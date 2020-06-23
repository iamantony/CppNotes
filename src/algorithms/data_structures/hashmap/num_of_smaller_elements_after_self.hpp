#ifndef NUM_OF_SMALLER_ELEMENTS_AFTER_SELF_HPP
#define NUM_OF_SMALLER_ELEMENTS_AFTER_SELF_HPP

/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
You are given an integer array nums and you have to return a new counts array. The counts array has
the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:
Input: [5,2,6,1]
Output: [2,1,1,0]

Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/

#include "types/ds/fenwick_tree.hpp"
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

namespace Algo::DS::HashMap {
    class NumOfSmallerElementsAfterSelf {
    public:
        static std::vector<int> count_with_map(const std::vector<int>& nums) {
            if (nums.empty()) { return {}; }

            std::map<int, size_t> count_map;
            std::vector<int> result(nums.size(), 0);
            for (auto i = nums.size() - 1; ; --i) {
                auto elem_iter = count_map.find(nums[i]);
                if (elem_iter == count_map.end()) {
                    const auto [new_iter, _] = count_map.insert({nums[i], 1});
                    elem_iter = new_iter;
                }
                else {
                    elem_iter->second += 1;
                }

                for (auto iter = count_map.begin(); iter != elem_iter; ++iter) {
                    result[i] += static_cast<int>(iter->second);
                }

                if (i == 0) { break; }
            }

            return result;
        }

        static std::vector<int> count_with_sorting(const std::vector<int>& nums) {
            if (nums.empty()) { return {}; }

            auto input = nums;
            std::vector<int> result(nums.size(), 0);
            for (auto i = input.size() - 1; ; --i) {
                const auto value = input[i];
                auto iter = input.begin() + static_cast<long>(i);
                std::inplace_merge(iter, iter + 1, input.end());
                auto value_iter = std::lower_bound(iter, input.end(), value);
                result[i] = static_cast<int>(std::distance(iter, value_iter));

                if (i == 0) { break; }
            }

            return result;
        }

        static std::vector<int> count_with_fenwick_tree(const std::vector<int>& nums) {
            if (nums.empty()) { return {}; }

            std::unordered_map<int, int> m;
            size_t rank = 0;
            {
                std::set<int> unique_nums(nums.begin(), nums.end());
                for(auto& x : unique_nums) {
                    m[x] = static_cast<int>(rank);
                    ++rank;
                }
            }

            Types::DS::FenwickTree<int> ft(rank);
            std::vector<int> ans;
            for(size_t i = nums.size() - 1; ; --i) {
                const auto num_rank = m[nums[i]] - 1;
                if (num_rank < 0) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(ft.prefix_sum(static_cast<size_t>(num_rank)));
                }

                ft.add(static_cast<size_t>(m[nums[i]]), 1);

                if (i == 0) { break; }
            }

            reverse(ans.begin(),ans.end());
            return ans;
        }
    };
}

#endif //NUM_OF_SMALLER_ELEMENTS_AFTER_SELF_HPP
