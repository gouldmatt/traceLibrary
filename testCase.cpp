#include <iostream>
#include "traceLibrary.cpp"

using namespace std;

int main(){
    
    traceLibrary trace1;

    char name[] = "start";
    char name2[] = "second"; 
    char name3[] = "third"; 
    char cat[] = "PERF";


    trace1.trace_start(name);

    trace1.trace_event_start(name, cat);
    trace1.trace_event_end();

    trace1.trace_event_start(name2, cat);
    trace1.trace_event_end();

    //stall in program to test with time
    int count = 0;
    for(int i=0; i<10000000; i++){
        count++;
    }
    /////////////////////////////////////

    trace1.trace_event_start(name3, cat);
    trace1.trace_event_end();

    trace1.trace_end(); 

    return 0;
}