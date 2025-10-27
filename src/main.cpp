#include <iostream>
#include <cstdint>
#include <cstdlib>

#include <my-lib/bit.h>
#include "hierarchy.hpp"

#define DEBUG

#ifdef DEBUG
#define dprint(x) std::cout << x << '\n'
#else 
#define dprint(x) do{} while(0)
#endif

int main (int argc, char **argv)
{
	if(argc != 2){
		printf("usage: %s [cache_levels]\n", argv[0]);
		exit(0);
	}

	int conv = std::strtol(argv[1], NULL, 10);

	dprint(conv);

	MemoryHierarchy hierarchy(conv);
	return 0;
}