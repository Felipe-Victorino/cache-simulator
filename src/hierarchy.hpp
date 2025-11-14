#ifndef HIERARCHY_H
#define HIERARCHY_H
#include <list>

#include "cache.hpp"
#include "processor.hpp"

class MemoryHierarchy{

    private:
    /* Ultima cache da lista é memória principal*/
    uint32_t p_n;
    uint32_t p_stride;
    std::vector<Cache> cacheList; // lista com as memórias
    Processor processor; // objeto processador
    MainMemory mainMemory; // objeto memória principal
    unsigned int p_levelQuantity; // quantidade de caches, deve ser maior que 0

    MainMemory configureMainMemory();
    Cache configureCacheLevels();

    public:

    MemoryHierarchy(int quantity, int runtime);

    int getLevelQuantity(){return this->p_levelQuantity;}

    void fillCacheList();

};

#endif