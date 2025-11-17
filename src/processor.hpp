#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdlib>

#include "cache.hpp"

enum InstructionType
{
    WRITE, 
    READ
};

struct GroupIns {
    InstructionType type;
    uint32_t address;
    uint32_t tag;

};

class Processor
{
    public:
    
    Processor();
    ~Processor();
    
    GroupIns sendInstruction(uint32_t write_ratio);
    uint32_t genRandomAddress();

};

#endif