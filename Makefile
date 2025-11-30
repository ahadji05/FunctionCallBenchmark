
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
