#include "problem7.hpp"

#include <iostream>
#include <math.h>

#include "common/primenumbers.hpp"

void Problem7::DoSolve()
{
    std::cout << "Problem 7" << std::endl;

    const long unsigned int primeNumberNum = 10001;
    long unsigned int limit = FindLimitNumber(primeNumberNum);
    std::vector<long unsigned int> primals =
                    PrimeNumbers::GetPrimeNumbers(limit);

    if ( primals.size() < primeNumberNum )
    {
        std::cout << "Error - can't find prime number" << std::endl;
        return;
    }

    std::cout << "Answer = " << primals[primeNumberNum - 1] << std::endl;
}

long unsigned int Problem7::FindLimitNumber(const long unsigned int& t_primeNum)
{
    if ( t_primeNum <= 0 )
    {
        std::cout << "Error - invalid prime number" << std::endl;
        return (0);
    }

    const double numOfPrimes = static_cast<double>(t_primeNum);
    double foundLimit = 0.0;
    double iterator = 1.0;
    do
    {
        iterator += 1.0;
        foundLimit = iterator / log(iterator);
    }
    while ( foundLimit < numOfPrimes );

    long unsigned int limit = static_cast<long unsigned int>(
                    floor(iterator + 0.5));

    return (limit);
}
