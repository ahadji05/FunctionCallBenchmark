# FunctionCallBenchmark
We are comparing three types of function calls on a multi-core processor: 1) virtual, 2) normal, 3) inline (no call).

### 10-core 12th Gen Intel(R) Core(TM) i7-12650H - g++ 11.4.0 - ubuntu 22.04.2

#### logical core 0:

 - Thread 0 timings: 	Virtual call: 6.48 ns,      Normal call:  5.66 ns,      Inline call:  5.64 ns

#### logical cores 0 and 1 (two threads - one physical core):

 - Thread 0 timings:   Virtual call: 9.86 ns,      Normal call:  9.03 ns,      Inline call:  9.04 ns

 - Thread 1 timings:   Virtual call: 9.85 ns,      Normal call:  9.03 ns,      Inline call:  9.04 ns

#### logical cores 0 and 2 (two threads - two physical cores):

 - Thread 0 timings: 	Virtual call: 6.51 ns,      Normal call:  5.67 ns,      Inline call:  5.67 ns

 - Thread 1 timings: 	Virtual call: 6.50 ns,      Normal call:  5.67 ns,      Inline call:  5.66 ns

*Virtual function has a 12-13% overhead compared to a normal function call when running on a single thread. Multithreading on the same physical core makes each call approximately 30% slower and at the same time hides some of the virtual call latency - the overhead drops to 8%. Multithreading on two physical cores shows the same overhead as without multithreading. In absolute time the v-table lookup cost is in the order of 1 ns.*

#### logical core 11 (performance-core) Vs logical core 12 (efficient-core):

 - Thread 11 timings: 	Virtual call: 6.40 ns, 	Normal call:  5.64 ns, 	Inline call:  5.63 ns

 - Thread 12 timings: 	Virtual call: 9.28 ns, 	Normal call:  8.42 ns, 	Inline call:  8.43 ns

*The processor has 6 performance cores and 4 efficient cores. Each performance core has two logical cores (so-called hardware-threads, or, hyperthreads), these correspond to logical cores 0-11. Each efficient core has 1 logical core, these correspond to logical cores 12-15. The comparison between logical core 11 and 12 is a comparison between a performance and an efficient core. Performance cores are approximately 30% faster than efficient cores (turns-out "efficient" cores are not so efficient). The v-table overhead is 0.8 ns in both cases (12.5% on performance cores - 10% on efficient cores).*
