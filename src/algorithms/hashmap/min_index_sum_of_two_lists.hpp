#ifndef MIN_INDEX_SUM_OF_TWO_LISTS_HPP
#define MIN_INDEX_SUM_OF_TWO_LISTS_HPP

/*
https://leetcode.com/problems/minimum-index-sum-of-two-lists/
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of
favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a
choice tie between answers, output all of them with no order requirement. You could assume there
always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".

Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/

#include <string>
#include <vector>
#include <unordered_map>

namespace Algo::HashMap {
    class MinIndexSum {
    public:
        static std::vector<std::string> find(
            const std::vector<std::string>& v1, const std::vector<std::string>& v2)
        {
            if (v1.empty() || v2.empty()) { return {}; }

            const auto& small_list = v1.size() > v2.size() ? v2 : v1;
            const auto& big_list = v1.size() > v2.size() ? v1 : v2;
            std::unordered_map<std::string, size_t> search_map;
            for (size_t i = 0; i < small_list.size(); ++i) {
                search_map.insert({small_list[i], i});
            }

            std::vector<std::string> result;
            size_t min_index_sum = v1.size() + v2.size();
            for (size_t i = 0; i < big_list.size(); ++i) {
                const auto iter = search_map.find(big_list[i]);
                if (iter == search_map.end()) { continue; }

                const auto index_sum = i + iter->second;
                if (index_sum < min_index_sum) {
                    min_index_sum = index_sum;
                    result.clear();
                    result.push_back(iter->first);
                }
                else if (index_sum == min_index_sum) {
                    result.push_back(iter->first);
                }
            }

            return result;
        }
    };
}

#endif //MIN_INDEX_SUM_OF_TWO_LISTS_HPP
