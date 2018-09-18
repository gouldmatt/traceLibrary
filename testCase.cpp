#include <iostream>
#include "traceLibrary.hpp"

 char file[] = "outputfile.JSON";
 char name[] = "main";
 char name2[] = "addLoop"; 
 char name3[] = "otherLoop"; 
 char cat[] = "PERF";

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
    for(int i=0; i<999; i++){
        count++;
    } 
}
int main(){

    trace_start(file);
    trace_event_start(name, cat); //for main 'B'

    trace_event_start(name2, cat); //for addLoop 'B'
    addLoop();
    trace_event_end(); //for addLoop 'E'

    trace_event_start(name3, cat); //for otherLoop 'B'
    otherLoop();
    trace_event_end(); //for otherLoop 'E'

    trace_event_end(); //for main 'E'
    trace_end(); 

    return 0;
}