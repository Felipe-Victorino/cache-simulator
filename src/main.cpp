#include <iostream>
#include <cstdint>
#include <cstdlib>

#include <my-lib/bit.h>
#include "hierarchy.hpp"
#include "debug.hpp"

int main (int argc, char **argv)
{
	std::cout << sizeof(uint32_t) * 8 << std::endl;
	if(argc != 3){
		printf("usage: %s [cache_levels] [n]\n", argv[0]);
		exit(0);
	}

	int cache_n = std::strtol(argv[1], NULL, 10);

	int runtime_n = std::strtol(argv[2], NULL, 10);
	
	MemoryHierarchy hierarchy(cache_n, runtime_n);
	return 0;
}