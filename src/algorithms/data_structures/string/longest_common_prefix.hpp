#ifndef LONGEST_COMMON_PREFIX_HPP
#define LONGEST_COMMON_PREFIX_HPP

// https://leetcode.com/problems/longest-common-prefix/description/

// Write a function to find the longest common prefix string amongst an array
// of strings.

#include <vector>
#include <string>

namespace Algo::DS::String {
    class CommonPrefix {
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            if (strs.empty()) {
                return std::string();
            }

            for (size_t pos = 0; pos < strs[0].size() ; ++pos) {
                char c = strs[0][pos];
                for (size_t sNum = 1; sNum < strs.size(); ++sNum) {
                    if (pos == strs[sNum].size() || strs[sNum][pos] != c) {
                        return strs[0].substr(0, pos);
                    }
                }
            }

            return strs[0];
        }
    };
}

#endif // LONGEST_COMMON_PREFIX_HPP
