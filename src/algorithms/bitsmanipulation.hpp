#ifndef BITSMANIPULATION_HPP_
#define BITSMANIPULATION_HPP_

#include <iostream>
#include <limits>
#include <bitset>

void Representation()
{
    std::cout << "Representation of the numbers in binary and hex" <<
                    std::endl;

    const long long unsigned int max = std::numeric_limits<unsigned char>::max();
    for (long long unsigned int i = 0; i <= max; ++i)
    {
        std::cout << "Dec: " <<  std::dec << std::showbase << i;
        std::cout << " Bin: 0b" << std::bitset<8>(i).to_string();
        std::cout << " Oct: " << std::oct << std::showbase << i;
        std::cout << " Hex: " << std::hex << std::showbase << i << std::endl;
    }
}

// TODO: AND operation
// TODO: OR operation
// TODO: XOR operation
// TODO: bit reversing
// TODO: bit rotation
// TODO: number multiplication to 2
// TODO: number division by 2

void StartBM()
{
    Representation();
}

#endif /* BITSMANIPULATION_HPP_ */
