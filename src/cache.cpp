#include "cache.hpp"

Cache::Cache(std::string name, int latency, int associativity, int linesize, int set_size)
{
    this->p_name = name;
    this->p_latency = latency;
    this->p_linesize = linesize;
    this->p_associativity = associativity;
    this->associative_set_size = set_size;
};