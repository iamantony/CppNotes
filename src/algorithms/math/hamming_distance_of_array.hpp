#ifndef HAMMING_DISTANCE_OF_ARRAY_HPP
#define HAMMING_DISTANCE_OF_ARRAY_HPP

// https://leetcode.com/problems/total-hamming-distance/description/

// The Hamming distance between two integers is the number of positions at
// which the corresponding bits are different.
// Now your job is to find the total Hamming distance between all pairs of the
// given numbers.

// Example:
// Input: 4, 14, 2
// Output: 6

// Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is
// 0010 (just showing the four bits relevant in this case). So the answer
// will be:
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) =
// 2 + 2 + 2 = 6.

#include <vector>
#include <set>

#include "algorithms/math/hamming_distance.hpp"

namespace HammingDistanceOfArray {

class Solution {
public:
    int totalHammingDistance(const std::vector<int>& nums) {
        int result = 0;
        if (nums.size() <= 1) {
            return result;
        }

        std::set<int> uniqueElements(nums.begin(), nums.end());
        std::vector<int> resultNums(uniqueElements.begin(), uniqueElements.end());

        HammingDistance::Solution hd;
        for (size_t i = 0; i < resultNums.size() - 1; ++i ) {
            for (size_t j = i + 1; j < resultNums.size(); ++j) {
                result += hd.HammingDistanceForIntsFast(resultNums.at(i), resultNums.at(j));
            }
        }

        return result;
    }
};

}

#endif // HAMMING_DISTANCE_OF_ARRAY_HPP
