#ifndef STR_IS_SUBSTRING_HPP_
#define STR_IS_SUBSTRING_HPP_

#include <string>

namespace StrSubstring {

// https://leetcode.com/problems/implement-strstr/description/

// Implement strStr(). Return the index of the first occurrence of needle in
// haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // needle should be less or equal in size with haystack to be
        // a substring
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        else if (haystack.size() == needle.size())
        {
            // quick check if size of strings are equal
            return (haystack == needle) ? 0 : -1;
        }
        else if (needle.empty()) {
            // empty string is substring for every string
            return 0;
        }

        for(size_t i = 0; i < haystack.size(); ++i) {
            if (haystack[i] == needle[0]) {
                size_t startPos = i;
                size_t hi = i + 1, ni = 1;
                while ( hi < haystack.size() &&
                        ni < needle.size() &&
                        haystack[hi] == needle[ni]) {
                    ++hi;
                    ++ni;
                }

                if (ni == needle.size()) {
                    return static_cast<int>(startPos);
                }
            }
        }

        return -1;
    }

    // Assume you have a method isSubstring which checks if one word is a
    // substring of another. Given two strings, s1 and s2, write code to check
    // if s2 is a rotation of s1 using only one call to isSubstring (e.g.,
    // "waterbottLe" is a rotation of "erbottLewat").
    bool isStrRotationOfOtherStr(const std::string& original,
            const std::string& str)
    {
        if (original.empty() || original.size() != str.size())
        {
            return false;
        }

        std::string sourceStr = original + original;
        return strStr(sourceStr, str) > 0;
    }
};

}

#endif /* STR_IS_SUBSTRING_HPP_ */
