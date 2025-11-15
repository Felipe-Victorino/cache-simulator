#include "cache.hpp"

Cache::Cache(std::string name, int latency, int associativity, int set_amount, WritePolicy policy)
{
    this->p_name = name;
    this->p_latency = latency;
    this->p_associativity = associativity;
    this->p_set_amount = set_amount;
    this->p_policy = policy;
};

uint32_t Cache::calculateCacheSize(){
    int size = this->p_linesize * this->p_set_amount * this->p_associativity;
    return size;
};

uint32_t Cache::calculateLineTotal(){
    uint32_t total = this->p_associativity * this->p_set_amount;
    return total;
};

void Cache::printCache(){
    std::cout << "Name: " << this->p_name << std::endl;
    std::cout << "Latency: " << this->p_latency << std::endl;
    std::cout << "Line size: " << this->p_linesize << std::endl;
    std::cout << "Associativity: " << this->p_associativity << std::endl;
    std::cout << "Sets: " << this->p_set_amount << std::endl;
    std::cout << "Cache size: " << this->p_cache_size << std::endl;
    std::cout << "Policy: " << this->p_policy << std::endl;

}
Cache::Cache()
{

}