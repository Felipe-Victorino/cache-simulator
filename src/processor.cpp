#include "processor.hpp"
#include "debug.hpp"

Processor::Processor()
{

}

Processor::~Processor()
{
}

GroupIns Processor::sendInstruction(uint32_t write_ratio)
{
    GroupIns ins;

    if( static_cast<uint32_t>((rand() % 100)) < write_ratio){
        ins.type = WRITE;
    } else {
        ins.type = READ;
    };

    return ins;
}

uint32_t Processor::genRandomAddress()
{
    return static_cast<uint32_t>(rand());
};