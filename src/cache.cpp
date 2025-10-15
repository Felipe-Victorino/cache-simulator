#include "cache.hpp"

Cache::Cache(){};
Cache::~Cache(){};

Cache::Cache(std::string name, int latency, int linesize, int set_size)
{
    this->p_name = name;
    this->p_latency = latency;
    this->p_linesize = linesize;
    this->associative_set_size = set_size;
};

MemoryNode::MemoryNode(){};
MemoryNode::~MemoryNode(){};