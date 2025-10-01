#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <my-lib/bit.h>

using BitSet = Mylib::BitSet<32>;

enum WritePolicy {
    WRITE_BACK,
    WRITE_THROUGH
}

class MemoryLevel{
    private:
    std::string p_name;
    int p_latency;
    int p_linesize;
    BitSet p_bits;
    int associative_set_size;
    Bitset associative_set[];
    
    enum WritePolicy p_policy;

    MemoryLevel *next;

	public:
    MemoryLevel();
    MemoryLevel(std::string name, int latency, BitSet bits);
    ~MemoryLevel();

    std::string MemoryLevel::getName()
    {
        return this->p_name;
    }
    void MemoryLevel::setName(std::string name)
    {
        this->p_name = name;
    }
   
    int MemoryLevel::getLatency()
    {
        return this->p_latency;
    }

    void MemoryLevel::setLatency(int latency){
        this->p_latency = latency;
    }

    BitSet MemoryLevel::getBitSet(){
        return this->p_bits;
    }

    void setBitSet(BitSet bits){
        this->p_bits = bits;
    };
};


#endif