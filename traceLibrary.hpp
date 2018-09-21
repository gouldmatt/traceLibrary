// header file  for trace library 
#ifndef TRACELIBRARY_HPP
#define TRACELIBRARY_HPP

namespace TRACELIBRARY{

    void trace_start(char* file);

    void trace_end(); 

    void trace_event_start(char* name, char* cat, char* arg);

    void trace_event_end(char* arg);
    
    void trace_flush(); 

    void trace_instant_global(char* name);

    void trace_object_new(char* name, void* obj_pointer);

    void trace_object_gone(char* name, void* obj_pointer);

    void trace_counter(char* name, char* key, char* value);
}
#endif 
