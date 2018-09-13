#include <iostream>
#include <chrono> 
#include "traceLibrary.hpp"

using namespace std; 

void traceLibrary::trace_start(char* filename){ 
    currentEvent = 0; 
}

void traceLibrary::trace_end(){

}

void traceLibrary::trace_event_start(char* name){
    currentEvent++;

    //start time measurement
    //eventsArr[currentEvent].startTime = chrono::system_clock::now();
    eventsArr[currentEvent].startTime = 1; 

    eventsArr[currentEvent].namePtr = name; 
}

void traceLibrary::trace_event_end(){
    //end time measurement
    //auto end = chrono::steady_clock::now();
    eventsArr[currentEvent].endTime = 10; 

    //flush to file, print for now 
    cout << "[ ";
    cout << "\{​\"" << eventsArr[1].namePtr << "\"​:​\"Asub\"​,\"cat\"​:​\"PERF\"​,\"ph\"​:\"B\"​,​\"pid\"​:​22630​,\"tid\"​:​22630​,​\"ts\"​:​833​}";
    cout << ",";
    cout << endl; 
    cout << "\{​\"name\"​:​\"Asub\"​,\"cat\"​:​\"PERF\"​,\"ph\"​:\"E\"​,​\"pid\"​:​22630​,\"tid\"​:​22630​,​\"ts\"​:​833​}";
    cout << endl << "]";
}

int main(){
    traceLibrary trace1;

    char name[] = "start";

    //program not being traced

    trace1.trace_start(name);

    trace1.trace_event_start(name);

    trace1.trace_event_end();

    trace1.trace_end(); 

    //program not being traced 

    return 0;
}