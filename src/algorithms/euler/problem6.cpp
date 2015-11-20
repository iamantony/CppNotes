/*
 * problem6.cpp
 *
 *  Created on: Dec 26, 2013
 *      Author: Antony Cherepanov
 */

#include <iostream>

#include "problem6.h"

// Source: http://mathworld.wolfram.com/NicomachussTheorem.html

void Problem6::DoSolve()
{
	std::cout << "Problem 6" << std::endl;

	int diff = 0;
	for ( int i = 2; i <= 100; ++i )
	{
		diff += i * i * (i - 1);
	}

	std::cout << "Answer = " << diff << std::endl;
}

