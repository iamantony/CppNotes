#ifndef LONGEST_PALINDROME_HPP
#define LONGEST_PALINDROME_HPP

// https://leetcode.com/problems/longest-palindromic-substring/description/
// Given a string s, find the longest palindromic substring in s.

// Solutions:
// https://articles.leetcode.com/longest-palindromic-substring-part-i/
// https://articles.leetcode.com/longest-palindromic-substring-part-ii/

#include <string>

namespace LongestPalindrome
{

class Solution {
public:
    std::string longestPalindrome(std::string s)
    {
        size_t start = 0, end = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            size_t len1 = expandAroundCenter(s, i, i);
            size_t len2 = expandAroundCenter(s, i, i + 1);
            size_t len = std::max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end + 1 - start);
    }

private:
    size_t expandAroundCenter(const std::string& s, const size_t& left,
                              const size_t& right)
    {
        size_t L = left, R = right;
        while (L >= 0 && R < s.length() && s.at(L) == s.at(R)) {
            L--;
            R++;
        }

        return R - L - 1;
    }
};

}

#endif // LONGEST_PALINDROME_HPP

