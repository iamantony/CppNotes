#ifndef FIND_FOUR_SUM_HPP
#define FIND_FOUR_SUM_HPP

/*
https://leetcode.com/problems/4sum/
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in
nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives
the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <map>
#include <vector>
#include <algorithm>

namespace Algo::Search {
    class Find4Sum {
        std::vector<int> m_input;
        std::set<std::vector<int>> m_result;

        void find_two_sum(const size_t ind1, const size_t ind2, size_t start_index, const int target)
        {
            size_t end_index = m_input.size() - 1;
            while (start_index < end_index) {
                const auto sum = m_input[start_index] + m_input[end_index];
                if (sum == target) {
                    add_to_result(ind1, ind2, start_index, end_index);
                    ++start_index;
                    --end_index;
                }
                else if (sum > target) {
                    --end_index;
                }
                else {
                    ++start_index;
                }
            }
        }

        void add_to_result(size_t ind1, size_t ind2, size_t ind3, size_t ind4) {
            std::vector<int> nums = {m_input[ind1], m_input[ind2], m_input[ind3], m_input[ind4]};
            std::sort(nums.begin(), nums.end());
            m_result.insert(nums);
        }

        std::vector<std::vector<int>> convert_result() const {
            return std::vector<std::vector<int>>(m_result.begin(), m_result.end());
        }

    public:
        std::vector<std::vector<int>> find(const std::vector<int>& v, const int target) {
            if (v.size() < 4) { return {}; }

            m_input = v;
            std::sort(m_input.begin(), m_input.end());

            for (size_t i = 0; i < m_input.size() - 3; ++i) {
                if (i != 0 && m_input[i] == m_input[i - 1]) { continue; }

                for (size_t j = i + 1; j < m_input.size() - 2; ++j) {
                    if (j != i + 1 && m_input[j] == m_input[j - 1]) { continue; }

                    const auto new_target = target - m_input[i] - m_input[j];
                    find_two_sum(i, j, j + 1, new_target);
                }
            }

            return convert_result();
        }
    };
}

#endif //FIND_FOUR_SUM_HPP
