
CXX=g++
CXXFLAGS=-O3

bench.exe: deps
	$(CXX) $(CXXFLAGS) *.o -o $@

deps: main.o foo.o fooVirtual.o pinning.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $? -o $@

foo.o: foo.cpp
	$(CXX) $(CXXFLAGS) -c $? -o $@

fooVirtual.o: fooVirtual.cpp
	$(CXX) $(CXXFLAGS) -c $? -o $@

pinning.o: pinning.cpp
	$(CXX) $(CXXFLAGS) -c $? -o $@

clean:
	rm *.o bench.exe

# Below several options are listed for running the benchmark on one or more logical cores.
run_core_0: bench.exe
	./bench.exe 0

run_cores_0and1: bench.exe
	./bench.exe 0 1

run_four_cores_even: bench.exe
	./bench.exe 0 2 4 6

run_four_cores_odd: bench.exe
	./bench.exe 1 3 5 7

run_eight_cores_even: bench.exe
	./bench.exe 0 2 4 6 8 10 12 14

run_eight_cores_odd: bench.exe
	./bench.exe 1 3 5 7 9 11 13 15
