#include <iostream>
#include "traceLibrary.hpp"

 char file[] = "outputfile.JSON";
 char name[] = "main";
 char name2[] = "addLoop"; 
 char name3[] = "otherLoop"; 
 char cat[] = "PERF";
 char none[] = "none"; 

using namespace std;
using namespace TRACELIBRARY;

void addLoop(int count);

void otherLoop(); 

int main(){

    int count = 9; 

    trace_start(file);
    trace_event_start(name, cat, none); //for main 'B'

    trace_event_start(name2, cat, none); //for addLoop 'B'
    addLoop(count);
    trace_event_end(none); //for addLoop 'E'

    trace_event_start(name3, cat, none); //for otherLoop 'B'
    otherLoop();
    trace_event_end(none); //for otherLoop 'E'

    trace_event_end(none); //for main 'E'
    trace_end(); 

    return 0;
}

void addLoop(int count){
    //test recursive call  
    if(count != 0){
        count--; 
        otherLoop(); 
        addLoop(count); 

    }  
    return; 
}
void otherLoop(){
    //stall in program to test
    int count = 0;
    for(int i=0; i<99998999; i++){
        count++;
    } 
}