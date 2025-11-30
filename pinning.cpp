#include "pinning.hpp"

#if defined(_WIN32)
    #include <windows.h>
#elif defined(__linux__)
    #include <pthread.h>
    #include <sched.h>
#else
    #error "Thread pinning not supported on this platform."
#endif

bool pin_thread_to_core(unsigned core) {
#if defined(_WIN32)
    DWORD_PTR mask = (1ULL << core);
    HANDLE thread = GetCurrentThread();
    return SetThreadAffinityMask(thread, mask) != 0;

#elif defined(__linux__)
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(core, &set);
    return pthread_setaffinity_np(pthread_self(), sizeof(set), &set) == 0;

#endif
}
