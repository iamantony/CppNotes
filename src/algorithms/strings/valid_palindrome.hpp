#ifndef VALID_PALINDROME_HPP
#define VALID_PALINDROME_HPP

// https://leetcode.com/problems/valid-palindrome/description/

// Given a string, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question
// to ask during an interview. For the purpose of this problem, we define empty
// string as valid palindrome.

#include <string>
#include <algorithm>
#include <locale>

namespace ValidPalindrome {

class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.size() < 2) {
            return true;
        }

        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        size_t left = 0;
        size_t right = s.size() - 1;
        while (left < right) {
            if (!std::isalnum(s[left])) {
                left++;
            }
            else if (!std::isalnum(s[right])) {
                if (right == 0) {
                    return false;
                }

                right--;
            }
            else {
                if (s[left] != s[right]) {
                    return false;
                }
                else {
                    ++left;
                    if (right == 0) {
                        return false;
                    }

                    --right;
                }
            }
        }

        return true;
    }
};

}

#endif // VALID_PALINDROME_HPP
