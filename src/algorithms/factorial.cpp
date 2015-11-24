#include "factorial.hpp"

#include <iostream>

unsigned long long int Factorial::Calc ( const int& num )
{
    if (num <= 0)
    {
        std::cout << "Invalid argument";
        return (0);
    }

    unsigned long long int factorial = 1;
    unsigned long long int number = static_cast<unsigned long long int>(num);
    for (unsigned long long int i = 1; i <= number; ++i)
    {
        factorial *= i;
    }

    return (factorial);
}


