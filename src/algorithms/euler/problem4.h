/*
 * problem4.h
 *
 *  Created on: Dec 25, 2013
 *      Author: Antony Cherepanov
 */

#ifndef PROBLEM4_H_
#define PROBLEM4_H_

#include "problem.h"

// Problem 4:
// A palindromic number reads the same both ways. The largest palindrome
// made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

class Problem4 : public Problem
{
	// == DATA ==

	// == METHODS ==
private:
	virtual void DoSolve();
	bool IsPalindrom(const int &t_number);
};

#endif /* PROBLEM4_H_ */
