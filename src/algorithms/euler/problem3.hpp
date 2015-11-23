/*
 * problem3.h
 *
 *  Created on: Dec 23, 2013
 *      Author: Antony Cherepanov
 */

#ifndef PROBLEM3_H_
#define PROBLEM3_H_

#include <vector>
#include "problem.h"

// Problem 3:
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

class Problem3 : public Problem
{
	// == DATA ==

	// == METHODS ==
private:
	virtual void DoSolve();
	std::vector<long int> GetPrimalNumbers(const long int &t_limit = 0);
};

#endif /* PROBLEM3_H_ */
