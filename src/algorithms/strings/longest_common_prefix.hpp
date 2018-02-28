#ifndef LONGEST_COMMON_PREFIX_HPP
#define LONGEST_COMMON_PREFIX_HPP

// https://leetcode.com/problems/longest-common-prefix/description/

// Write a function to find the longest common prefix string amongst an array
// of strings.

#include <vector>
#include <string>

namespace CommonPrefix {

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return std::string();
        }

        if (strs[0].empty()) {
            return std::string();
        }

        std::string prefix;
        std::copy_n(strs[0].begin(), 1, prefix.begin());
        while (prefix.size() < strs[0].size()) {
            for (size_t i = 1; i < strs.size(); ++i) {
                if () {

                }
            }

            std::copy_n(strs[0].begin(), prefix.size() + 1, prefix.begin());
        }

        return prefix;
    }
};

}

#endif // LONGEST_COMMON_PREFIX_HPP
