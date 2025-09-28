#include <string>
#include <my-lib/bit.h>
#include "cache.hpp"


MemoryLevel::MemoryLevel(std::string name, int latency)
{
    this->p_name = name;
    this->p_latency = latency;
}

