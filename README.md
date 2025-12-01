# FunctionCallBenchmark
A repository dedicated for benchmarking differenent types of function calls on multi-core processors.


### 12th Gen Intel(R) Core(TM) i7-12650H - g++ 11.4.0

#### logical core 0:

 - Thread 0 timings: 	Virtual call: 6.48 ns,      Normal call:  5.66 ns,      Inline call:  5.64 ns

#### logical cores 0 and 1 (two threads - one physical core):

 - Thread 0 timings:   Virtual call: 9.86 ns,      Normal call:  9.03 ns,      Inline call:  9.04 ns

 - Thread 1 timings:   Virtual call: 9.85 ns,      Normal call:  9.03 ns,      Inline call:  9.04 ns

#### logical cores 0 and 2 (two threads - two physical cores):

 - Thread 0 timings: 	Virtual call: 6.51 ns,      Normal call:  5.67 ns,      Inline call:  5.67 ns

 - Thread 1 timings: 	Virtual call: 6.50 ns,      Normal call:  5.67 ns,      Inline call:  5.66 ns

*Virtual function has a 12-13% overhead compared to a normal function call when running on a single thread. Multithreading on the same physical core makes each call approximately 30% slower and at the same time hides some of the virtual call latency - the overhead drops to 8%. Multithreading on two physical cores shows the same overhead as without multithreading.*
