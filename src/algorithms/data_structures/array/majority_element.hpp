#ifndef MAJORITY_ELEMENT_HPP
#define MAJORITY_ELEMENT_HPP

/*
https://leetcode.com/problems/majority-element/description/

Given an array of size n, find the majority element. The majority element is
the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always
exist in the array.

Do it in O(n) time and O(1) space.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
*/

#include <vector>

namespace Algo::DS::Array {

class MajorityElement {
public:
    static int Find(const std::vector<int>& v) {
        int majorityElement = v[0];
        size_t counter = 1;
        for (size_t i = 1; i < v.size(); ++i) {
            if (v[i] == majorityElement) {
                ++counter;
            }
            else {
                if (counter == 1) {
                    majorityElement = v[i];
                }
                else {
                    --counter;
                }
            }
        }

        return majorityElement;
    }
};

}

#endif // MAJORITY_ELEMENT_HPP
