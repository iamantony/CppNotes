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

#include <vector>
#include <limits>

namespace Algo::Math {

class ReverseInteger {
public:
    static int Reverse(int x) {
        long result = 0;
        while(x != 0) {
            result = result * 10 + x % 10;
            if (result > std::numeric_limits<int>::max() ||
                result < std::numeric_limits<int>::min()) {
                return 0;
            }

            x /= 10;
        }

        return static_cast<int>(result);
    }
};

}

#endif // REVERSE_INTEGER_HPP
