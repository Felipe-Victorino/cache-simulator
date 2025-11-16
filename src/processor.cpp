#include "processor.hpp"
#include "debug.hpp"

Processor::Processor()
{

}

Processor::~Processor()
{
}

Instruction Processor::write(){
    Instruction ins = WRITE;
    return ins;
}

Instruction Processor::read(){
    Instruction ins = READ;
    return ins;
}

uint32_t Processor::genRandomAddress()
{
    return std::rand() % (sizeof(uint32_t) * 8);
};