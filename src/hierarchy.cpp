#include <format>

#include "hierarchy.hpp"


MemoryHierarchy::MemoryHierarchy(uint32_t quantity, uint32_t runtime, int32_t buffer, int32_t write_ratio)
{
    this->p_levelQuantity = quantity;
    this->p_n = runtime;
    this->p_buffer = buffer;
    this->p_write_ratio = write_ratio;

    this->fillCacheList();
    this->mainMemory = configureMainMemory();
    Processor processor;

    this->processor = processor;

    randomAccess();

    printCaches();
    printStats();
}

MemoryHierarchy::MemoryHierarchy(uint32_t quantity, uint32_t runtime, int32_t buffer, uint32_t stride, int32_t write_ratio)
{
    this->p_levelQuantity = quantity;
    this->p_n = runtime;
    this->p_buffer = buffer;
    this->p_stride = stride;
    this->p_write_ratio = write_ratio;

    this->fillCacheList();
    this->mainMemory = configureMainMemory();

    Processor processor;
    this->processor = processor;

    sequentialAccess();

    printCaches();
    printStats();
}

MainMemory MemoryHierarchy::configureMainMemory()
{
    MainMemory main;
    main.setName(MAIN_NAME);
    main.setLatency(MAIN_LATENCY);
    return main;
};

void MemoryHierarchy::fillCacheList()
{
    std::cout << "Preenchendo cache" << std::endl;

    Cache l1 = Cache(L1_NAME, L1_LATENCY, L1_ASSOCIATIVITY, L1_SET_AMOUNT, L1_POLICY);
    Cache l2 = Cache(L2_NAME, L2_LATENCY, L2_ASSOCIATIVITY, L2_SET_AMOUNT, L2_POLICY);
    Cache l3 = Cache(L3_NAME, L3_LATENCY, L3_ASSOCIATIVITY, L3_SET_AMOUNT, L3_POLICY);

    this->cacheList.push_back(l1);
    this->cacheList.push_back(l2);
    this->cacheList.push_back(l3);
};

void MemoryHierarchy::printCaches()
{
    for (Cache cache : this->cacheList)
    {
        cache.printCache();
    }
};

void MemoryHierarchy::printStats()
{
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << '=';
    }
    std::cout << std::endl;

    std::cout << "Cycles: " << this->p_cycles_used << std::endl;

    for (size_t i = 0; i < 50; i++)
    {
        std::cout << '=';
    }
    std::cout << std::endl;

    for (Cache& cache : this->cacheList)
    {
        std::cout << "Name: " << cache.getName() << std::endl;
        std::cout << "Cache hits: " << cache.getCacheHit() << std::endl;
        std::cout << "Cache misses: " << cache.getCacheMiss() << std::endl;
    }

    for (size_t i = 0; i < 50; i++)
    {
        std::cout << '=';
    }
    std::cout << std::endl;

    std::cout << "MAIN MEMORY:" << std::endl;
    std::cout << "Read: " << this->mainMemory.getReadCount() << std::endl;
    std::cout << "Write: " << this->mainMemory.getWriteCount() << std::endl;
    std::cout << "Total: " << (this->mainMemory.getReadCount() + this->mainMemory.getWriteCount()) << std::endl;

    for (size_t i = 0; i < 50; i++)
    {
        std::cout << '=';
    }
    std::cout << std::endl;
}

void MemoryHierarchy::randomAccess()
{
    for (size_t i = 0; i < this->p_n; i++)
    {
        GroupIns ins = processor.sendInstruction(this->p_write_ratio);
        // Generate address within buffer range
        ins.address = static_cast<uint32_t>(rand()) % this->p_buffer;
        search(ins);

        // std::cout << std::format("endereço requisitado: {:#010x}", ins.address) << std::endl;
    }
};

void MemoryHierarchy::sequentialAccess()
{
    uint32_t current_address = 0;

    for (size_t i = 0; i < this->p_n; i++)
    {
        if (i > 0 && i % this->p_buffer == 0)
        {
            current_address = 0; // Reset to beginning of buffer
        }

        GroupIns ins = processor.sendInstruction(this->p_write_ratio);
        ins.address = current_address;
        search(ins);

        current_address += this->p_stride;

        // std::cout << std::format("endereço requisitado: {:#010x}", current_address) << std::endl;
    }
};

uint32_t MemoryHierarchy::getTag(uint32_t address, uint32_t tag_size, uint32_t index_size, uint32_t offset_size)
{
    uint32_t tag = address >> (offset_size + index_size);
    return tag;
};

uint32_t MemoryHierarchy::getIndex(uint32_t address, uint32_t tag_size, uint32_t index_size, uint32_t offset_size)
{
    uint32_t tag_index = address >> offset_size;
    uint32_t mask = (1 << index_size) - 1;
    uint32_t index = tag_index & mask;
    return index;
}

void MemoryHierarchy::search(GroupIns instruction)
{
    bool hit = false;

    for (Cache& level : this->cacheList)
    {
        uint32_t tag_size = level.calculateTagSize();
        uint32_t index_size = level.calculateIndexSize();
        uint32_t offset_size = level.calculateOffsetSize();

        uint32_t tag = getTag(instruction.address, tag_size, index_size, offset_size);
        uint32_t index = getIndex(instruction.address, tag_size, index_size, offset_size);

        this->p_cycles_used += level.getLatency();

        uint32_t result = level.checkLines(tag, index);


        if (result == 1)
        {
            hit = true;
            break; 
        }

    }

    if (!hit)
    {
        addInstructionTypeCounter(instruction.type);
        this->p_cycles_used += this->mainMemory.getLatency();
    }
};

void MemoryHierarchy::addInstructionTypeCounter(InstructionType type)
{
    switch (type)
    {
    case WRITE:
        this->mainMemory.incWriteCount();
        break;
    case READ:
        this->mainMemory.incReadCount();
        break;
    default:
        std::cerr << "Tipo de instrução inválido";
        exit(0);
    }
}
/*
void MemoryHierarchy::copyBack(Cache &level, GroupIns instruction)
{
    for (Cache& l : this->cacheList) //&
    {

        l.getLines().at(index).tag = instruction.address;

        if (l.getName() == level.getName()) //como comparar objetos
        {
            return;
        }

    }
};
*/