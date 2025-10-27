#include "processor.hpp"

#define DEBUG

#ifdef DEBUG
#define dprint(x) std::cout << x << '\n'
#else 
#define dprint(x) do{} while(0)
#endif

Processor::Processor(std::list<Cache> *cache)
{
    this->cache = cache;
}

Processor::~Processor()
{
}