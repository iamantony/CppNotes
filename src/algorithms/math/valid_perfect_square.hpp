#ifndef VALID_PERFECT_SQUARE_HPP
#define VALID_PERFECT_SQUARE_HPP

// https://leetcode.com/problems/valid-perfect-square/description/
// Given a positive integer num, write a function which returns True if num is
// a perfect square else False.
// Note: Do not use any built-in library function such as sqrt.

// Example 1:
// Input: 16
// Returns: True

// Example 2:
// Input: 14
// Returns: False

#include "algorithms/math/square_root.hpp"
#include "common/equality.hpp"

namespace ValidPerfectSquare {

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) {
            return false;
        }

        double root = SquareRoot::BabylonialSR(num, 0.00001);
        return equalDoubles(root, std::floor(root), 0.00001);
    }
};

}

#endif // VALID_PERFECT_SQUARE_HPP
