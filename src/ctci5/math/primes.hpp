#ifndef PRIMES_HPP_
#define PRIMES_HPP_

#include <vector>

template<typename T>
std::vector<T> GetPrimesNaive(const T& limit)
{
    if (limit < 2)
    {
        return std::vector<T>();
    }

    std::vector<T> primes;
    for (T i = 2; i < limit; ++i)
    {
        bool isPrime = true;
        for (T j = 2; j < i; ++j)
        {
            if (i % j == 0 && i != j)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            primes.push_back(i);
        }
    }

    return primes;
}

#endif /* PRIMES_HPP_ */
