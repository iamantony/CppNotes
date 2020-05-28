#ifndef STR_REPLACE_SPACES_HPP_
#define STR_REPLACE_SPACES_HPP_

// Write a method to replace all spaces in a string with '%20'. You may assume
// that the string has sufficient space at the end of the string to hold the
// additional characters, and that you are given the "true" length of the
// string.

#include <cstring>

namespace Algo::DS::String {
    void ReplaceSpaces(char * const str) {
        int strLength = static_cast<int>(strlen(str));
        if (strLength <= 1) { return; }

        int spaces = 0;
        for (int i = 0; i < strLength; ++i) {
            if (str[i] == ' ') {
                ++spaces;
            }
        }

        int newLength = strLength + 2 * spaces;
        str[newLength] = '\0';
        for (int i = strLength - 1, j = newLength - 1; i >= 0; --i) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
            else {
                str[j--] = str[i];
            }
        }
    }
}

#endif /* STR_REPLACE_SPACES_HPP_ */
