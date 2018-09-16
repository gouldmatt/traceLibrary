#include <iostream>
#include <chrono> 
#include <time.h>
#include "traceLibrary.hpp"

using namespace std; 

void traceLibrary::trace_start(char* file){ 
    currentEvent = 0; 
    fileName = file; 
}

void traceLibrary::trace_end(){
    flush_to_file(); 
}

void traceLibrary::trace_event_start(char* name, char* cat){
     currentEvent++; 

    //start time measurement
    //clock_t t;
    //t = clock();
    chrono::time_point<std::chrono::steady_clock> ts = std::chrono::steady_clock::now();
    eventsArr[currentEvent].startTime = chrono::duration_cast<std::chrono::nanoseconds>(ts.time_since_epoch()).count();

    eventsArr[currentEvent].namePtr = name;
    eventsArr[currentEvent].category = cat; 
}

void traceLibrary::trace_event_end(){

    //end time measurement
    //clock_t t;
    //t = clock();
    chrono::time_point<std::chrono::steady_clock> ts = std::chrono::steady_clock::now();
    eventsArr[currentEvent].endTime = chrono::duration_cast<std::chrono::nanoseconds>(ts.time_since_epoch()).count(); 
}

void traceLibrary::flush_to_file(){

    //flush to file, print for now -- > need to add start/end for json 
    cout << "[" << endl;

    for(int i=1; i<=currentEvent; i++){
        cout << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\": \"" << eventsArr[i].category << "\", \"ph\": \"B\", \"pid\": 1, \"ts\": \"" << eventsArr[i].startTime << "\"}";
        cout << "," << endl;
        cout << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\":  \"" << eventsArr[i].category << "\", \"ph\": \"E\", \"pid\": 1, \"ts\": \"" << eventsArr[i].endTime << "\"}";

        if(i != currentEvent) {cout << ",";}
        cout << endl;
    }

    cout << "]";
    cout << endl; 
}