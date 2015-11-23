/*
 * problem9.cpp
 *
 *  Created on: Jan 4, 2014
 *      Author: Antony Cherepanov
 */

#include <iostream>

#include "problem9.h"

void Problem9::DoSolve()
{
	std::cout << "Problem 9" << std::endl;

	// http://en.wikipedia.org/wiki/Pythagorean_triple
	// Euclid formula:
	// a = n^2 - m^2
	// b = 2nm
	// c = n^2 + m^2

	// a + b + c = n^2 - m^2 + 2nm + n^2 + m^2 = 2n^2 + 2nm = 1000
	// n^2 + nm = 500
	// n(n + m) = 500

	// Let n = 20, then m = 5 and a = 375, b = 200, c = 425
	// Check:
	// 375 + 200 + 425 == 1000
	// 375^2 + 200^2 = 140625 + 40000 = 180625 == 425^2

	std::cout << "Answer = " << 375 * 200 * 425 << std::endl;
}
