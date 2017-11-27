#ifndef HAMMING_DISTANCE_HPP
#define HAMMING_DISTANCE_HPP

// https://leetcode.com/problems/hamming-distance/description/
// https://en.wikipedia.org/wiki/Hamming_distance

// The Hamming distance between two integers is the number of positions at
// which the corresponding bits are different.
// Given two integers x and y, calculate the Hamming distance.

#include <string>

namespace HammingDistance {
    class Solution {
    public:
        // Hamming distance for string is the number of different characters
        // at the same positions in two strings
        int HammingDistanceForStrings(const std::string& first,
                                      const std::string& second) {
            if (first.size() != second.size()) {
                return -1;
            }

            int result = 0;
            for (size_t i = 0; i < first.size(); ++i) {
                if (first[i] != second[i]) {
                    ++result;
                }
            }

            return result;
        }

        // Hamming distance for integers is the number of not equal bits
        int HammingDistanceForInts(const int& first, const int& second) {
            int result = 0;
            for (size_t offset = 0; offset < sizeof(int) * 8; ++offset) {
                result += ((first >> offset) & 1) ^ ((second >> offset) & 1);
            }

            return result;
        }
    };
}

#endif // HAMMING_DISTANCE_HPP
