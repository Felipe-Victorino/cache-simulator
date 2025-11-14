#include "cache.hpp"

Cache::Cache(std::string name, int latency, int associativity, int set_size)
{
    this->p_name = name;
    this->p_latency = latency;
    this->p_associativity = associativity;
    this->p_total_sets = set_size;
    this->p_policy = WRITE_BACK;
};

int Cache::calculateCacheSize(){
    int size = this->p_linesize * this->p_total_sets * this->p_associativity;
    return size;
};

void Cache::printCache(){
    std::cout << this->p_name << std::endl;
    std::cout << this->p_latency << std::endl;
    std::cout << this->p_linesize << std::endl;
    std::cout << this->p_associativity << std::endl;
    std::cout << this->p_total_sets << std::endl;
    std::cout << this->p_cache_size << std::endl;
    std::cout << this->p_policy << std::endl;

}
Cache::Cache()
{

}