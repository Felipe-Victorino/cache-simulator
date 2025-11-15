#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <list>

#include <cstdlib>

#include "cache.hpp"

enum Instruction
{
    WRITE, 
    READ
};

class Processor
{
    public:
    
    Processor();
    ~Processor();
    
    Instruction read();
    Instruction write();
    uint32_t genRandomAddress();

};

#endif