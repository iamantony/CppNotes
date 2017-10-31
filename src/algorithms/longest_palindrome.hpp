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
        const int strSize = static_cast<int>(s.size());

        // Start and end indexes of the longest palindrom
        int start = 0, end = 0;

        // Iterate over string. On each iteration we choose new (next) letter
        // as possible center of palindrom
        for (int i = 0; i < strSize; ++i)
        {
            // Check if current letter is central letter of palindrom
            // (length of palindrom is odd - 'aba')
            int len1 = expandAroundCenter(s, i, i);

            // Check if center of palindrom is between current and next
            // letters (length of palindrim is even - 'abba')
            int len2 = expandAroundCenter(s, i, i + 1);

            // Update start and end indexes of the longest palindrom
            int len = std::max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(static_cast<size_t>(start),
                        static_cast<size_t>(end + 1 - start));
    }

private:
    int expandAroundCenter(const std::string& s, const int& left,
                           const int& right)
    {
        // 'left' and 'right' are possible indexes of the center of the
        // palindrom. Because palindrom is symmetric about its center,
        // we will try to move from the center to the palindrom borders
        // (variables L and R) at the same time. We will stop when letters
        // on the borders of palindrom will not be the same.
        // Do not forget to check at each step that our borders are within
        // the string!!!

        int L = left, R = right;
        const int strSize = static_cast<int>(s.size());
        while (L >= 0 && R < strSize &&
               s.at(static_cast<size_t>(L)) == s.at(static_cast<size_t>(R))) {
            L--;
            R++;
        }

        return R - L - 1;
    }
};

}

#endif // LONGEST_PALINDROME_HPP

