# traceLibrary

## Library for tracing C++ program and outputting results to JSON file for viewing with chrome://tracing/

## Instructions for compiling
- inside the project directory type: make traceLibrary.o 

## Instructions for compiling and running the test program 
- inside the project directory type: make testTrace.o 
- then ./testTrace to run 
 
## Program being traced must include: 
- using namespace TRACELIBRARY; 

## Writes to file when: 
- ten thousand trace items have been accumulated
- the program crashes
- when trace is flushed 

