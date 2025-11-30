#include "fooVirtual.hpp"
#include "pinning.hpp"
#include "foo.hpp"

#include <iostream>
#include <cstddef>
#include <memory>
#include <chrono>
#include <future>
#include <vector>
#include <queue>

size_t nCalls = 1E8;

template<typename RNG>
inline int foo_inline( RNG & gen, std::uniform_int_distribution<int> &dist ) {
    return dist(gen);
}

void warmup(){
    size_t sum = 0;
    for ( size_t i = 0 ; i < 1E10; ++i )
        sum += i;
    // print sum to prevent compiler from eliding the whole warmup() call.
    std::cout << sum << std::endl;
}

// global conditional variable to help printing a meaningful message when std::stoi() fails to read user-input.
static bool parsed;

int parseCoreId( char const * const argv  ) {
    parsed = false;
    int core = std::stoi( argv );
    parsed = true;
    return core;
}

int main( int argc, char *argv[] ) {

    try {

        if ( argc == 1 ) {
            std::cout << "Usage (1 thread in core 0):         $ " << argv[ 0 ] << " 0" << std::endl;
            std::cout << "Usage (1 thread in core N):         $ " << argv[ 0 ] << " N" << std::endl;
            std::cout << "Usage (4 threads in cores 0 2 4 6): $ " << argv[ 0 ] << " 0 2 4 6" << std::endl;
            std::cout << "etc..." << std::endl;
            throw std::runtime_error("No CL arguments parsed for the thread pinning. See usage examples!");
        }

        // parse thread pinning from the CL.
        std::vector<int> threadIds;
        threadIds.reserve( argc - 1 );
        for ( int i = 1; i < argc; ++i )
            threadIds.emplace_back( parseCoreId( argv[i] ) );

        // print pinning.
        std::cout << "\nRunning weak-scaling function-call benchmark using " << threadIds.size() << " threads and " << nCalls << " calls per thread...\n" << std::endl;
        std::cout << "Thread pinning:" << std::endl;
        for ( int i = 0; i < threadIds.size(); ++i )
            std::cout << "\tthread " << i << " -> CPU-core " << threadIds[ i ] << std::endl;
        std::cout << std::endl;
        std::queue<std::future<std::string>> threads;

        // launch threads asynchronously.
        for ( auto const& threadId : threadIds ) {

            // launch benchmark asynchronously and push future to a vector.
            std::future<std::string> future = std::async( std::launch::async, [=]() {

                // pin thread to a specific CPU core to avoid context-switching.
                pin_thread_to_core( threadId );

                std::cout << "Thread " << threadId << " warm-up..." << std::endl;
                warmup();

                std::cout << "Virtual call benchmark..." << std::endl;
                std::unique_ptr<FooVirtualBase> fv = std::make_unique<FooVirtual>( FooVirtual() );
                auto startV = std::chrono::high_resolution_clock::now();
                int sumV = 0;
                for (int i = 0; i < nCalls; ++i) sumV += fv->foo();
                auto endV = std::chrono::high_resolution_clock::now();

                std::cout << "Normal call benchmark..." << std::endl;
                Foo foo;
                auto startN = std::chrono::high_resolution_clock::now();
                int sumN = 0;
                for (int i = 0; i < nCalls; ++i) sumN += foo.foo();
                auto endN = std::chrono::high_resolution_clock::now();

                std::cout << "Inline call benchmark..." << std::endl;
                std::mt19937 gen(std::random_device{}());
                std::uniform_int_distribution<int> dist(0, 1000000);
                auto startI = std::chrono::high_resolution_clock::now();
                int sumI = 0;
                for (int i = 0; i < nCalls; ++i) sumI += foo_inline(gen, dist);
                auto endI = std::chrono::high_resolution_clock::now();

                std::string msg = "Thread " + std::to_string( threadId ) + " timings: " + \
                    "\tVirtual call: " + std::to_string( std::chrono::duration<double>(endV - startV).count() ) + " s, " + \
                    "\tNormal call:  " + std::to_string( std::chrono::duration<double>(endN - startN).count() ) + " s, " + \
                    "\tInline call:  " + std::to_string( std::chrono::duration<double>(endI - startI).count() ) + " s\n";

                return msg;
            });

            // append thread at the end of a queue.
            threads.emplace( std::move( future ) );
        }

        // print thread timings.
        while ( !threads.empty() ){
            std::cout << threads.front().get() << std::endl;
            threads.pop();
        }

    } catch ( std::exception const& e ) {
        if ( !parsed )
            std::cout << "Failed to parse CL argument!!\n\tRun executable without arguments to see usage example." << std::endl;
        else
            std::cout << e.what() << std::endl;
    }

    return 0;
}
