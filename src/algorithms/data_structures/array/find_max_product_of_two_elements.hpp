#ifndef FIND_MAX_PRODUCT_OF_TWO_ELEMENTS_HPP
#define FIND_MAX_PRODUCT_OF_TWO_ELEMENTS_HPP

/*
Coursera: Algorithmic Toolbox
Find the maximum product of two distinct numbers in a sequence of non-negative
integers.

Input: A sequence of non-negative integers.
Output: The maximum value that can be obtained by multiplying two different
elements from the sequence.
*/

#include <vector>
#include <algorithm>

namespace Algo::DS::Array {
class FindMaxProduct {
public:
    static long long Find(const std::vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        size_t max = 0, smax = 1;
        if (nums[max] < nums[smax]) {
            std::swap(max, smax);
        }

        for (size_t i = 2; i < nums.size(); ++i) {
            if (nums[max] < nums[i]) {
                smax = max;
                max = i;
            }
            else if (nums[smax] < nums[i])
            {
                smax = i;
            }
        }

        return static_cast<long long>(nums[max]) *
                static_cast<long long>(nums[smax]);
    }

    static long long FindNaive(std::vector<int> nums) {
        if (nums.size() < 2) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        return static_cast<long long>(nums[nums.size() - 1]) *
                static_cast<long long>(nums[nums.size() - 2]);
    }
};
}

#endif // FIND_MAX_PRODUCT_OF_TWO_ELEMENTS_HPP
