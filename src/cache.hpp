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
    enum WritePolicy p_policy;

	public:
    MemoryLevel();
    MemoryLevel(std::string name, int latency, BitSet bits);

    std::string getName();
    void setName(std::string name);

    int getLatency();
    void setLatency(int latency);

    BitSet getBitSet();
    void setBitSet(BitSet bits);

};


#endif