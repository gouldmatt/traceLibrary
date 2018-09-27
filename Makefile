#target: dependencies
#	action

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall

testTrace.o: traceLibrary.hpp traceLibrary.cpp
	g++ testCase.cpp traceLibrary.cpp -o testTrace

traceLibrary.o: traceLibrary.hpp traceLibrary.cpp
	g++ traceLibrary.cpp -c 
	
clean:
	rm *.o traceLibrary
