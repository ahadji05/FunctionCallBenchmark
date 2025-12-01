# FunctionCallBenchmark
A repository dedicated for benchmarking differenent types of function calls on multi-core processors.


### 12th Gen Intel(R) Core(TM) i7-12650H - g++ 11.4.0

#### logical core 0:

 - Thread 0 timings: 	Virtual call: 6.28 ns,      Normal call:  5.66 ns,      Inline call:  5.64 ns

#### logical cores 0 and 1 (two threads - one physical core):

 - Thread 0 timings:   Virtual call: 9.86 ns,      Normal call:  9.034 ns,      Inline call:  9.047 ns

 - Thread 1 timings:   Virtual call: 9.85 ns,      Normal call:  9.033 ns,      Inline call:  9.043 ns

#### logical cores 0 and 2 (two threads - two physical cores):

 - Thread 0 timings: 	Virtual call: 6.61 ns,      Normal call:  5.67 ns,      Inline call:  5.67 ns

 - Thread 1 timings: 	Virtual call: 6.60 ns,      Normal call:  5.66 ns,      Inline call:  5.66 ns
