#ifndef HIERARCHY_H
#define HIERARCHY_H
#include <list>

#include "cache.hpp"
#include "processor.hpp"

const std::string L1_NAME = "L1";
const uint32_t L1_LATENCY = 1;
const uint32_t L1_ASSOCIATIVITY = 4;
const uint32_t L1_SET_AMOUNT = 8;
const WritePolicy L1_POLICY = WRITE_BACK;

const std::string L2_NAME = "L2";
const uint32_t L2_LATENCY = 4;
const uint32_t L2_ASSOCIATIVITY = 4;
const uint32_t L2_SET_AMOUNT = 16;
const WritePolicy L2_POLICY = WRITE_BACK;

const std::string L3_NAME = "L3";
const uint32_t L3_LATENCY = 8;
const uint32_t L3_ASSOCIATIVITY = 4;
const uint32_t L3_SET_AMOUNT = 32;
const WritePolicy L3_POLICY = WRITE_BACK;

const std::string MAIN_NAME = "Main Memory";
const uint32_t MAIN_LATENCY = 220;

class MemoryHierarchy{

private:
    /* Ultima cache da lista é memória principal*/
    uint32_t p_n;
    uint32_t p_stride = 1;
    uint32_t p_buffer;
    uint32_t p_write_ratio;
    uint32_t p_cycles_used;

    Processor processor; // objeto processador
    std::vector<Cache> cacheList; // lista com as memórias
    MainMemory mainMemory; // objeto memória principal
    uint32_t p_levelQuantity; // quantidade de caches, deve ser maior que 0

    MainMemory configureMainMemory();
    Cache configureCacheLevels();

public:

    MemoryHierarchy(uint32_t quantity, uint32_t runtime, int32_t buffer, uint32_t stride, int32_t write_ratio);
    MemoryHierarchy(uint32_t quantity, uint32_t runtime, int32_t buffer, int32_t write_ratio);

    int getLevelQuantity(){return this->p_levelQuantity;}

    void fillCacheList();
    void printCaches();
    void printStats();

    int genRandomAddress();

    void search(uint32_t address);
    void randomAccess();
    void sequentialAccess();

};

#endif