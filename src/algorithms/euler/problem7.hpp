#ifndef PROBLEM7_H_
#define PROBLEM7_H_

#include "problem.hpp"

// Problem 7:
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
// that the 6th prime is 13.
// What is the 10 001st prime number?

class Problem7 : public Problem
{
    // == METHODS ==
private:
    virtual void DoSolve() override;
    long unsigned int FindLimitNumber(const long unsigned int& t_primeNum);
};

#endif /* PROBLEM7_H_ */
