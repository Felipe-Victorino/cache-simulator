#include <my-lib/math.h>

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

uint32_t Cache::calculateCacheSize()
{
    int size = this->p_linesize * this->p_set_amount * this->p_associativity;
    return size;
};

uint32_t Cache::calculateLineTotal()
{
    uint32_t total = this->p_associativity * this->p_set_amount;
    return total;
};

uint32_t Cache::calculateOffsetSize()
{
    return Mylib::Math::base2_log_of_integer(this->p_linesize); //
};

uint32_t Cache::calculateIndexSize()
{
    return Mylib::Math::base2_log_of_integer(this->p_set_amount);
};

uint32_t Cache::calculateTagSize()
{
    return 32 - calculateIndexSize() - calculateOffsetSize();
}

uint32_t Cache::checkLines(uint32_t tag, uint32_t index)
{
    // Calculate the starting line for this set
    uint32_t set_start = index * this->p_associativity;

    // Check only the lines in this specific set
    for (size_t i = set_start; i < set_start + this->p_associativity; i++)
    {
        if (this->p_lines.at(i).content && this->p_lines.at(i).tag == tag)
        {
            incCacheHit();
            return 1;
        }
    }

    // Only count as miss once per search
    incCacheMiss();
    return 0;
};

void Cache::writeBack() {

};

void Cache::writeThrough() {

};

void Cache::printCache()
{
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
