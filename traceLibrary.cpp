#include <iostream>
#include <fstream> 
#include <time.h>
#include "traceLibrary.hpp"

using namespace std; 

void traceLibrary::trace_start(char* file){ 
    uncompleteIndex = 0; 
    completeIndex = 0; 
    fileName = file; 
}

void traceLibrary::trace_end(){
    flush_to_file(); 
}

void traceLibrary::trace_event_start(char* name, char* cat){

    eventsArr[uncompleteIndex].namePtr = name;
    eventsArr[uncompleteIndex].category = cat; 

    //start time measurement
    clock_t t;
    t = clock()/CLOCKS_PER_SEC;
    
    eventsArr[uncompleteIndex].startTime = t;
    uncompleteIndex++;
}

void traceLibrary::trace_event_end(){

    //end time measurement
    clock_t t;
    t = clock()/CLOCKS_PER_SEC;
    //doesn't always end in the same order as it started... use stack??
    eventsArr[completeIndex].endTime = t;
    
    completeIndex++; 

    cout << t << endl;
}

void traceLibrary::flush_to_file(){
    //might need to write to a buffer as the event occure to properly nest
    ofstream f;
    f.open(fileName);
    
    f << "[" << endl;
    //JSON format (could use json handler here instead)
    for(int i=0; i<completeIndex; i++){
        f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\": \"" << eventsArr[i].category << "\", \"ph\": \"B\", \"pid\": 1, \"ts\": \"" << eventsArr[i].startTime << "\"}";
        f << "," << endl;
        f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\":  \"" << eventsArr[i].category << "\", \"ph\": \"E\", \"pid\": 1, \"ts\": \"" << eventsArr[i].endTime << "\"}";

        if(i != completeIndex-1) {f << ",";}
        f << endl;
    }

    f << "]";
    f << endl;
    f.close();
}