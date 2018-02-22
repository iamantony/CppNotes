#ifndef REVERSE_INTEGER_HPP
#define REVERSE_INTEGER_HPP

// https://leetcode.com/problems/reverse-integer/description/

// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:
// Input: 123
// Output:  321

// Example 2:
// Input: -123
// Output: -321

// Example 3:
// Input: 120
// Output: 21

// Note:
// Assume we are dealing with an environment which could only hold integers
// within the 32-bit signed integer range. For the purpose of this problem,
// assume that your function returns 0 when the reversed integer overflows.

#include <string>

#include "../strings/str_reverse.hpp"

namespace ReverseInteger {

class Solution {
public:
    int reverse(int x) {
        if ( x < 10 && x > -10 ) {
            return x;
        }

        int sign = (x > 0) ? 1 : -1;
        std::string number = std::to_string(std::abs(x));

        ReverseStr::Solution revSolution;
        std::string reversedNumber = revSolution.reverseString(number);

        try {
            int result = sign * std::stoi(reversedNumber);
            return result;
        }
        catch(...) {
            return 0;
        }

        return 0;
    }
};

}

#endif // REVERSE_INTEGER_HPP
