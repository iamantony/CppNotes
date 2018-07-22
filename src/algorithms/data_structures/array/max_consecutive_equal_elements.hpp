#ifndef MAX_CONSECUTIVE_EQUAL_ELEMENTS_HPP
#define MAX_CONSECUTIVE_EQUAL_ELEMENTS_HPP

/*
https://leetcode.com/problems/max-consecutive-ones/description/

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

#include <vector>

namespace Algo::DS::Array {

class MaxConsecutiveElems {
public:
    static int MaxOnes(const std::vector<int>& v) {
        return Max<int>(v, 1);
    }

    template<typename T>
    static int Max(const std::vector<T>& v, const T& value) {
        size_t result = 0, i = 0, start = 0;
        for (; i < v.size(); ++i) {
            if (v[i] != value) {
                result = std::max(result, i - start);
                start = i + 1;
            }
        }

        result = std::max(result, i - start);

        return static_cast<int>(result);
    }
};

}

#endif // MAX_CONSECUTIVE_EQUAL_ELEMENTS_HPP
