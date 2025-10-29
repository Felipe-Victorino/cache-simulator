#include "hierarchy.hpp"

MemoryHierarchy::MemoryHierarchy(int quantity)
{
    this->p_levelQuantity = quantity;
    Processor processor(&this->cacheList);
    this->processor = processor;
}

Cache MemoryHierarchy::configureMainMemory()
{
   Cache main;

   std::string name;
   int latency;

   std::cout << "Set Name of Main Memory: ";
   std::getline(std::cin, name);
   std::cout << '\n';

   std::cout << "Set latency: ";
   std::cin >> latency;
   std::cout << '\n';

   main.setName(name);
   main.setLatency(latency);
   
   return main;
};

Cache MemoryHierarchy::configureCacheLevels(){

    Cache cache;

    std::string name;
    int latency;

    std::cout << "Set Name of Main Memory: ";
    std::getline(std::cin, name);
    std::cout << '\n';

    std::cout << "Set latency: ";
    std::cin >> latency;
    std::cout << '\n';

    cache.setName(name);
    cache.setLatency(latency);
    

    return cache;
};

void MemoryHierarchy::fillCacheList()
{
    Cache cacheLevel("Main Memory", 3, 3, 4);
    for (size_t i = 0; i < this->p_levelQuantity; i++)
    {
         this->cacheList.emplace_back(cacheLevel);
    }
   
};