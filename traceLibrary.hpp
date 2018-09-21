// header file  for trace library 
#ifndef TRACELIBRARY_HPP
#define TRACELIBRARY_HPP

namespace TRACELIBRARY{

    void trace_start(char* file);

    void trace_end(); 

    void trace_event_start(char* name, char* cat);

    void trace_event_end();
    
    void flush_to_file(); 
}
#endif 
