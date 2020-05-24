#ifndef PRIMES_HPP_
#define PRIMES_HPP_

#include <vector>
#include <cmath>
#include <algorithm>

namespace Algo::Math {
    template<typename T>
    std::vector<T> GetPrimesNaive(const T& limit)
    {
        if (limit < 2)
        {
            return std::vector<T>();
        }
        else if (2 == limit)
        {
            return std::vector<T>(1, 2);
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

    template<typename T>
    std::vector<T> GetPrimesImproved(const T& limit)
    {
        if (limit < 2)
        {
            return std::vector<T>();
        }
        else if (2 == limit)
        {
            return std::vector<T>(1, 2);
        }

        std::vector<T> primes;
        for (T i = 2; i < limit; ++i)
        {
            bool isPrime = true;
            long double ldLimit = static_cast<long double>(i);
            T newLimit = static_cast<T>(std::floor(std::sqrt(ldLimit)));
            for (T j = 2; j <= newLimit; ++j)
            {
                if (i % j == 0)
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

    // Seive of Eratosthenes
    template<typename T>
    std::vector<T> GetPrimesSeive(const T& limit)
    {
        if (limit < 2)
        {
            return std::vector<T>();
        }
        else if (2 == limit)
        {
            return std::vector<T>(1, 2);
        }

        size_t numOfValues = static_cast<size_t>(limit);
        std::vector<bool> flags(numOfValues, true);
        flags[0] = false;
        flags[1] = false;

        size_t prime = 2;
        long double ldLimit = static_cast<long double>(limit);
        size_t newLimit = static_cast<size_t>(std::floor(std::sqrt(ldLimit)));
        while(prime <= newLimit)
        {
            // Cross out elements
            for (size_t i = prime * prime; i < flags.size(); i += prime)
            {
                flags[i] = false;
            }

            // Find first not cross out element - next prime number
            size_t next = prime + 1;
            while(next < flags.size() && false == flags[next])
            {
                ++next;
            }

            prime = next;
        }

        // Collect prime numbers
        std::vector<T> primes;
        for (size_t i = 0; i < flags.size(); ++i)
        {
            if (flags[i])
            {
                primes.push_back(static_cast<T>(i));
            }
        }

        return primes;
    }

    template <typename T>
    T GetNextPrime(const T& start_value) {
        if (start_value < 2) { return {}; }

        auto result = start_value;
        auto prime_limit = start_value;
        while (result <= start_value) {
            prime_limit += start_value / 2;
            const auto primes = GetPrimesSeive(prime_limit);
            result = primes.back();
        }

        return result;
    }
}

#endif /* PRIMES_HPP_ */
