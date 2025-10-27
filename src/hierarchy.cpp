#include "hierarchy.hpp"

MemoryHierarchy::MemoryHierarchy(int quantity)
{
    this->p_levelQuantity = quantity;
    Processor processor(this->cacheList);
    this->processor = processor;
}

Cache MemoryHierarchy::configureMainMemory()
{
    
}

void MemoryHierarchy::fillCacheList()
{
    Cache cacheLevel("Main Memory", 3, 3, 32, 4);
    for (size_t i = 0; i < this->p_levelQuantity; i++)
    {
         this->cacheList.emplace_back(cacheLevel);
    }
    dprint();
   
}