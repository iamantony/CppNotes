#ifndef UNIQUE_NUMBER_OF_OCCURRENCE_HPP
#define UNIQUE_NUMBER_OF_OCCURRENCE_HPP

/*
https://leetcode.com/problems/unique-number-of-occurrences/
Given an array of integers arr, write a function that returns true if and only if the number of
occurrences of each value in the array is unique.

Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:
Input: arr = [1,2]
Output: false

Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

Constraints:
1. 1 <= arr.length <= 1000
2. -1000 <= arr[i] <= 1000
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace Algo::HashMap {
    class UniqueNumberOfOccurrence {
    public:
        static bool check(const std::vector<int>& v) {
            std::unordered_map<int, size_t> occurrence_map;
            for (const auto& i : v) {
                if (occurrence_map.count(i) == 0) {
                    occurrence_map[i] = 1;
                }
                else {
                    ++occurrence_map[i];
                }
            }

            std::unordered_set<size_t> unique_occurrence_num;
            for (const auto& [_, count] : occurrence_map) {
                if (unique_occurrence_num.count(count) > 0) {
                    return false;
                }
                else {
                    unique_occurrence_num.insert(count);
                }
            }

            return true;
        }
    };
}

#endif //UNIQUE_NUMBER_OF_OCCURRENCE_HPP
