#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdlib>
#include <list>
#include "cache.hpp"


class Processor
{
    private:
    enum MemoryAccess{SEQUENTIAL, RANDOM};
    enum MemoryAccess access;
    std::list<Cache> *cache;
    public:
    Processor(std::list<Cache> *cache);
    
    ~Processor();
};





#endif