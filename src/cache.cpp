#include <string>
#include <my-lib/bit.h>
#include "cache.hpp"

MemoryLevel::MemoryLevel(){}

MemoryLevel::MemoryLevel(std::string name, int latency, BitSet bits)
{
    this->p_name = name;
    this->p_latency = latency;
}

std::string MemoryLevel::getName()
{
    return this->p_name;
}

void MemoryLevel::setName(std::string name)
{
    this->p_name = name;
}

int MemoryLevel::getLatency(){
    return this->p_latency;
}

void MemoryLevel::setLatency(int latency){
    this->p_latency = latency;
}

BitSet MemoryLevel::getBitSet(){
    return this->p_bits;
}
