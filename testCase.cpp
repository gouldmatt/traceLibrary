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

    TRACELIBRARY::trace_start(file);
    TRACELIBRARY::trace_event_start(name, cat); //for main 'B'

    TRACELIBRARY::trace_event_start(name2, cat); //for addLoop 'B'
    addLoop();
    TRACELIBRARY::trace_event_end(); //for addLoop 'E'

    TRACELIBRARY::trace_event_start(name3, cat); //for otherLoop 'B'
    otherLoop();
    TRACELIBRARY::trace_event_end(); //for otherLoop 'E'

    TRACELIBRARY::trace_event_end(); //for main 'E'
    TRACELIBRARY::trace_end(); 

    return 0;
}