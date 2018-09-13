// header file  for trace library 
#ifndef TRACELIBRARY_HPP
#define TRACELIBRARY_HPP

struct traceEvent{
    double startTime;
    double endTime;  
    char* namePtr;
};

class traceLibrary{
public: 
    void trace_start(char* filename);

    void trace_end(); 

    void trace_event_start(char* name);

    void trace_event_end();

private: 
    int currentEvent;
    traceEvent eventsArr[10000]; 
};

#endif 
