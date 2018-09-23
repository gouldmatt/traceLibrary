#include <iostream>
#include <fstream> 
#include <time.h>
#include "traceLibrary.hpp"

struct traceEvent{
    const char *namePtr;
    char phaseNumber; // 0 duration, 1 counter event 
    int startTime;
    int endTime;
    const char *threadPtr;
    const char *arguments;
    const char *category;
    const char *counterKey;
};
const char *fileName;
unsigned short int stack[10000];
traceEvent eventsArr[10000];
int eventIndex;
int stackCounter;


void TRACELIBRARY::trace_start(const char* file){ 
    eventIndex = 0; 
    stackCounter = 0; 
    fileName = file; 
}

void TRACELIBRARY::trace_end(){
    TRACELIBRARY::trace_flush(); 
}

void TRACELIBRARY::trace_event_start(const char* name, const char* cat, const char* arg){

    eventsArr[eventIndex].namePtr = name;
    eventsArr[eventIndex].category = cat; 
    eventsArr[eventIndex].phaseNumber = 0; 

    //push index to stack 
    stack[stackCounter] = eventIndex;
    stackCounter++; 

    //start time measurement
    clock_t t;
    t = clock();
    
    eventsArr[eventIndex].startTime = t;
    eventIndex++;
}

void TRACELIBRARY::trace_event_end(const char* arg){

    eventsArr[eventIndex].phaseNumber = 0; 

    //end time measurement
    clock_t t;
    t = clock();

    //pop stack to find index of event to end
    eventsArr[stack[stackCounter-1]].endTime = t;

    stack[stackCounter] = 0;
    stackCounter--; 
}

void TRACELIBRARY::trace_flush(){
    std::ofstream f;
    f.open(fileName);

    f << "[" << std::endl;
    for(int i=0; i<eventIndex; i++){

        // duration event 
        if(eventsArr[i].phaseNumber == 0){
            f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\": \"" << eventsArr[i].category << "\", \"ph\": \"B\", \"pid\": 1, \"ts\": \"" << eventsArr[i].startTime << "\"}";
            f << "," << std::endl;
            f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\":  \"" << eventsArr[i].category << "\", \"ph\": \"E\", \"pid\": 1, \"ts\": \"" << eventsArr[i].endTime << "\"}";
        }

        // counter event 
        if(eventsArr[i].phaseNumber == 1){    
            f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"ph\": \"C\", \"pid\": 1, \"ts\": \"" << eventsArr[i].startTime << "\", \"args\": {\"" << eventsArr[i].counterKey << "\": " << eventsArr[i].arguments << "}}";
        }

        if(i != eventIndex-1) {f << ",";}
        f << std::endl;
    }

    f << "]";
    f << std::endl;
    f.close();
}

void TRACELIBRARY::trace_instant_global(const char* name){

}

void TRACELIBRARY::trace_object_new(const char* name, void* obj_pointer){

}

void TRACELIBRARY::trace_object_gone(const char* name, void* obj_pointer){

}

void TRACELIBRARY::trace_counter(const char* name, const char* key, const char* value){
    eventsArr[eventIndex].namePtr = name;
    eventsArr[eventIndex].phaseNumber = 1; 
    eventsArr[eventIndex].arguments = value; 
    eventsArr[eventIndex].counterKey = key; 

    clock_t t;
    t = clock();
    
    eventsArr[eventIndex].startTime = t;
    eventIndex++;
}

void TRACELIBRARY::signal_handler(int signal_num){ 
    std::cout << "The interrupt signal is (" << signal_num << "). \n"; 
    TRACELIBRARY::trace_end();
    // terminate program   
    exit(signal_num);
}  