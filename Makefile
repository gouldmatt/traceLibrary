#target: dependencies
#	action

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall

traceLibrary.o: traceLibrary.hpp bzip2.c traceLibrary.cpp
	g++ bzip2.c traceLibrary.cpp -o bzip2
	
clean:
	rm *.o traceLibrary
