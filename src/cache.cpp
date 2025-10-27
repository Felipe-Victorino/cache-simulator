#include "cache.hpp"

Cache::Cache(std::string name, int latency, int associativity, int linesize, int set_size)
{
    this->p_name = name;
    this->p_latency = latency;
    this->p_linesize = linesize;
    this->p_associativity = associativity;
    this->p_total_sets = set_size;
};

int Cache::calculateCacheSize(){
    const int size = this->p_linesize * this->p_total_sets * this->p_associativity;
    return size;
}