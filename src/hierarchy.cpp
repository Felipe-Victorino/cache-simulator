#include "hierarchy.hpp"
#include "debug.hpp"

MemoryHierarchy::MemoryHierarchy(uint32_t quantity, uint32_t runtime)
{
    this->p_levelQuantity = quantity;
    this->fillCacheList();
    this->mainMemory = configureMainMemory();
    Processor processor;

    this->processor = processor;

}

MemoryHierarchy::MemoryHierarchy(uint32_t quantity, uint32_t runtime, uint32_t stride)
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
   main.setName(MAIN_NAME);
   main.setLatency(MAIN_LATENCY);
   return main;
};

void MemoryHierarchy::fillCacheList()
{
    std::cout << "Preenchendo cache" << std::endl;
    
    Cache l1 = Cache(L1_NAME, L1_LATENCY, L1_ASSOCIATIVITY, L1_SET_AMOUNT, L1_POLICY);
    Cache l2 = Cache(L2_NAME, L2_LATENCY, L2_ASSOCIATIVITY, L2_SET_AMOUNT, L2_POLICY);
    Cache l3 = Cache(L3_NAME, L3_LATENCY, L3_ASSOCIATIVITY, L3_SET_AMOUNT, L3_POLICY);
    
    this->cacheList.push_back(l1);
    this->cacheList.push_back(l2);
    this->cacheList.push_back(l3);  

};

void MemoryHierarchy::randomAccess()
{
    for (size_t i = 0; i < this->p_n; i++)
    {
        uint32_t target = this->processor.genRandomAddress();
        //std::cout << this->cacheList.at(i).getLatency();
    }
    
};

void MemoryHierarchy::sequentialAccess()
{
    for (size_t i = 0; i < this->p_n; i += this->p_stride)
    {
        uint32_t target = this->processor.genRandomAddress();

        //std::cout << this->cacheList.at(i).getLatency();
        
    }
    
    
};

void MemoryHierarchy::search(uint32_t address)
{

};