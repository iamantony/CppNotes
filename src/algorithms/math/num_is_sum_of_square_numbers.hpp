#ifndef NUM_IS_SUM_OF_SQUARE_NUMBERS_HPP
#define NUM_IS_SUM_OF_SQUARE_NUMBERS_HPP

// https://leetcode.com/problems/sum-of-square-numbers/description/
// Given a non-negative integer c, your task is to decide whether there're two
// integers a and b such that a^2 + b^2 = c.

// Example 1:
// Input: 5
// Output: True
// Explanation: 1 * 1 + 2 * 2 = 5

// Example 2:
// Input: 3
// Output: False

#include "algorithms/math/valid_perfect_square.hpp"

namespace SumOfSquares {

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) {
            return false;
        }
        else if (c <= 1) {
            return true;
        }

        ValidPerfectSquare::Solution validator;
        if (validator.isPerfectSquare(c)) {
            return true;
        }

        const int half = c / 2;
        for (int a = 1; a <= half; ++a) {
            int a2 = a * a;
            int secondSquare = c - a2;
            if (secondSquare <= 0) {
                return false;
            }

            if (a2 == secondSquare ||
                validator.isPerfectSquare(secondSquare)) {
                return true;
            }
        }

        return false;
    }
};

}

#endif // NUM_IS_SUM_OF_SQUARE_NUMBERS_HPP
