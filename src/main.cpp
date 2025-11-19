#include <iostream>
#include <string_view>

#include <cstdint>
#include <cstdlib>
#include <ctime>

#include <my-lib/bit.h>

#include "hierarchy.hpp"

int main (int argc, char **argv)
{
	srand(time(0)); //semente de aleatoriedade
	/// RETIRAR CACHE LEVELS 
	if(argc < 2){
		printf("usage: %s sequential [cache_levels] [n] [buffer] [stride] [write_ratio]\n", argv[0]);
		printf("usage: %s random [cache_levels] [n] [buffer] [write_ratio]\n", argv[0]);
		exit(0);
	}
	if(std::string_view(argv[1]) == "sequential"){
		if (argc != 7) {
            printf("usage: %s sequential [cache_levels] [n] [buffer] [stride] [write_ratio]\n", argv[0]);
            exit(0);
        }
		uint32_t cache_n = std::strtol(argv[2], nullptr, 10);
		uint32_t runtime_n = std::strtol(argv[3], nullptr, 10);
		uint32_t buffer = std::strtol(argv[4], nullptr, 10);
		uint32_t stride_n = std::strtol(argv[5], nullptr, 10);
		uint32_t write_ratio = std::strtol(argv[6], nullptr, 10);

		MemoryHierarchy hierarchy(cache_n, runtime_n, buffer, stride_n, write_ratio);

	} else if (std::string_view(argv[1]) == "random"){
		if (argc != 6) {
            printf("usage: %s random [cache_levels] [n] [buffer] [write_ratio]\n", argv[0]);
            exit(0);
        }
		uint32_t cache_n = std::strtol(argv[2], nullptr, 10);
		uint32_t runtime_n = std::strtol(argv[3], nullptr, 10);
		uint32_t buffer = std::strtol(argv[4], nullptr, 10);
		uint32_t write_ratio = std::strtol(argv[5], nullptr, 10);; 

		MemoryHierarchy hierarchy(cache_n, runtime_n, buffer, write_ratio);

	} else {
		printf("usage: %s sequential [cache_levels] [n] [stride]\n", argv[0]);
		printf("usage: %s random [cache_levels] [n] \n", argv[0]);
		exit(0);
	}

	
	
	return 0;
}