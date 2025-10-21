#include "hierarchy.hpp"

MemoryHierarchy::MemoryHierarchy(int quantity){
    this->p_levelQuantity = quantity;
}

void MemoryHierarchy::fillCacheList(){
    Cache cacheLevel("test", 3, 3, 32, 4);
    this->cacheList.emplace_back(cacheLevel);
}