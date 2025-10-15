#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <my-lib/bit.h>

using BitSet = Mylib::BitSet<32>;

enum WritePolicy {
    WRITE_BACK,
    WRITE_THROUGH
};

enum Associativity{
    FULL,
    DIRECT,
    SET
};

class Cache{
    private:
    std::string p_name;
    int p_latency;
    int p_linesize;
    BitSet p_bits;
    int associative_set_size;
    
    enum WritePolicy p_policy;

	public:
    Cache();
    Cache(std::string name, int latency, int linesize, int set_size);

    std::string getName(){return this->p_name;}
    void setName(std::string name){this->p_name = name;}
    int getLatency() {return this->p_latency;}
    void setLatency(int latency){this->p_latency = latency;}
    int getAssociativeSetSize(){return this->associative_set_size;}
    BitSet getBitSet(){return this->p_bits;}
    void setBitSet(BitSet bits){this->p_bits = bits;};
};

#endif