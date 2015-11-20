/*
 * problem5.cpp
 *
 *  Created on: Dec 26, 2013
 *      Author: Antony Cherepanov
 */

#include <iostream>
#include <limits>
#include <vector>

#include "problem5.h"

void Problem5::DoSolve()
{
	std::cout << "Problem 5" << std::endl;

	int numbers[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	std::vector<int> dividers(numbers, numbers + sizeof(numbers) / sizeof(int));

	int foundNumber = 0;
	for ( int i = 40; i < std::numeric_limits<int>::max(); ++i )
	{
		bool numFound = true;
		for ( size_t j = 0; j < dividers.size(); ++j )
		{
			if ( 0 != i % dividers[j] )
			{
				numFound = false;
				break;
			}
		}

		if ( true == numFound )
		{
			foundNumber = i;
			break;
		}
	}

	std::cout << "Answer = " << foundNumber << std::endl;
}

