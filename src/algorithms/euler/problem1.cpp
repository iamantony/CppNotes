#include "problem1.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

void Problem1::DoSolve()
{
    std::cout << "Problem 1" << std::endl;

    std::vector<int> numbers;
    for (int i = 3; i < 1000; i += 3)
    {
        numbers.push_back( i );
    }

    for (int i = 5; i < 1000; i += 5)
    {
        numbers.push_back( i );
    }

    std::sort( numbers.begin(), numbers.end() );
    std::vector<int>::iterator last = unique( numbers.begin(), numbers.end() );

    int summ = 0;
    for (std::vector<int>::iterator it = numbers.begin(); it != last; ++it)
    {
        summ += *it;
    }

    std::cout << "Answer = " << summ << std::endl;
}

