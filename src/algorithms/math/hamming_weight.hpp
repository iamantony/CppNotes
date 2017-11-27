#ifndef HAMMING_WEIGHT_HPP
#define HAMMING_WEIGHT_HPP

// https://leetcode.com/problems/number-of-1-bits/description/
// https://en.wikipedia.org/wiki/Hamming_weight

// The Hamming weight of a string is the number of symbols that are different
// from the zero-symbol of the alphabet used. It is thus equivalent to the
// Hamming distance from the all-zero string of the same length.

// Write a function that takes an unsigned integer and returns the number of
// ’1' bits it has (also known as the Hamming weight).

// For example, the 32-bit integer ’11' has binary representation
// 0b00000000000000000000000000001011, so the function should return 3.

#include <string>

namespace HammingWeight {
    class Solution {
    public:
        int HammingWeightForString(const std::string& str) {
            int result = 0;
            for (size_t i = 0; i < str.size(); ++i) {
                if (str[i] != 0) {
                    ++result;
                }
            }

            return result;
        }

        int HammingWeightForInt(const int& value) {
            int result = 0;
            for (size_t offset = 0; offset < sizeof(int) * 8; ++offset) {
                result += (value >> offset) & 1;
            }

            return result;
        }
    };
}

#endif // HAMMING_WEIGHT_HPP
