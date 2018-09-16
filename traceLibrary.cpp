#include <iostream>
#include <fstream> 
#include <time.h>
#include "traceLibrary.hpp"

using namespace std; 

void traceLibrary::trace_start(char* file){ 
    eventIndex = 0; 
    stackCounter = 0; 
    fileName = file; 
}

void traceLibrary::trace_end(){
    flush_to_file(); 
}

void traceLibrary::trace_event_start(char* name, char* cat){

    eventsArr[eventIndex].namePtr = name;
    eventsArr[eventIndex].category = cat; 

    //push index to stack 
    stack[stackCounter] = eventIndex;
    stackCounter++; 

    //start time measurement
    clock_t t;
    t = clock();
    
    eventsArr[eventIndex].startTime = t;
    eventIndex++;
}

void traceLibrary::trace_event_end(){

    //end time measurement
    clock_t t;
    t = clock();

    //pop stack to find index of event to end
    eventsArr[stack[stackCounter-1]].endTime = t;

    stack[stackCounter] = 0;
    stackCounter--; 
}

void traceLibrary::flush_to_file(){
    //might need to write to a buffer as the event occure to properly nest
    ofstream f;
    f.open(fileName);

    f << "[" << endl;
    //JSON format (could use json handler here instead)
    for(int i=0; i<eventIndex; i++){
        f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\": \"" << eventsArr[i].category << "\", \"ph\": \"B\", \"pid\": 1, \"ts\": \"" << eventsArr[i].startTime << "\"}";
        f << "," << endl;
        f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\":  \"" << eventsArr[i].category << "\", \"ph\": \"E\", \"pid\": 1, \"ts\": \"" << eventsArr[i].endTime << "\"}";

        if(i != eventIndex-1) {f << ",";}
        f << endl;
    }

    f << "]";
    f << endl;
    f.close();
}