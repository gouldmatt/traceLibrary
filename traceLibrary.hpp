// header file  for trace library 
#ifndef TRACELIBRARY_HPP
#define TRACELIBRARY_HPP

struct traceEvent{
    int startTime;
    int endTime;
    char* arguments;
    char* category; 
    char* namePtr;
};

class traceLibrary{
public: 
    void trace_start(char* file);

    void trace_end(); 

    void trace_event_start(char* name, char* cat);

    void trace_event_end();

private: 
    void flush_to_file(); 

    char* fileName;
    traceEvent eventsArr[10000]; 
    int uncompleteIndex;
    int completeIndex; 
};

#endif 
