#ifndef MISSING_VALUE_HPP
#define MISSING_VALUE_HPP

/*
https://leetcode.com/problems/missing-number/description/
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it
using only constant extra space complexity?
*/

#include <vector>

namespace Algo::DS::Array {

class MissingElement {
public:
    static int Find(const std::vector<int>& nums) {
        int length = static_cast<int>(nums.size());

        // n * (n + 1) / 2 = 1 + 2 + 3 + ... + n
        int sum = length * (length + 1) / 2;
        for (const int& i : nums) {
            sum -= i;
        }

        return sum;
    }
};

}

#endif // MISSING_VALUE_HPP
