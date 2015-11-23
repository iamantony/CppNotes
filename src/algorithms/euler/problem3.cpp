/*
 * problem3.cpp
 *
 *  Created on: Dec 23, 2013
 *      Author: Antony Cherepanov
 */

#include <iostream>
#include <limits>
#include <math.h>

#include "problem3.h"

void Problem3::DoSolve()
{
	std::cout << "Problem 3" << std::endl;

	long int number = 600851475143;
	long int numSqrt = (long int)floor( sqrt((double)number) + 0.5);
	std::vector<long int> primalNumbers = GetPrimalNumbers(numSqrt);

	long int lastPrimal = 0;
	const long int numOfPrimes = primalNumbers.size();
	for ( long int i = 0; i < numOfPrimes; ++i )
	{
		if ( 0 == number % primalNumbers[i] )
		{
			lastPrimal = primalNumbers[i];
		}
	}

	std::cout << "Answer = " << lastPrimal << std::endl;
}

std::vector<long int> Problem3::GetPrimalNumbers(const long int &t_limit)
{
	long int limit = t_limit;
	if ( limit <= 0 )
	{
		limit = std::numeric_limits<long int>::max();
	}

	std::vector<char> flags(limit, 1);
	flags[0] = flags[1] = 0;

	std::vector<long int> primals;

	for ( long int i = 0; i < limit; ++i )
	{
		if ( 0 == flags[i] )
		{
			continue;
		}

		primals.push_back(i);

		for ( long int j = i + i; j < limit; j += i )
		{
			flags[j] = 0;
		}
	}

	return primals;
}
