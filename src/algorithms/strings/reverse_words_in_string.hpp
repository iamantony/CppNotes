#ifndef REVERSE_WORDS_IN_STRING_HPP
#define REVERSE_WORDS_IN_STRING_HPP

/*
https://leetcode.com/problems/reverse-words-in-a-string/description/
Given an input string, reverse the string word by word.

Example:
Input: "the sky is blue",
Output: "blue is sky the".

Note:
- A word is defined as a sequence of non-space characters.
- Input string may contain leading or trailing spaces. However, your reversed
string should not contain leading or trailing spaces.
- You need to reduce multiple spaces between two words to a single space in the
reversed string.

Follow up: For C programmers, try to solve it in-place in O(1) space.


https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
Given a string, you need to reverse the order of characters in each word within
a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will
not be any extra space in the string.
*/

#include <algorithm>
#include <iterator>
#include <string>

namespace Algo::Strigns {

class ReverseWords {
    static void EliminateExtraSpace(std::string& s) {
        auto iter = s.begin(), write_iter = s.begin();
        while (iter != s.end()) {
            auto word_start = std::find_if(
                iter, s.end(), [](const auto& ch){ return ch != ' '; });

            if (word_start == s.end()) {
                break;
            }

            auto word_end = std::find(word_start, s.end(), ' ');
            if (write_iter != s.begin()) {
                *write_iter = ' ';
                ++write_iter;
            }

            for (; word_start < word_end; ++word_start, ++write_iter) {
                *write_iter = *word_start;
            }

            iter = word_end;
        }

        auto new_size = std::distance(s.begin(), write_iter);
        s.resize(static_cast<size_t>(new_size));
    }

public:
    static void ReverseWordsOrder(std::string& s) {
        EliminateExtraSpace(s);

        std::reverse(s.begin(), s.end());

        ReverseLettersInWords(s);
    }

    static void ReverseLettersInWords(std::string& s) {
        auto iter = s.begin();
        while (iter != s.end()) {
            auto word_start = std::find_if(
                iter, s.end(), [](const auto& ch){ return ch != ' '; });

            if (word_start == s.end()) {
                break;
            }

            auto word_end = std::find(word_start, s.end(), ' ');
            std::reverse(word_start, word_end);

            iter = word_end;
        }
    }
};
}

#endif // REVERSE_WORDS_IN_STRING_HPP
