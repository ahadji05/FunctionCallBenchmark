# FunctionCallBenchmark
A repository dedicated for benchmarking differenent types of function calls on multi-core processors.


### 12th Gen Intel(R) Core(TM) i7-12650H

- logical core 0:

Thread 0 timings: 	Virtual call: 6.873754 ns, 	Normal call:  6.185105 ns, 	Inline call:  6.161657 ns

- logical cores 0 and 1 (same physical core):

Thread 0 timings: 	Virtual call: 10.597840 ns, 	Normal call:  9.939409 ns, 	Inline call:  9.959898 ns

Thread 1 timings: 	Virtual call: 10.598196 ns, 	Normal call:  9.938211 ns, 	Inline call:  9.995126 ns

- logical cores 0 1 2 3 (4 threads on two physical cores):

Thread 0 timings: 	Virtual call: 12.371862 ns, 	Normal call:  11.515672 ns, 	Inline call:  11.556346 ns

Thread 1 timings: 	Virtual call: 12.367808 ns, 	Normal call:  11.511895 ns, 	Inline call:  11.563369 ns

Thread 2 timings: 	Virtual call: 12.336187 ns, 	Normal call:  11.521830 ns, 	Inline call:  11.576298 ns

Thread 3 timings: 	Virtual call: 12.330469 ns, 	Normal call:  11.527650 ns, 	Inline call:  11.541343 ns

- logical cores 0 2 4 6 (4 threads on 4 physical cores):

Thread 0 timings: 	Virtual call: 10.700796 ns, 	Normal call:  9.498859 ns, 	Inline call:  9.422081 ns

Thread 2 timings: 	Virtual call: 10.716405 ns, 	Normal call:  9.484790 ns, 	Inline call:  9.458674 ns

Thread 4 timings: 	Virtual call: 10.717378 ns, 	Normal call:  9.520695 ns, 	Inline call:  9.449220 ns

Thread 6 timings: 	Virtual call: 10.670265 ns, 	Normal call:  9.476507 ns, 	Inline call:  9.441251 ns
