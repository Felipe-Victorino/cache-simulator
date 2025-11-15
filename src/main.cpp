#include <iostream>
#include <string_view>

#include <cstdint>
#include <cstdlib>

#include <my-lib/bit.h>

#include "hierarchy.hpp"
#include "debug.hpp"

int main (int argc, char **argv)
{
	
	if(argc != 3){
		printf("usage: %s sequential [cache_levels] [n] [stride]\n", argv[0]);
		printf("usage: %s random [cache_levels] [n] \n", argv[0]);
		exit(0);
	}
	if(std::string_view(argv[1]) == "sequential"){
		uint32_t cache_n = std::strtol(argv[2], NULL, 10);
		uint32_t runtime_n = std::strtol(argv[3], NULL, 10);
		uint32_t stride_n = std::strtol(argv[4], NULL, 10);

		MemoryHierarchy hierarchy(cache_n, runtime_n, stride_n);

	} else if (std::string_view(argv[1]) == "random"){
		uint32_t cache_n = std::strtol(argv[2], NULL, 10);
		uint32_t runtime_n = std::strtol(argv[3], NULL, 10);

		MemoryHierarchy hierarchy(cache_n, runtime_n);

	} else {
		printf("usage: %s sequential [cache_levels] [n] [stride]\n", argv[0]);
		printf("usage: %s random [cache_levels] [n] \n", argv[0]);
		exit(0);
	}

	
	
	return 0;
}