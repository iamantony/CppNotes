/*
 * problem5.h
 *
 *  Created on: Dec 26, 2013
 *      Author: Antony Cherepanov
 */

#ifndef PROBLEM5_H_
#define PROBLEM5_H_

#include "problem.h"

// Problem 5:
// 2520 is the smallest number that can be divided by each of the numbers
// from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible
// by all of the numbers from 1 to 20?

class Problem5 : public Problem
{
	// == DATA ==

	// == METHODS ==
private:
	virtual void DoSolve();
};

#endif /* PROBLEM5_H_ */
