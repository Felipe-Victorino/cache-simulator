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
    //infelizmente a rand tem um limite de um inteiro com sinal;
    //felizmente o bitshift é uma possibilidade
    return static_cast<uint32_t>(rand());
};