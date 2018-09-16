#include <iostream>
#include "traceLibrary.hpp"

using namespace std;
void addLoop(){
    //stall in program to test
    int count = 0;
    for(int i=0; i<1000; i++){
        count++;
    } 
}
void otherLoop(){
    //stall in program to test
    int count = 0;
    for(int i=0; i<9999; i++){
        count++;
    } 
}
int main(){
    
    traceLibrary trace1;
    char file[] = "outputfile.JSON";
    char name[] = "main";
    char name2[] = "addLoop"; 
    char name3[] = "otherLoop"; 
    char cat[] = "PERF";

    trace1.trace_start(file);
    trace1.trace_event_start(name, cat); //for main 'B'

    trace1.trace_event_start(name2, cat); //for addLoop 'B'
    addLoop();
    trace1.trace_event_end(); //for addLoop 'E'

    trace1.trace_event_start(name3, cat); //for otherLoop 'B'
    otherLoop();
    trace1.trace_event_end(); //for otherLoop 'E'

    trace1.trace_event_end(); //for main 'E'
    trace1.trace_end(); 

    return 0;
}