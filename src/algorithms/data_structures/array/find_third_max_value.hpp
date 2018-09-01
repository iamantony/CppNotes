#ifndef FIND_THIRD_MAX_VALUE_HPP
#define FIND_THIRD_MAX_VALUE_HPP

/*
https://leetcode.com/problems/third-maximum-number/description/
Given a non-empty array of integers, return the third maximum number in this
array. If it does not exist, return the maximum number. The time complexity
must be in O(n).

Example 1:
Input: [3, 2, 1]
Output: 1
Explanation: The third maximum is 1.

Example 2:
Input: [1, 2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned
instead.

Example 3:
Input: [2, 2, 3, 1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct
number. Both numbers with value 2 are both considered as second maximum.
*/

#include <set>
#include <vector>

namespace Algo::DS::Array {

class ThirdMaxValue {
public:
    // Main idea: use set to contain max 3 sorted values.
    // TC: O(n * log 3)
    // SC: O(4)
    static int Find(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::set<int> values;
        for (const int& number : nums) {
            values.insert(number);
            if (values.size() > 3) {
                values.erase(values.begin());
            }
        }

        if (values.size() < 3) {
            // return largest
            return *(values.rbegin());
        }

        // return 3rd max value
        return *(values.begin());
    }
};

}

#endif // FIND_THIRD_MAX_VALUE_HPP
