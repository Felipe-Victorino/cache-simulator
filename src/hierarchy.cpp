#include "hierarchy.hpp"
#include "debug.hpp"

MemoryHierarchy::MemoryHierarchy(int quantity, int runtime)
{
    this->p_levelQuantity = quantity;
    this->fillCacheList();
    this->mainMemory = configureMainMemory();
    Processor processor;

    this->processor = processor;

}


MainMemory MemoryHierarchy::configureMainMemory()
{
   MainMemory main;

   std::string name;
   uint32_t latency;

   
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
    uint32_t latency;
    uint32_t associativity;
    uint32_t sets;
    uint32_t policy;

    
    std::cout << "Set Name of Cache Level: ";
    std::getline(std::cin, name);
    std::cout << std::endl;

    std::cout << "Set latency: ";
    std::cin >> latency;
    std::cout << std::endl;

    std::cout << "Set associativity: ";
    std::cin >> associativity;
    std::cout << std::endl;

    std::cout << "Set set amount: ";
    std::cin >> sets;
    std::cout << std::endl;

    std::cout << "0 = Write-back, 1 = Write-through";
    std::cout << "Set policy: ";
    std::cin >> policy;
    std::cout << std::endl;

   

    cache.setName(name);
    cache.setLatency(latency);
    cache.setAssociativity(associativity);
    cache.setAssociativeSet(sets);
     
    if(policy == 0){
        cache.setPolicy(WRITE_BACK);
    } else if (policy == 1){
        cache.setPolicy(WRITE_THROUGH);
    } else {
        std::cout << "ERRO: Valor inválido: Valor padrão WRITE BACK";
        cache.setPolicy(WRITE_BACK);
    }
    cache.setCacheSize(cache.calculateCacheSize());
    
    return cache;
};

void MemoryHierarchy::fillCacheList()
{
    
    for (size_t i = 0; i < this->p_levelQuantity; i++)
    {
        std::cout << "Preenchendo cache" << std::endl;
        Cache cacheLevel;
        cacheLevel = configureCacheLevels();
        std::cin.ignore();
        this->cacheList.push_back(cacheLevel);
    }

    for (Cache c: cacheList){
        c.printCache();
    }
   
};