#include "primenumbers.hpp"

#include <cstddef>
#include <limits>

// Based on algorithm Seive of Eratosthenes
std::vector<long unsigned int> PrimeNumbers::GetPrimeNumbers(
                const long unsigned int &t_limit)
{
    long unsigned int limit = t_limit <= 2 ?
                    std::numeric_limits<long unsigned int>::max() : t_limit;

    std::vector<bool> flags(limit, true);
    flags[0] = flags[1] = false;

    std::vector<long unsigned int> primals;
    for ( long unsigned int i = 0; i < limit; ++i )
    {
        // Skip crossed out numbers
        if ( false == flags[i] )
        {
            continue;
        }

        // If number have not crossed out, then it is a prime number
        primals.push_back(i);

        // Start from i^2 because numbers between i and i^2 already
        // have crossed out by other primes
        for ( long unsigned int j = i * i; j < limit; j += i )
        {
            flags[j] = false;
        }
    }

    return (primals);
}
