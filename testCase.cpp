#include <iostream>
#include <csignal>
#include "traceLibrary.cpp"

using namespace std;
using namespace TRACELIBRARY;

void addLoop(int count);

void otherLoop(); 

int main(){
    signal(SIGSEGV, signal_handler); // register signal SIGSEGV and signal handler 

    int count = 9; 

    trace_start("outputfile.JSON");
    trace_event_start("main", "PERF", "none"); //for main 'B'

    trace_event_start("addLoop", "PERF", "none"); //for addLoop 'B'
    addLoop(count);
    trace_event_end("none"); //for addLoop 'E'

    trace_counter("counter","ctr","10");
    otherLoop();
    trace_counter("counter","ctr","20");
    otherLoop();
    trace_counter("counter","ctr","60");
    otherLoop();
    trace_counter("counter","ctr","90");

    otherLoop();
    trace_counter("counter","ctr","30");

    trace_event_start("otherLoop", "PERF", "none"); //for otherLoop 'B'
    otherLoop();
    trace_event_end("none"); //for otherLoop 'E'

    trace_event_end("none"); //for main 'E'
    trace_end(); 

    return 0;
}

void addLoop(int count){
    //test recursive call
    
    if(count != 0){
        trace_event_start("addLoop", "PERF", "none"); //for addLoop 'B'  
        count--; 
        otherLoop(); 
        addLoop(count); 

    }  
    trace_event_end("none"); //for addLoop 'E'
    return; 
}
void otherLoop(){
    //stall in program to test
    int count = 0;
    for(int i=0; i<99998999; i++){
        count++;
    } 
}