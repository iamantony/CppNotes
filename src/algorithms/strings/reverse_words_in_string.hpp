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

#include <string>

namespace Algo::Strigns {

class ReverseWords {
public:
    // TODO: update tests
    static void ReverseWordsOrder(std::string& s) {
        if (s.empty()) {
            return;
        }

        // Reverse string
        for (size_t left = 0, right = s.size() - 1; left < right;
             ++left, --right)
        {
            std::swap(s[left], s[right]);
        }

        // Reverse words in reversed string
        for (size_t i = 0; i < s.size(); ++i) {
            size_t wordStart = i;
            while(wordStart < s.size() && s[wordStart] == ' ') {
                ++wordStart;
            }

            if (wordStart >= s.size()) {
                break;
            }

            size_t wordEnd = wordStart;
            while(wordEnd < s.size() && s[wordEnd] != ' ') {
                ++wordEnd;
            }

            for (size_t wLeft = wordStart, wRight = wordEnd - 1;
                 wLeft < wRight; ++wLeft, --wRight)
            {
                std::swap(s[wLeft], s[wRight]);
            }

            i = wordEnd - 1;
        }

        // Eliminate extra space
        size_t writePos = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            while(i < s.size() && s[i] == ' ') {
                ++i;
            }

            if (i >= s.size()) {
                break;
            }

            while(i < s.size() && s[i] != ' ') {
                if (writePos == i) {
                    ++writePos;
                    ++i;
                }
                else {
                    s[writePos++] = s[i];
                    s[i++] = ' ';
                }
            }

            --i;

            if (writePos < s.size()) {
                s[writePos++] = ' ';
            }
        }

        // Check that on the end of the string there is no white space
        size_t endPos = std::min(writePos, s.size() - 1);
        while (s[endPos] == ' ') {
            if (endPos == 0) {
                break;
            }

            --endPos;
        }

        if (endPos == 0) {
            s[endPos] != ' ' ? s.resize(1) : s.resize(0);
        }
        else {
            s.resize(endPos + 1);
        }
    }
    
    // TODO: add tests
    static void ReverseLettersInWords(std::string& s) {
        if (s.size() < 2) {
            return;
        }
        
        for (size_t start = 0, end = 1; end < s.size(); ) {
            while(end < s.size() && s[end] != ' ') {
                ++end;
            }
            
            if (end - start > 1) {
                for (size_t i = start, j = end - 1; i < j; ++i, --j) {
                    std::swap(s[i], s[j]);
                }
            }
            
            start = end + 1;
            end = end + 2;
        }
    }
};

}

#endif // REVERSE_WORDS_IN_STRING_HPP
