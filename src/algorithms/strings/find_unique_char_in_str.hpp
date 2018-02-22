#ifndef FIND_UNIQUE_CHAR_IN_STR_HPP
#define FIND_UNIQUE_CHAR_IN_STR_HPP

// Given a string, find the first non-repeating character in it and return
// it's index. If it doesn't exist, return -1.

// Examples:
// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.

// Note: You may assume the string contain only lowercase letters.

#include <string>
#include <map>

namespace FindUnique {

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::map<char, int> strStat;
        for (size_t i = 0; i < s.size(); ++i) {
            if (strStat.count(s[i]) > 0) {
                strStat[s[i]] = -1;
            }
            else {
                strStat[s[i]] = static_cast<int>(i);
            }
        }

        int minPos = static_cast<int>(s.size());
        for(auto iter : strStat) {
            if (iter.second < 0) {
                continue;
            }

            minPos = std::min(minPos, iter.second);
        }

        if (minPos >= static_cast<int>(s.size())) {
            return -1;
        }

        return minPos;
    }
};

}

#endif // FIND_UNIQUE_CHAR_IN_STR_HPP
