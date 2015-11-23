/*
 * problem7.cpp
 *
 *  Created on: Dec 27, 2013
 *      Author: Antony Cherepanov
 */

#include <iostream>
#include <math.h>

#include "problem7.h"
#include "algorithms/primenumbers.h"

void Problem7::DoSolve()
{
	std::cout << "Problem 7" << std::endl;

	const int primeNumberNum = 10001;
	int limit = FindLimitNumber(primeNumberNum);

	PrimeNumbers alg;
	std::vector<long int> primals = alg.GetPrimeNumbers( (long int)limit);

	if ( primals.size() < primeNumberNum )
	{
		std::cout << "Error - can't find prime number" << std::endl;
		return;
	}

	std::cout << "Answer = " << primals[primeNumberNum - 1] << std::endl;
}

int Problem7::FindLimitNumber(const int &t_primeNum)
{
	if ( t_primeNum <= 0 )
	{
		std::cout << "Error - invalid prime number number" << std::endl;
		return 0;
	}

	const double numOfPrimes = (double)t_primeNum;
	double foundLimit = 0.0;
	double iterator = 1.0;
	do
	{
		iterator += 1.0;
		foundLimit = iterator / log(iterator);
	}
	while ( foundLimit < numOfPrimes );

	int limit = (int)floor( iterator + 0.5 );

	return limit;
}
