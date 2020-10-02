#ifndef VALID_PALINDROME_HPP
#define VALID_PALINDROME_HPP

#include <string>
#include <algorithm>
#include <locale>

namespace Algo::DS::String {
    class ValidPalindrome {
    public:
        /*
        https://leetcode.com/problems/valid-palindrome/description/
        Given a string, determine if it is a palindrome, considering only
        alphanumeric characters and ignoring cases.

        For example, "A man, a plan, a canal: Panama" is a palindrome.
        "race a car" is not a palindrome.

        Note:
        Have you consider that the string might be empty? This is a good question
        to ask during an interview. For the purpose of this problem, we define empty
        string as valid palindrome.
        */
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
                    right--;
                }
                else {
                    if (s[left] != s[right]) {
                        return false;
                    }
                    else {
                        ++left;
                        --right;
                    }
                }
            }

            return true;
        }

        /*
        https://leetcode.com/problems/valid-palindrome-ii/
        Given a non-empty string s, you may delete at most one character. Judge whether you can
        make it a palindrome.

        Example 1:
        Input: "aba"
        Output: True

        Example 2:
        Input: "abca"
        Output: True
        Explanation: You could delete the character 'c'.

        Note:
        The string will only contain lowercase characters a-z. The maximum length of the string is
        50000.
        */
        bool isPalindromeWithOneError(std::string s) {
            if (s.size() < 2) { return true; }

            size_t l = 0, r = s.size() - 1;
            while (l < r  && s[l] == s[r]) {
                ++l;
                --r;
            }

            return l >= r ?
                true :
                isPalindrome({s.data() + l + 1, r-l}) || isPalindrome({s.data() + l, r-l});
        }
    };
}

#endif // VALID_PALINDROME_HPP
