#include <iostream>
#include <cstdint>

#include <my-lib/bit.h>
#include "cache.hpp"

#define DEBUG

#ifdef DEBUG
#define dprint(x) std::cout << x << '\n'
#else 
#define dprint(x) do{} while(0)
#endif

using BitSet = Mylib::BitSet<32>;

int main (int argc, char **argv)
{

	return 0;
}