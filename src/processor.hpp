#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdlib>
#include <list>
#include "cache.hpp"

enum MemoryAccess{SEQUENTIAL, RANDOM};

class Processor
{
    private:
    
    enum MemoryAccess p_access;
 

    public:
    
    Processor();
    ~Processor();
    
    
    void read();
    void write();

    int genRandomAddress()
    {
        return std::rand() % (sizeof(u_int32_t) * 8);
    };

    void iterateThroughCache();
    void search();
    void randomAccess();
    void sequentialAccess();

};





#endif