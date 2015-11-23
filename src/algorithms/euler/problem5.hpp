#ifndef PROBLEM5_H_
#define PROBLEM5_H_

#include "problem.hpp"

// Problem 5:
// 2520 is the smallest number that can be divided by each of the numbers
// from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible
// by all of the numbers from 1 to 20?

class Problem5 : public Problem
{
    // == METHODS ==
private:
    virtual void DoSolve() override;
};

#endif /* PROBLEM5_H_ */
