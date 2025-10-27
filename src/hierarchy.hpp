#ifndef HIERARCHY_H
#define HIERARCHY_H
#include "cache.hpp"
#include "processor.hpp"
#include <list>



class MemoryHierarchy{


    /* Ultima cache da lista é memória principal*/
    std::list<Cache> cacheList;
    Processor processor;
    int p_levelQuantity;

    public:

    MemoryHierarchy(int quantity);

    int getLevelQuantity(){return this->p_levelQuantity;}

    void fillCacheList();

};

#endif