#include "problem10.hpp"

#include <iostream>
#include <vector>

#include "common/primenumbers.hpp"

void Problem10::DoSolve()
{
    std::cout << "Problem 10" << std::endl;

    const long unsigned int maxPrime = 2000000;
    std::vector<long unsigned int> primes =
                    PrimeNumbers::GetPrimeNumbers(maxPrime);

    long unsigned int sum = 0;
    for ( size_t i = 0; i < primes.size(); ++i )
    {
        sum += primes[i];
    }

    std::cout << "Answer = " << sum << std::endl;
}
