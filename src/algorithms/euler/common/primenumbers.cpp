/*
 * primalnumbers.cpp
 *
 *  Created on: Dec 30, 2013
 *      Author: Antony Cherepanov
 */

#include <limits>

#include "primenumbers.h"

// Based on algorithm Seive of Eratosthenes
std::vector<long int> PrimeNumbers::GetPrimeNumbers(const long int &t_limit)
{
	long int limit = t_limit;
	if ( limit <= 0 )
	{
		limit = std::numeric_limits<long int>::max();
	}

	std::vector<bool> flags(limit, true);
	flags[0] = flags[1] = false;

	std::vector<long int> primals;

	for ( long int i = 0; i < limit; ++i )
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
		for ( long int j = i * i; j < limit; j += i )
		{
			flags[j] = false;
		}
	}

	return primals;
}
