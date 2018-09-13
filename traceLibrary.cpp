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
    //start time measurement
    //eventsArr[currentEvent].startTime = chrono::system_clock::now();

}

void traceLibrary::trace_event_end(){
    //end time measurement
    auto end = chrono::steady_clock::now();

}

int main(){
    return 0;
}