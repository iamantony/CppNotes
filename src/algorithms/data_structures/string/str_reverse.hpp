#ifndef STR_REVERSE_HPP_
#define STR_REVERSE_HPP_

#include <cstring>
#include <string>

namespace Algo::DS::String {

    // Implement a function void reverse(char* str) in C or C++ which reverses a
    // null-terminated string
    void ReverseString(char* str) {
        size_t size = strlen(str);
        if (size < 2) { return; }

        char* i = str;
        char* j = str + size - 1;
        while(i < j) {
            char buff = *i;
            *i++ = *j;
            *j-- = buff;
        }
    }

    // https://leetcode.com/problems/reverse-string/description/
    // Write a function that takes a string as input and returns the string reversed.
    // Example:
    // Given s = "hello", return "olleh".
    class ReverseStr {
    public:
        std::string reverse(std::string s) {
            if (s.size() < 2) {
                return s;
            }

            size_t i = 0;
            size_t j = s.size() - 1;
            while(i < j) {
                std::swap(s[i++], s[j--]);
            }

            return s;
        }
    };
}

#endif /* STR_REVERSE_HPP_ */
