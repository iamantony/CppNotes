#ifndef GROUP_ANAGRAMS_HPP
#define GROUP_ANAGRAMS_HPP

/*
https://leetcode.com/problems/group-anagrams/
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

namespace Algo::DS::HashMap {
    class GroupAnagrams {
    public:
        static std::vector<std::vector<std::string>> group(const std::vector<std::string>& input) {
            std::unordered_map<std::string, std::vector<std::string>> group_map;
            for (const auto& str : input) {
                auto sorted_str = str;
                std::sort(sorted_str.begin(), sorted_str.end());

                const auto iter = group_map.find(sorted_str);
                if (iter == group_map.end()) {
                    group_map[sorted_str] = {str};
                }
                else {
                    iter->second.push_back(str);
                }
            }

            std::vector<std::vector<std::string>> result;
            for (auto& iter : group_map) { result.push_back(std::move(iter.second)); }

            return result;
        }
    };
}

#endif //GROUP_ANAGRAMS_HPP
