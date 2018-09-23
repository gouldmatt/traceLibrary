#target: dependencies
#	action

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall

traceLibrary.o: traceLibrary.hpp testCase.cpp traceLibrary.cpp
	g++ testCase.cpp traceLibrary.cpp -o traceLibrary

	
clean:
	rm *.o traceLibrary
