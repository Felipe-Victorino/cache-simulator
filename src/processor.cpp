#include "processor.hpp"
#include "debug.hpp"

Processor::Processor()
{

}

Processor::~Processor()
{
}

void Processor::write(){

}

void Processor::read(){

}

void Processor::randomAccess()
{
    for (size_t i = 0; i < this->p_n; this->genRandomAddress())
    {
        std::cout << this->p_cache->at(i).getLatency();
    }
    
}

void Processor::search()
{

}

void Processor::sequentialAccess()
{
    for (size_t i = 0; i < this->p_n; i + this->p_stride)
    {
        std::cout << this->p_cache->at(i).getLatency();
        
    }
    
    
}