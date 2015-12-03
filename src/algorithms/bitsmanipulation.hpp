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

    std::cout << std::endl;
}

void OperationAND()
{
    std::cout << "Example of AND operation" << std::endl;
    unsigned char first = 0b00111000;
    unsigned char second = 0b10101010;
    unsigned char result = first & second;

    std::cout << "First value: 0b" << std::bitset<8>(first).to_string() <<
                    std::endl;
    std::cout << "Second value: 0b" << std::bitset<8>(second).to_string() <<
                    std::endl;
    std::cout << "Result of AND operation: 0b" <<
                    std::bitset<8>(result).to_string() << std::endl;

    first = 0b11111000;
    second = 0b10101011;
    result = first & second;

    std::cout << std::endl << "With other values" << std::endl;
    std::cout << "First value: 0b" << std::bitset<8>(first).to_string() <<
                    std::endl;
    std::cout << "Second value: 0b" << std::bitset<8>(second).to_string() <<
                    std::endl;
    std::cout << "Result of AND operation: 0b" <<
                    std::bitset<8>(result).to_string() << std::endl;

    std::cout << std::endl;
}

void OperationOR()
{
    std::cout << "Example of OR operation" << std::endl;
    unsigned char first = 0b00111000;
    unsigned char second = 0b10101010;
    unsigned char result = first | second;

    std::cout << "First value: 0b" << std::bitset<8>(first).to_string() <<
                    std::endl;
    std::cout << "Second value: 0b" << std::bitset<8>(second).to_string() <<
                    std::endl;
    std::cout << "Result of OR operation: 0b" <<
                    std::bitset<8>(result).to_string() << std::endl;

    first = 0b11111000;
    second = 0b10101011;
    result = first | second;

    std::cout << std::endl << "With other values" << std::endl;
    std::cout << "First value: 0b" << std::bitset<8>(first).to_string() <<
                    std::endl;
    std::cout << "Second value: 0b" << std::bitset<8>(second).to_string() <<
                    std::endl;
    std::cout << "Result of OR operation: 0b" <<
                    std::bitset<8>(result).to_string() << std::endl;

    std::cout << std::endl;
}

// TODO: XOR operation
// TODO: bit reversing
// TODO: bit rotation
// TODO: number multiplication to 2
// TODO: number division by 2

void StartBM()
{
    Representation();
    OperationAND();
    OperationOR();
}

#endif /* BITSMANIPULATION_HPP_ */
