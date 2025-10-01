#include <string>
#include <my-lib/bit.h>
#include "cache.hpp"

MemoryLevel::MemoryLevel(){}

MemoryLevel::MemoryLevel(std::string name, int latency, BitSet bits)
{
    this->p_name = name;
    this->p_latency = latency;
}

MemoryLevel::~MemoryLevel()


int MemoryLevel::getLatency(){
    return this->p_latency;
}

void MemoryLevel::setLatency(int latency){
    this->p_latency = latency;
}

BitSet MemoryLevel::getBitSet(){
    return this->p_bits;
}
