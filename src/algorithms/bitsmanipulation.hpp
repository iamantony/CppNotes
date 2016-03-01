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

    std::cout << std::bitset<8>(first).to_string() << " & " <<
                    std::bitset<8>(second).to_string() << " = " <<
                    std::bitset<8>(first & second).to_string() <<
                    std::endl;

    first = 0b11111000;
    second = 0b10101011;

    std::cout << std::bitset<8>(first).to_string() << " & " <<
                        std::bitset<8>(second).to_string() << " = " <<
                        std::bitset<8>(first & second).to_string() <<
                        std::endl;

    std::cout << std::endl;
}

void OperationOR()
{
    std::cout << "Example of OR operation" << std::endl;
    unsigned char first = 0b00111000;
    unsigned char second = 0b10101010;

    std::cout << std::bitset<8>(first).to_string() << " | " <<
                        std::bitset<8>(second).to_string() << " = " <<
                        std::bitset<8>(first | second).to_string() <<
                        std::endl;

    first = 0b11111000;
    second = 0b10101011;

    std::cout << std::bitset<8>(first).to_string() << " | " <<
                        std::bitset<8>(second).to_string() << " = " <<
                        std::bitset<8>(first | second).to_string() <<
                        std::endl;

    std::cout << std::endl;
}

void OperationXOR()
{
    std::cout << "Example of XOR operation" << std::endl;
    unsigned char first = 0b00111000;
    unsigned char second = 0b10101010;

    std::cout << std::bitset<8>(first).to_string() << " ^ " <<
                        std::bitset<8>(second).to_string() << " = " <<
                        std::bitset<8>(first ^ second).to_string() <<
                        std::endl;

    first = 0b11111000;
    second = 0b10101011;

    std::cout << std::bitset<8>(first).to_string() << " ^ " <<
                        std::bitset<8>(second).to_string() << " = " <<
                        std::bitset<8>(first ^ second).to_string() <<
                        std::endl;

    std::cout << "Byte complementation using XOR operation" << std::endl;
    first = 0b11111111;
    std::cout << std::bitset<8>(first).to_string() << " ^ " <<
                            std::bitset<8>(second).to_string() << " = " <<
                            std::bitset<8>(first ^ second).to_string() <<
                            std::endl;

    std::cout << std::endl;
}

void Reverse()
{
    std::cout << "Byte reverse operation" << std::endl;
    const unsigned char original = 0b00110010;

    unsigned char value = original;
    unsigned char result = 0;
    const int max = std::numeric_limits<unsigned char>::digits - 1;
    for (int i = 0; i < max; ++i)
    {
       if (value & 0x01)
       {
          result |= 0x01;
       }

       value = static_cast<unsigned char>(value >> 1);
       result = static_cast<unsigned char>(result << 1);
    }

    std::cout << std::bitset<8>(original).to_string() << " -> " <<
                    std::bitset<8>(result).to_string() << std::endl;

    std::cout << std::endl;
}

// TODO: bit rotation
// TODO: number multiplication to 2
// TODO: number division by 2

void StartBM()
{
    Representation();
    OperationAND();
    OperationOR();
    OperationXOR();
    Reverse();
}

#endif /* BITSMANIPULATION_HPP_ */
