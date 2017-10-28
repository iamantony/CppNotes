#ifndef LONGEST_SUBSTRING_HPP
#define LONGEST_SUBSTRING_HPP

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Given a string, find the length of the longest substring without repeating
// characters.

// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
//Given "bbbbb", the answer is "b", with the length of 1.
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the
// answer must be a substring, "pwke" is a subsequence and not a substring.

#include <string>
#include <map>

namespace LongestSubstring
{

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::map<char, size_t> characters;
        size_t result = 0;
        for (size_t i = 0, j = 0; j < s.size(); ++j)
        {
            if (0 < characters.count(s.at(j)))
            {
                i = std::max(i, characters.at(s.at(j)));
            }

            result = std::max(result, j - i + 1);
            characters[s.at(j)] = j;
        }

        return static_cast<int>(result);
    }
};

}

#endif // LONGEST_SUBSTRING_HPP

