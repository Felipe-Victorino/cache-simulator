#include "hierarchy.hpp"
#include "debug.hpp"

MemoryHierarchy::MemoryHierarchy(uint32_t quantity, uint32_t runtime, int32_t buffer, int32_t write_ratio)
{
    this->p_levelQuantity = quantity;
    this->p_n = runtime;
    this->p_buffer = buffer;
    this->p_write_ratio = write_ratio;

    this->fillCacheList();
    this->mainMemory = configureMainMemory();
    Processor processor;

    this->processor = processor;

    randomAccess();

}

MemoryHierarchy::MemoryHierarchy(uint32_t quantity, uint32_t runtime, int32_t buffer, uint32_t stride, int32_t write_ratio)
{
    this->p_levelQuantity = quantity;
    this->p_n = runtime;
    this->p_buffer = buffer;
    this->p_stride = stride;
    this->p_write_ratio = write_ratio;

    this->fillCacheList();
    this->mainMemory = configureMainMemory();
    
    Processor processor;
    this->processor = processor;

    sequentialAccess();

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
        if (i + 1 > this->p_buffer){
            i = 0;
        }
        uint32_t target = this->processor.genRandomAddress();
        search(target);

        std::cout << i << std::endl;
        
    }
    
};

void MemoryHierarchy::sequentialAccess()
{
    for (size_t i = 0; i < this->p_n; i += p_stride)
    {
        if (i + 1 > this->p_buffer){
            i = 0;
        }

        uint32_t target = i;
        search(target);

        std::cout << i << std::endl;
    }
    
    
    
};

void MemoryHierarchy::search(uint32_t address)
{

    for(Cache level : this->cacheList){
        this->p_cycles_used += level.getLatency();
        
        for (CacheLine line : level.getLines()){

            if(line.tag == address){
                level.incCacheHit();
                return;
            } else {
                level.incCacheMiss();
                return;
            }
        }
    }
};