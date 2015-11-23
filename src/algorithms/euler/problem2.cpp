#include "problem2.hpp"

#include <iostream>
#include <vector>

void Problem2::DoSolve()
{
    std::cout << "Problem 2" << std::endl;

    // Create Fibonacci sequence
    std::vector<size_t> fibNums;
    fibNums.push_back(1);
    fibNums.push_back(2);

    size_t newNum = fibNums[0] + fibNums[1];
    do
    {
        fibNums.push_back(newNum);

        size_t lastInd = fibNums.size() - 1;
        newNum = fibNums[lastInd] + fibNums[lastInd - 1];
    }
    while (newNum < 4000000);

    // Summ even numbers
    size_t summ = 0;
    for ( size_t i = 0; i < fibNums.size(); ++i )
    {
        if (0 == fibNums[i] % 2)
        {
            summ += fibNums[i];
        }
    }

    std::cout << "Answer = " << summ << std::endl;
}
