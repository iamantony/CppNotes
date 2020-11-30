#ifndef CPPNOTESMAIN_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP
#define CPPNOTESMAIN_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP

/*
https://leetcode.com/problems/product-of-array-except-self/
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal
to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array
(including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra
space for the purpose of space complexity analysis.)
*/

#include <vector>

namespace Algo::DS::Array {
    class ProductOfArrayExceptSelf {
    public:
        static std::vector<int> calc(std::vector<int> nums) {
            if (nums.empty()) { return {}; }
            if (nums.size() == 1) { return nums; }

            std::vector<int> prefixes(nums.size(), 1);
            prefixes[nums.size() - 1] = nums.back();
            for (size_t i = nums.size() - 2; i >= 0; --i) {
                prefixes[i] = nums[i] * prefixes[i+1];
                if (i == 0) { break; }
            }

            for (size_t i = 1; i < nums.size(); ++i) {
                nums[i] = nums[i] * nums[i-1];
            }

            for (size_t i = 0; i < nums.size(); ++i) {
                int suf = 1;
                if (i > 0) { suf = nums[i-1]; }

                int pref = 1;
                if (i < nums.size() - 1) { pref = prefixes[i+1]; }

                prefixes[i] = suf * pref;
            }

            return prefixes;
        }
    };
}

#endif //CPPNOTESMAIN_PRODUCT_OF_ARRAY_EXCEPT_SELF_HPP
