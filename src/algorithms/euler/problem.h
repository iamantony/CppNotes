/*
 * problem.h
 *
 *  Created on: Dec 23, 2013
 *      Author: Antony Cherepanov
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

// Base class for problem classes
class Problem
{
	// == DATA ==

	// == METHODS ==
public:
	Problem();
	virtual ~Problem();

	void Solve();

private:
	virtual void DoSolve() = 0;
};

#endif /* PROBLEM_H_ */
