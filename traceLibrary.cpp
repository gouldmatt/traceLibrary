// header file  for trace library 
//#ifndef TRACELIBRARY_HPP
//#define TRACELIBRARY_HPP

#include <iostream>
#include <fstream> 
#include <time.h>
#include <csignal>

namespace TRACELIBRARY
{
    struct traceEvent{
        int startTime;
        int endTime;
        char* arguments;
        char* category; 
        char* namePtr;
    };

    char* fileName;
    unsigned short int stack[10000]; 
    traceEvent eventsArr[10000]; 
    int eventIndex; 
    int stackCounter;

    void trace_start(char* file);

    void trace_end(); 

    void trace_event_start(char* name, char* cat);

    void trace_event_end();
  
    void signal_handler(int signal_num); 

    void flush_to_file(); 

    void trace_start(char* file){ 
        eventIndex = 0; 
        stackCounter = 0; 
        fileName = file; 
    }

    void trace_end(){
        flush_to_file(); 
    }

    void trace_event_start(char* name, char* cat){

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

    void trace_event_end(){

        //end time measurement
        clock_t t;
        t = clock();

        //pop stack to find index of event to end
        eventsArr[stack[stackCounter-1]].endTime = t;

        stack[stackCounter] = 0;
        stackCounter--; 
    }

    void signal_handler(int signal_num){ 
        std::cout << "The interrupt signal is (" << signal_num << "). \n"; 
     
        trace_end();
        // terminate program   
        exit(signal_num);   
    } 
    void flush_to_file(){
        //might need to write to a buffer as the event occure to properly nest
        std::ofstream f;
        f.open(fileName);

        f << "[" << std::endl;
        //JSON format (could use json handler here instead)
        for(int i=0; i<eventIndex; i++){
            f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\": \"" << eventsArr[i].category << "\", \"ph\": \"B\", \"pid\": 1, \"ts\": \"" << eventsArr[i].startTime << "\"}";
            f << "," << std::endl;
            f << "{\"name\": \"" << eventsArr[i].namePtr << "\", \"cat\":  \"" << eventsArr[i].category << "\", \"ph\": \"E\", \"pid\": 1, \"ts\": \"" << eventsArr[i].endTime << "\"}";

            if(i != eventIndex-1) {f << ",";}
            f << std::endl;
        }

        f << "]";
        f << std::endl;
        f.close();
    }
}

//#endif 
