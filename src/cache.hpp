#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <vector>
#include <my-lib/bit.h>

#define LINE_SIZE 32

using BitSet = Mylib::BitSet<LINE_SIZE>;
/*
A CACHE NÃO ARMAZENA DADOS REAIS, ELA É UM SIMULADOR DE TEMPO
*/



//representa uma linha
typedef struct {
    bool dirty = false;
    int32_t tag;
    int content : 1;
} CacheLine;
// guardar structs em um vetor até que se tenha o tamanho da cache;

enum WritePolicy {WRITE_BACK, WRITE_THROUGH};

class MainMemory{
private:
    std::string p_name;
    uint32_t p_latency;
    uint32_t p_size ; // 32 bits, a quantidade de endereços da memória
public:

    std::string getName(){return this->p_name;}
    uint32_t getLatency() {return this->p_latency;}
    void setName(std::string name){this->p_name = name;}
    void setLatency(int latency){this->p_latency = latency;}
};

class Cache{

private:
    std::string p_name;
    uint32_t p_cache_size;

    uint32_t p_latency;
    uint32_t p_linesize = LINE_SIZE;//tamanho de linha da cache
    uint32_t p_associativity; // quantas linhas de memórias são agrupadas em uma linha de cache
    uint32_t p_total_sets;
    std::vector<CacheLine> lines;
    enum WritePolicy p_policy;

public:
    Cache();
    Cache(std::string name, int latency, int associativity, int set_size);

    uint32_t calculateCacheSize();
    void printCache();

    // GETTERS E SETTERS

    std::string getName(){return this->p_name;}
    void setName(std::string name){this->p_name = name;}

    uint32_t getLatency() {return this->p_latency;}
    void setLatency(int latency){this->p_latency = latency;}

    uint32_t getCacheSize(){return this->p_cache_size;}
    void setCacheSize(uint32_t size){this->p_cache_size = size;}

    uint32_t getLineSize(){return this->p_linesize;}
    
    uint32_t getAssociativity(){return this->p_associativity;}
    void setAssociativity(uint32_t associativity){this->p_associativity = associativity;}

    uint32_t getAssociativeSet(){return this->p_total_sets;}
    void setAssociativeSet(uint32_t sets){this->p_total_sets = sets;};

    WritePolicy getPolicy(){return this->p_policy;};
    void setPolicy(WritePolicy policy){ this->p_policy = policy;}

};

#endif