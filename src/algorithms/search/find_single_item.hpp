#ifndef FIND_SINGLE_ITEM_HPP
#define FIND_SINGLE_ITEM_HPP

// https://leetcode.com/problems/single-number/description/
// Given an array of integers, every element appears twice except for one.
// Find that single one.
// Note: Your algorithm should have a linear runtime complexity. Could you
// implement it without using extra memory?

#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

namespace FindSingleItem {

class Solution {
public:
    int singleNumberHash(const std::vector<int>& nums) {
        std::unordered_map<int, int> numbers;
        for (const int& value : nums) {
            if (numbers.count(value) > 0) {
                numbers.erase(value);
            }
            else {
                numbers[value] = 1;
            }
        }

        if (numbers.size() != 1) {
            return -1;
        }

        return numbers.begin()->first;
    }

    // Concept:
    // 2 * (a + b + c) - (a + a + b + b + c) = c2∗(a+b+c)−(a+a+b+b+c)=c
    int singleNumberMath(const std::vector<int>& nums) {
        std::set<int> numbers(nums.begin(), nums.end());
        return 2 * std::accumulate(numbers.begin(), numbers.end(), 0) -
                std::accumulate(nums.begin(), nums.end(), 0);
    }

    // Concept
    // - If we take XOR of zero and some bit, it will return that bit
    //   a ^ 0 = a
    // - If we take XOR of two same bits, it will return 0
    //   a ^ a = 0
    // - a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b
    // So we can XOR all bits together to find the unique number.
    int singleNumberBitManipulation(const std::vector<int>& nums) {
        int result = 0;
        for (const int& value : nums) {
            result ^= value;
        }

        return result;
    }
};

}

#endif // FIND_SINGLE_ITEM_HPP
