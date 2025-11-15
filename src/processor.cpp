#include "processor.hpp"
#include "debug.hpp"

Processor::Processor()
{

}

Processor::~Processor()
{
}

Instruction Processor::write(){
    return WRITE;
}

Instruction Processor::read(){
    return READ;
}

uint32_t Processor::genRandomAddress()
{
    return std::rand() % (sizeof(uint32_t) * 8);
};