#ifndef PROCESSOR_H
#define PROCESSOR_H

enum MemoryAccess{
    SEQUENTIAL,
    RANDOM
};

class Processor
{
private:
    enum MemoryAcesss p_access;
public:
    Processor(/* args */);
    ~Processor();
};





#endif