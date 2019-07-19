#ifndef FIND_NEXT_GREATER_ELEMENT_HPP
#define FIND_NEXT_GREATER_ELEMENT_HPP

#include <vector>
#include <unordered_map>
#include <stack>

namespace Algo::Search {

class FindNextGreaterElem {
public:
    /*
    https://leetcode.com/problems/next-greater-element-i/
    You are given two arrays (without duplicates) nums1 and nums2 where
    nums1’s elements are subset of nums2. Find all the next greater numbers
    for nums1's elements in the corresponding places of nums2.

    The Next Greater Number of a number x in nums1 is the first greater number
    to its right in nums2. If it does not exist, output -1 for this number.

    Example 1:
    Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
    Output: [-1,3,-1]
    Explanation:
        For number 4 in the first array, you cannot find the next greater
            number for it in the second array, so output -1.
        For number 1 in the first array, the next greater number for it
            in the second array is 3.
        For number 2 in the first array, there is no next greater number
            for it in the second array, so output -1.

    Example 2:
    Input: nums1 = [2,4], nums2 = [1,2,3,4].
    Output: [3,-1]
    Explanation:
        For number 2 in the first array, the next greater number for it
            in the second array is 3.
        For number 4 in the first array, there is no next greater number
            for it in the second array, so output -1.

    Note:
    All elements in nums1 and nums2 are unique.
    The length of both nums1 and nums2 would not exceed 1000.
    */

    // TC: O(n*m)
    // SC: O(1)
    static std::vector<int> FindSimple(const std::vector<int>& nums1,
                                       const std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return {};
        }

        std::vector<int> result(nums1.size(), -1);
        for (size_t i = 0; i < nums1.size(); ++i) {
            size_t pos = nums2.size();
            for (size_t j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    pos = j;
                    break;
                }
            }

            for (size_t j = pos + 1; j < nums2.size(); ++j) {
                if (nums1[i] < nums2[j]) {
                    result[i] = nums2[j];
                    break;
                }
            }
        }

        return result;
    }

    // TC: O(n)
    // SC: O(m)
    static std::vector<int> FindUsingStack(const std::vector<int>& nums1,
                                           const std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return {};
        }

        std::unordered_map<int, int> search_map;
        std::stack<int> st;
        for (size_t i = 0; i < nums2.size(); ++i) {
            while(!st.empty() && st.top() < nums2[i]) {
                search_map[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        std::vector<int> result(nums1.size(), -1);
        for (size_t i = 0; i < nums1.size(); ++i) {
            auto iter = search_map.find(nums1[i]);
            if (iter != std::end(search_map)) {
                result[i] = iter->second;
            }
        }

        return result;
    }
};

}

#endif // FIND_NEXT_GREATER_ELEMENT_HPP
