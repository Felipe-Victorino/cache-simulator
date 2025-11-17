#include <cmath>

#include "cache.hpp"

Cache::Cache()
{

}

Cache::Cache(std::string name, int latency, int associativity, int set_amount, WritePolicy policy)
{
    this->p_name = name;
    this->p_latency = latency;
    this->p_associativity = associativity;
    this->p_set_amount = set_amount;
    this->p_policy = policy;
    this->p_cache_size = calculateCacheSize();
    
    for (size_t i = 0; i < calculateLineTotal(); i++)
    {
        CacheLine line;
        this->p_lines.push_back(line);
    }
    
};

uint32_t Cache::calculateCacheSize(){
    int size = this->p_linesize * this->p_set_amount * this->p_associativity;
    return size;
};

uint32_t Cache::calculateLineTotal(){
    uint32_t total = this->p_associativity * this->p_set_amount;
    return total;
};

uint32_t Cache::calculateOffsetSize(){
    return std::log2(this->p_linesize);
};

uint32_t Cache::calculateIndexSize(){
    return std::log2(this->p_set_amount);
};

uint32_t Cache::calculateTagSize(){
    return this->p_linesize - calculateIndexSize() - calculateOffsetSize();
}

void Cache::printCache(){
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << '=';
    }
    std::cout << std::endl;
    
    std::cout << "Name: " << this->p_name << std::endl;
    std::cout << "Latency: " << this->p_latency << std::endl;
    std::cout << "Line size: " << this->p_linesize << std::endl;
    std::cout << "Associativity: " << this->p_associativity << std::endl;
    std::cout << "Sets: " << this->p_set_amount << std::endl;
    std::cout << "Line total:" << calculateLineTotal() << std::endl;
    std::cout << "Cache size: " << this->p_cache_size << std::endl;

    std::cout << "Policy: " << this->p_policy << std::endl;

}
