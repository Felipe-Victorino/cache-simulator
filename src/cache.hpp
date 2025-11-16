#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <vector>
#include <my-lib/bit.h>

using BitSet = Mylib::BitSet<32>;
/*
A CACHE NÃO ARMAZENA DADOS REAIS, ELA É UM SIMULADOR DE TEMPO
*/

//representa uma linha
// offset log2 tamanho linha
// qtd total de linhas = associatividade * conjuntos

struct CacheLine {
    int content : 1;
    uint32_t tag;
    bool dirty = false;
    u_int32_t age;
};
// guardar structs em um vetor até que se tenha o tamanho da cache;

enum WritePolicy {WRITE_BACK, WRITE_THROUGH};

class MainMemory{
private:
    std::string p_name;
    uint32_t p_latency;
    uint32_t p_size = sizeof(uint32_t) * 8; // 32 bits, a quantidade de endereços da memória
public:

    std::string getName(){return this->p_name;}
    uint32_t getLatency() {return this->p_latency;}
    void setName(std::string name){this->p_name = name;}
    void setLatency(uint32_t latency){this->p_latency = latency;}
};

class Cache
{
private:
    std::string p_name;
    uint32_t p_cache_size;

    uint32_t p_latency;
    uint32_t p_linesize = 32; //tamanho de linha da cache
    uint32_t p_associativity; // quantas linhas de memórias são agrupadas em uma linha de cache
    uint32_t p_set_amount;
    std::vector<CacheLine> p_lines;
    WritePolicy p_policy;

    uint32_t p_cache_hit;
    uint32_t p_cache_miss;

public:
    Cache();
    Cache(std::string name, int latency, int associativity, int set_amount, WritePolicy policy);

    uint32_t calculateCacheSize();
    uint32_t calculateLineTotal();
    void printCache();

    // GETTERS E SETTERS

    std::vector<CacheLine> getLines(){return this->p_lines;}

    std::string getName(){return this->p_name;}
    void setName(std::string name){this->p_name = name;}

    uint32_t getLatency() {return this->p_latency;}
    void setLatency(int latency){this->p_latency = latency;}

    uint32_t getCacheSize(){return this->p_cache_size;}
    void setCacheSize(uint32_t size){this->p_cache_size = size;}

    uint32_t getLineSize(){return this->p_linesize;}
    
    uint32_t getAssociativity(){return this->p_associativity;}
    void setAssociativity(uint32_t associativity){this->p_associativity = associativity;}

    uint32_t getAssociativeSet(){return this->p_set_amount;}
    void setAssociativeSet(uint32_t sets){this->p_set_amount = sets;}

    WritePolicy getPolicy(){return this->p_policy;}
    void setPolicy(WritePolicy policy){ this->p_policy = policy;}

    uint32_t getCacheHit(){return this->p_cache_hit;}
    void incCacheHit(){this->p_cache_hit += 1;}

    uint32_t getCacheMiss(){return this->p_cache_miss;}
    void incCacheMiss(){this->p_cache_miss += 1;}

};

#endif