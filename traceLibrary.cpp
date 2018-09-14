#include <iostream>
#include <chrono> 
#include "traceLibrary.hpp"

using namespace std; 

void traceLibrary::trace_start(char* filename){ 
    currentEvent = 0; 
    fileName = filename; 
}

void traceLibrary::trace_end(){
    flush_to_file(); 
}

void traceLibrary::trace_event_start(char* name){

    //start time measurement
    //eventsArr[currentEvent].startTime = chrono::system_clock::now();
    eventsArr[currentEvent].startTime = 1; 

    eventsArr[currentEvent].namePtr = name; 

    currentEvent++;
}

void traceLibrary::trace_event_end(){
    //end time measurement
    //auto end = chrono::steady_clock::now();
    eventsArr[currentEvent].endTime = 10; 
}

void traceLibrary::flush_to_file(){

    //flush to file, print for now -- > need to add start/end for json 
    cout << "[" << endl;

    //for(int i =0; i<=currentEvent; i++){


    //}
    
    cout << "{\"name\": \"" << eventsArr[0].namePtr << "\", \"cat\": \"PERF\", \"ph\": \"B\", \"pid\": 1, \"ts\": 1}";
    cout << "," << endl;
    cout << "{\"name\": \"" << eventsArr[0].namePtr << "\", \"cat\": \"PERF\", \"ph\": \"E\", \"pid\": 1, \"ts\": 20}";


    cout << endl << "]";
    cout << endl; 
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