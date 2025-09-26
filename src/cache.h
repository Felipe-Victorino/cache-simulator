#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <my-lib/bit.h>

class Memory{
    private:
	
	public:

};

class CacheLevel{
	private:
	std::string name;
    int latency;

	public:
	CacheLevel(){};

};

class MainMemory{
    private:
    std::string name;
    int latency;

    public:
    MainMemory(){

    }

};

#endif