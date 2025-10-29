#ifndef HIERARCHY_H
#define HIERARCHY_H
#include <list>

#include "cache.hpp"
#include "processor.hpp"




class MemoryHierarchy{

    private:
    /* Ultima cache da lista é memória principal*/
    
    std::list<Cache> cacheList; // lista com as memórias
    Processor processor; // objeto processador
    unsigned int p_levelQuantity; // quantidade de caches, deve ser maior que 0

    Cache configureMainMemory();
    Cache configureCacheLevels();

    public:

    MemoryHierarchy(int quantity);

    int getLevelQuantity(){return this->p_levelQuantity;}

    void fillCacheList();

};

#endif