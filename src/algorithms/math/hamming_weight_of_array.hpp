#ifndef HAMMING_WEIGHT_OF_ARRAY_HPP
#define HAMMING_WEIGHT_OF_ARRAY_HPP

// https://leetcode.com/problems/counting-bits/description/
// Given a non negative integer number num. For every numbers i in the
// range 0 ≤ i ≤ num calculate the number of 1's in their binary representation
// and return them as an array.

// Example:
// For num = 5 you should return [0,1,1,2,1,2].

// Follow up:
// - It is very easy to come up with a solution with run time
//    O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in
//    a single pass?
// - Space complexity should be O(n).
// - Can you do it like a boss? Do it without using any builtin function like
//    __builtin_popcount in c++ or in any other language.

#include <vector>

#include "algorithms/math/hamming_distance.hpp"

namespace HammingWeightOfArray {

class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> result;
        HammingDistance::Solution hd;
        for (int i = 0; i <= num; ++i) {
            result.push_back(hd.HammingDistanceForIntsFast(i, 0));
        }

        return result;
    }
};

}

#endif // HAMMING_WEIGHT_OF_ARRAY_HPP
