#ifndef LONGEST_PALINDROME_HPP
#define LONGEST_PALINDROME_HPP

// https://leetcode.com/problems/longest-palindromic-substring/description/
// Given a string s, find the longest palindromic substring in s.

// Solutions:
// https://articles.leetcode.com/longest-palindromic-substring-part-i/
// https://articles.leetcode.com/longest-palindromic-substring-part-ii/

#include <string>

namespace Algo::DS::String {
    class LongestPalindrome {
    public:
        static std::string find(const std::string& s)
        {
            if (s.size() < 2) {
                return s;
            }

            // Start and end indexes of the longest palindrom
            size_t start = 0, end = 0;

            // Iterate over string. On each iteration we choose new (next) letter
            // as possible center of palindrom
            for (size_t i = 0; i < s.size(); ++i) {
                // Check if current letter is central letter of palindrom
                // (length of palindrom is odd - 'aba')
                size_t lenOddPalindrome = expandAroundCenter(s, i, i);

                // Check if center of palindrom is between current and next
                // letters (length of palindrim is even - 'abba')
                size_t lenEvenPalindrome = expandAroundCenter(s, i, i + 1);

                // Update start and end indexes of the longest palindrom
                size_t len = std::max(lenOddPalindrome, lenEvenPalindrome);
                if (len > end - start) {
                    start = i - (len - 1) / 2;
                    end = i + len / 2;
                }
            }

            return s.substr(start, (end + 1 - start));
        }

    private:
        static size_t expandAroundCenter(const std::string& s, size_t left, size_t right) {
            // 'left' and 'right' are possible indexes of the center of the
            // palindrom. Because palindrom is symmetric about its center,
            // we will try to move from the center to the palindrom borders
            // (variables L and R) at the same time. We will stop when letters
            // on the borders of palindrom will not be the same.
            // Do not forget to check at each step that our borders are within
            // the string!!!

            size_t length = 0;
            while (right < s.size() && s.at(left) == s.at(right)) {
                length = right - left + 1;
                if (left == 0 || right == s.size() - 1) {
                    break;
                }

                left--;
                right++;
            }

            return length;
        }
    };
}

#endif // LONGEST_PALINDROME_HPP
