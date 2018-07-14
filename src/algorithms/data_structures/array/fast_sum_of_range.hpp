#ifndef FAST_SUM_OF_RANGE_HPP
#define FAST_SUM_OF_RANGE_HPP

// https://leetcode.com/problems/range-sum-query-immutable/description/

/*
Given an integer array nums, find the sum of the elements between indices
i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

#include <vector>
#include <map>

namespace Algo::DS::Array {

class NumArray {
public:
    NumArray(const std::vector<int>& nums) {
        m_sums.resize(nums.size());
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            m_sums[i] = sum + nums[i];
            sum = m_sums[i];
        }
    }

    int sumRange(const int& i, const int& j) {
        if (m_sums.size() == 0 || i < 0 || j < i ) {
            return 0;
        }

        size_t ii = static_cast<size_t>(i);
        size_t jj = static_cast<size_t>(j);
        if (ii >= m_sums.size() || jj >= m_sums.size()) {
            return 0;
        }

        return (0 == ii) ? m_sums[jj] : m_sums[jj] - m_sums[ii - 1];
    }

private:
    std::vector<int> m_sums;
};

}

#endif // FAST_SUM_OF_RANGE_HPP
