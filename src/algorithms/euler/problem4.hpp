#ifndef PROBLEM4_H_
#define PROBLEM4_H_

#include "problem.hpp"

// Problem 4:
// A palindromic number reads the same both ways. The largest palindrome
// made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

class Problem4 : public Problem
{
    // == METHODS ==
private:
    virtual void DoSolve();
    bool IsPalindrom(const int &t_number);
};

#endif /* PROBLEM4_H_ */
