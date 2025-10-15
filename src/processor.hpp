#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdlib>
#include "cache.hpp"


class Processor
{
private:
    enum MemoryAccess{SEQUENTIAL, RANDOM};
    enum MemoryAccess access;

    

public:
    Processor();
    
    ~Processor();
};





#endif