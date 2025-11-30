# FunctionCallBenchmark
A repository dedicated for benchmarking differenent types of function calls on multi-core processors.


### 12th Gen Intel(R) Core(TM) i7-12650H

- logical core 0:

Virtual call: 0.682341 s, 	Normal call:  0.614067 s, 	Inline call:  0.615818 s

- logical cores 0 and 1 (same physical core):

Thread 0 timings: 	Virtual call: 1.058855 s, 	Normal call:  0.991853 s, 	Inline call:  0.992109 s

Thread 1 timings: 	Virtual call: 1.056873 s, 	Normal call:  0.992643 s, 	Inline call:  0.994350 s

- logical cores 0 2 4 and 6:

Thread 0 timings: 	Virtual call: 1.051569 s, 	Normal call:  0.947815 s, 	Inline call:  0.942366 s

Thread 2 timings: 	Virtual call: 1.049927 s, 	Normal call:  0.947405 s, 	Inline call:  0.947382 s

Thread 4 timings: 	Virtual call: 1.054137 s, 	Normal call:  0.950388 s, 	Inline call:  0.944192 s

Thread 6 timings: 	Virtual call: 1.049355 s, 	Normal call:  0.944687 s, 	Inline call:  0.944014 s

- logical cores 1 3 5 7: same performance as 0,2,4, and 6.

- logical cores 0 1 2 3 (4 threads on two physical cores):

Thread 0 timings: 	Virtual call: 1.232322 s, 	Normal call:  1.153152 s, 	Inline call:  1.155109 s

Thread 1 timings: 	Virtual call: 1.232081 s, 	Normal call:  1.152966 s, 	Inline call:  1.152470 s

Thread 2 timings: 	Virtual call: 1.232372 s, 	Normal call:  1.154161 s, 	Inline call:  1.155434 s

Thread 3 timings: 	Virtual call: 1.233220 s, 	Normal call:  1.153707 s, 	Inline call:  1.148838 s

