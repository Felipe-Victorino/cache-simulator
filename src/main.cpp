#include <iostream>
#include <cstdint>

#include <my-lib/bit.h>

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

	bits = 127;
	std::cout << bits << std::endl;

	// primeiro parâmetro é o bit inicial
	// segundo parâmetro é a quantidade de bits a partir do bit inicial
	bits[1, 2] = 0;
	std::cout << bits << std::endl;

	uint32_t most_sig = bits[31];
	std::cout << "Most significant bit: " << most_sig << std::endl;

	// quando for só 1 bit, pode omitir o segundo parâmetro
	bits[31] = 1;
	std::cout << bits << std::endl;

	most_sig = bits[31];
	std::cout << "Most significant bit: " << most_sig << std::endl;

	bits[31] = bits[1];
	std::cout << bits << std::endl;

	return 0;
}

class Cache{
	public:
	Cache(){

	}
};
