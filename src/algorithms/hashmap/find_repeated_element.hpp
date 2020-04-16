#ifndef FIND_REPEATED_ELEMENT_HPP
#define FIND_REPEATED_ELEMENT_HPP

/*
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is
repeated N times. Return the element repeated N times.

Example 1:
Input: [1,2,3,3]
Output: 3

Example 2:
Input: [2,1,2,5,3,2]
Output: 2

Example 3:
Input: [5,1,5,2,5,3,5,4]
Output: 5

Note:
- 4 <= A.length <= 10000
- 0 <= A[i] < 10000
- A.length is even
*/

#include <vector>
#include <unordered_set>

namespace Algo::HashMap {
    class FindRepeatedElement {
    public:
        static int find(const std::vector<int>& v) {
            if (v.size() < 2) {
                throw std::logic_error("Invalid size of input array");
            }

            size_t stop_index = std::min(v.size() / 2 + 2, v.size());
            std::unordered_set<int> set;
            for (size_t i = 0; i < stop_index; ++i) {
                if (set.count(v[i]) > 0) {
                    return v[i];
                }

                set.insert(v[i]);
            }

            throw std::runtime_error("Invalid content of the input array");
        }
    };
}

#endif //FIND_REPEATED_ELEMENT_HPP
