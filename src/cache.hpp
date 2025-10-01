#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <my-lib/bit.h>

using BitSet = Mylib::BitSet<32>;

class MemoryLevel{
    private:
    std::string p_name;
    int p_latency;
    BitSet bits;

	public:
    MemoryLevel(std::string name, int latency);

    std::string getName();
    void setName(std::string name);

    int getLatency();
    void setLatency(int latency);

};


#endif