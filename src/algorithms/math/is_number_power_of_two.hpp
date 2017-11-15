#ifndef IS_NUMBER_POWER_OF_TWO_HPP
#define IS_NUMBER_POWER_OF_TWO_HPP

// https://leetcode.com/problems/power-of-two/description/
// Check if number if power of two

// How we represent in bits number that is power of two:
// 2 - 0b10
// 4 - 0b100
// 8 - 0b100
// 16 - 0b1000
// .......
// All these numbers have only one bit set to '1'.

// How we represent int bits number that is equals to
// (number_of_power_of_two - 1):
// 1 - 0b1
// 3 - 0b11
// 7 - 0b111
// 15 - 0b1111
// .......

// Result of operation x & (x - 1) where x is a number of power of two:
// x = 4
// 4 & (4 - 1) = 4 & 3 =
// 0b100 & 0b011 =
// 1 & 0 = 0, 0 & 1 = 0, 0 & 1 = 0 -> 0b0 = 0

// Result of operation x & (x - 1) where x IS NOT a number of power of two:
// x = 6
// 6 & (6 - 1) = 6 & 5 =
// 0b110 & 0b101 =
// 1 & 1 = 1, 1 & 0 = 0, 0 & 1 = 0 -> 0b100 = 4

namespace NumberPowerOfTwo {

class Solution {
public:
    bool isPowerOfTwo(const int& number) {
        if (n <= 0) {
            return false;
        }
        
        bool result = (number & (number - 1)) == 0;
        return result;
    }
};

}

#endif // IS_NUMBER_POWER_OF_TWO_HPP
