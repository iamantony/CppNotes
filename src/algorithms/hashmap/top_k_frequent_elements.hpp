#ifndef TOP_K_FREQUENT_ELEMENTS_HPP
#define TOP_K_FREQUENT_ELEMENTS_HPP

/*
https://leetcode.com/problems/top-k-frequent-elements/
Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

namespace Algo::HashMap {
    class TopFrequentElements {
    public:
        static std::vector<int> find_with_sorting(std::vector<int> nums, const int k) {
            if (nums.empty() || k <= 0) { return {}; }

            std::sort(nums.begin(), nums.end());

            const auto kk = static_cast<size_t>(k);
            std::multimap<size_t, int> frequency;
            auto iter = nums.begin();
            while (iter != nums.end()) {
                auto next_iter = std::upper_bound(iter, nums.end(), *iter);
                const auto count = std::distance(iter, next_iter);
                frequency.insert({count, *iter});
                iter = next_iter;

                if (frequency.size() > kk) {
                    frequency.erase(frequency.begin());
                }
            }

            std::vector<int> result;
            for (const auto& [_, number] : frequency) { result.push_back(number); }

            std::sort(result.begin(), result.end());
            return result;
        }

        static std::vector<int> find_with_two_maps(std::vector<int> nums, int k) {
            if (nums.empty() || k <= 0) { return {}; }

            std::unordered_map<int, size_t> num_freq_map;
            for(const auto& i : nums){
                num_freq_map[i]++;
            }

            std::map<size_t, std::vector<int>, std::greater<size_t>> freq_num_map;
            for(const auto& [i, freq] : num_freq_map) {
                freq_num_map[freq].push_back(i);
            }

            std::vector<int> result;
            for(const auto& [freq, v] : freq_num_map) {
                if(k == 0) { break; }

                for(const auto& i : v) {
                    if(k == 0) { break; }

                    result.push_back(i);
                    --k;
                }
            }

            std::sort(result.begin(), result.end());
            return result;
        }
    };
}


#endif //TOP_K_FREQUENT_ELEMENTS_HPP
