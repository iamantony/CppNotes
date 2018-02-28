#ifndef COUNT_AND_SAY_HPP
#define COUNT_AND_SAY_HPP

// https://leetcode.com/problems/count-and-say/description/

// The count-and-say sequence is the sequence of integers with the first ten
// terms as following:

// 1. 1
// 2. 11
// 3. 21
// 4. 1211
// 5. 111221
// 6. 312211
// 7. 13112221
// 8. 1113213211
// 9. 31131211131221
// 10. 13211311123113112211

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:
// Input: 1
// Output: "1"

// Example 2:
// Input: 4
// Output: "1211"

#include <string>

namespace CountAndSay {

class Solution {
public:
    std::string countAndSay(int n) {
        if (n < 1) {
            return std::string();
        }

        std::string result("1");
        for (int i = 1; i < n; ++i) {
            result = generator(result);
        }

        return result;
    }

private:
    std::string generator(const std::string& code) {
        if (code.empty()) {
            return std::string();
        }

        std::string result;
        for (size_t i = 0; i < code.size();) {
            char number = code[i];
            size_t quantity = 1;
            while(code[++i] == number) {
                ++quantity;
            }

//            char quantitySymbol = '0' + static_cast<int>(quantity);
            result += std::to_string(quantity);
            result.push_back(number);
        }

        return result;
    }
};

}

#endif // COUNT_AND_SAY_HPP
