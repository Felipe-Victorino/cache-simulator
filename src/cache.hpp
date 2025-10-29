#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <my-lib/bit.h>

#define LINE_SIZE 32

using BitSet = Mylib::BitSet<LINE_SIZE>;
/*
A CACHE NÃO ARMAZENA DADOS REAIS, ELA É UM SIMULADOR DE TEMPO
*/

enum WritePolicy {
    WRITE_BACK,
    WRITE_THROUGH
};


class Cache{
    private:
    std::string p_name;
    int p_latency;
    int p_linesize = LINE_SIZE;//tamanho de linha da cache
    int p_associativity; // quantas linhas de memórias são agrupadas em uma linha de cache
    BitSet p_bits;
    int p_total_sets; 
    
    enum WritePolicy p_policy;

	public:
    Cache();
    Cache(std::string name, int latency, int associativity, int set_size);

    int calculateCacheSize();

    // GETTERS E SETTERS

    std::string getName(){return this->p_name;}
    void setName(std::string name){this->p_name = name;}

    int getLatency() {return this->p_latency;}
    void setLatency(int latency){this->p_latency = latency;}

    int getLineSize(){return this->p_linesize;}
    
    int getAssociativity(){return this->p_associativity;}
    void setAssociativity(int associativity){this->p_associativity = associativity;}

    int getAssociativeSetSize(){return this->p_total_sets;}

    BitSet getBitSet(){return this->p_bits;}
    void setBitSet(BitSet bits){this->p_bits = bits;};
};

#endif