#ifndef PROCESSOR_H
#define PROCESSOR_H

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
    Instruction sendInstruction(int ratio);
    uint32_t genRandomAddress();

};

#endif