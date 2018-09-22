// header file  for trace library 
#ifndef TRACELIBRARY_HPP
#define TRACELIBRARY_HPP

namespace TRACELIBRARY{

    void trace_start(const char* file);

    void trace_end(); 

    void trace_event_start(const char* name, const char* cat, const char* arg);

    void trace_event_end(const char* arg);
    
    void trace_flush(); 

    void trace_instant_global(const char* name);

    void trace_object_new(const char* name, void* obj_pointer);

    void trace_object_gone(const char* name, void* obj_pointer);

    void trace_counter(const char* name, const char* key, const char* value);
}
#endif 
