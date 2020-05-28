#ifndef STR_UNIQUE_CHAR_HPP_
#define STR_UNIQUE_CHAR_HPP_

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

namespace Algo::DS::String {
    bool IsStrHasAllUniqueCharsBool(const std::string& inputStr) {
        if (inputStr.size() < 2) { return true; }

        // max number of ASCII symbols == max(char) = 256
        const size_t MAX = 256;
        if (MAX < inputStr.size()) { return false; }

        bool symbols[MAX];
        for (size_t i = 0; i < MAX; ++i) {
            symbols[i] = false;
        }

        for (size_t i = 0; i < inputStr.size(); ++i) {
            const int code = static_cast<int>(inputStr.at(i));
            if (symbols[code]) { return false; }

            symbols[code] = true;
        }

        return true;
    }

    bool IsStrHasAllUniqueCharsSet(const std::string& inputStr) {
        if (inputStr.size() < 2) { return true; }

        std::set<char> characters;
        for (size_t i = 0; i < inputStr.size(); ++i) {
            if (0 == characters.count(inputStr.at(i))) {
                characters.insert(inputStr.at(i));
            }
            else {
                return false;
            }
        }

        return true;
    }

    bool IsStrHasAllUniqueCharsSort(const std::string& inputStr) {
        if (inputStr.size() < 2) { return true; }

        std::string str = inputStr;
        std::sort(str.begin(), str.end());
        return std::adjacent_find(str.begin(), str.end()) == str.end();
    }
}

#endif /* STR_UNIQUE_CHAR_HPP_ */
