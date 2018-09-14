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
     currentEvent++; 

    //start time measurement
    chrono::time_point<std::chrono::steady_clock> ts = std::chrono::steady_clock::now();
    eventsArr[currentEvent].startTime = chrono::duration_cast<std::chrono::nanoseconds>(ts.time_since_epoch()).count();

    eventsArr[currentEvent].namePtr = name; 
}

void traceLibrary::trace_event_end(){

    //end time measurement
    chrono::time_point<std::chrono::steady_clock> ts = std::chrono::steady_clock::now();
    eventsArr[currentEvent].endTime = chrono::duration_cast<std::chrono::nanoseconds>(ts.time_since_epoch()).count(); 
}

void traceLibrary::flush_to_file(){

    //flush to file, print for now -- > need to add start/end for json 
    cout << "[" << endl;

    for(int i =1; i<=currentEvent; i++){
        cout << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\": \"PERF\", \"ph\": \"B\", \"pid\": 1, \"ts\": \"" << eventsArr[i].startTime << "\"}";
        cout << "," << endl;
        cout << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\": \"PERF\", \"ph\": \"E\", \"pid\": 1, \"ts\": \"" << eventsArr[i].endTime << "\"}";

        if(i != currentEvent) {cout << ",";}

        cout << endl;
    }

    cout << "]";
    cout << endl; 
}

int main(){
    traceLibrary trace1;

    char name[] = "start";
    char name2[] = "second"; 
    char name3[] = "third"; 

    //program not being traced

    trace1.trace_start(name);

    trace1.trace_event_start(name);

    trace1.trace_event_end();

    trace1.trace_event_start(name2);

    int yeah = (100000 *80) + 90000;

    trace1.trace_event_end();


    trace1.trace_event_start(name3);

    trace1.trace_event_end();


    trace1.trace_end(); 

    //program not being traced 

    return 0;
}