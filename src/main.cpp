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
	// basicamente bitset é um espaco de armazenamento
	BitSet bits;

	MemoryLevel ml;

	

	bits = 127;
	dprint(bits);

	// primeiro parâmetro é o bit inicial
	// segundo parâmetro é a quantidade de bits a partir do bit inicial
	bits[1, 2] = 0;
	dprint(bits);

	uint32_t most_sig = bits[31];
	std::cout << "Most significant bit: " << most_sig << std::endl;

	// quando for só 1 bit, pode omitir o segundo parâmetro
	bits[31] = 1;
	dprint(bits);

	most_sig = bits[31];
	std::cout << "Most significant bit: " << most_sig << std::endl;

	bits[31] = bits[1];
	dprint(bits);

	return 0;
}