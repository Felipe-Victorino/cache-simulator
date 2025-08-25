#include <iostream>
#include <cstdint>

#include <my-lib/bit.h>

using BitSet = Mylib::BitSet<32>;

int main (int argc, char **argv)
{
	BitSet bits;

	bits = 127;
	std::cout << bits << std::endl;

	bits[1, 2] = 0;
	std::cout << bits << std::endl;

	uint32_t most_sig = bits[31];
	std::cout << "Most significant bit: " << most_sig << std::endl;

	bits[31] = 1;
	std::cout << bits << std::endl;

	most_sig = bits[31];
	std::cout << "Most significant bit: " << most_sig << std::endl;

	bits[31] = bits[1];
	std::cout << bits << std::endl;

	return 0;
}