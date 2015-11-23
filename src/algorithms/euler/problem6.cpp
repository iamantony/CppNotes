#include "problem6.hpp"

#include <iostream>

// Source: http://mathworld.wolfram.com/NicomachussTheorem.html

void Problem6::DoSolve()
{
    std::cout << "Problem 6" << std::endl;

    int diff = 0;
    for ( int i = 2; i <= 100; ++i )
    {
        diff += i * i * (i - 1);
    }

    std::cout << "Answer = " << diff << std::endl;
}

