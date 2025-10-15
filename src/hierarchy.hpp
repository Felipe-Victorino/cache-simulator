#ifndef HIERARCHY_H
#define HIERARCHY_H
#include "cache.hpp"
#include "processor.hpp"

class MemoryHierarchy{

    MemoryList cacheList;
    Processor processor;


}

class MemoryList{
    private:
        MemoryNode root;
    public:
        public add(MemoryNode node);
    
}

typedef struct MemoryNode{
    Cache ml;

    MemoryNode* next;

    MemoryNode();

} MemoryNode;

#endif