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

namespace Algo::Math {

class ReverseInteger {
public:
    static int Reverse(int x) {
        if ( x < 10 && x > -10 ) {
            return x;
        }

        int sign = (x > 0) ? 1 : -1;
        x = std::abs(x);

        std::vector<int> nums;
        while(x != 0) {
            nums.push_back(x % 10);
            x /= 10;
        }

        int result = 0;
        for (const int& num : nums) {
            result = result * 10 + num;

            // Check if we have integer overflow
            if (result < 0) {
                return 0;
            }
        }

        return result * sign;
    }
};

}

#endif // REVERSE_INTEGER_HPP
