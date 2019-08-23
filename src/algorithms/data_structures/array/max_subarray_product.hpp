#ifndef MAX_SUBARRAY_PRODUCT_HPP
#define MAX_SUBARRAY_PRODUCT_HPP

// https://leetcode.com/problems/maximum-product-subarray/description/

/*
Given an integer array nums, find the contiguous subarray within an array
(containing at least one number) which has the largest product.

Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <vector>

namespace Algo::DS::Array {
class MaxSubarrayProduct {
public:
    static int Calc(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int minProd = nums[0], maxProd = nums[0], result = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                std::swap(minProd, maxProd);
            }

            minProd = std::min(nums[i], minProd * nums[i]);
            maxProd = std::max(nums[i], maxProd * nums[i]);
            result = std::max(result, std::max(minProd, maxProd));
        }

        return result;
    }
};

}

#endif // MAX_SUBARRAY_PRODUCT_HPP
