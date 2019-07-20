#ifndef FIND_NEXT_GREATER_ELEMENT_HPP
#define FIND_NEXT_GREATER_ELEMENT_HPP

#include <vector>
#include <unordered_map>
#include <stack>
#include <set>
#include <limits>

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

    /*
    https://leetcode.com/problems/next-greater-element-ii/
    Given a circular array (the next element of the last element is the first
    element of the array), print the Next Greater Number for every element.
    The Next Greater Number of a number x is the first greater number to its
    traversing-order next in the array, which means you could search circularly
    to find its next greater number. If it doesn't exist, output -1 for
    this number.

    Example 1:
    Input: [1,2,1]
    Output: [2,-1,2]
    Explanation:
    - The first 1's next greater number is 2;
    - The number 2 can't find next greater number;
    - The second 1's next greater number needs to search circularly, which is also 2.

    Note: The length of given array won't exceed 10000.
    */
    // TC: O(n)
    // SC: O(n)
    static std::vector<int> FindInCircularArray(const std::vector<int>& nums) {
        std::vector<int> result(nums.size(), -1);
        std::stack<std::pair<int, size_t>> st;
        for (size_t i = 0; i < nums.size(); ++i) {
            while(!st.empty() && st.top().first < nums[i]) {
                result[st.top().second] = nums[i];
                st.pop();
            }

            st.emplace(nums[i], i);
        }

        for (size_t i = 0; i < nums.size() && !st.empty(); ++i) {
            while(!st.empty() && st.top().first < nums[i]) {
                result[st.top().second] = nums[i];
                st.pop();
            }
        }

        return result;
    }

    static int FindSmallestGreaterNum(int n) {
        n = std::abs(n);
        const auto input = n;

        std::vector<int> nums;
        std::multiset<int> ms;
        while(n > 0) {
            int number = n % 10;
            n /= 10;

            nums.push_back(number);
            ms.insert(number);
        }

        unsigned long long result = 0;
        unsigned long long multiplier = 1;
        for (size_t i = 0; i < nums.size(); ++i, multiplier *= 10) {
            auto iter = ms.upper_bound(nums[i]);
            if (iter == ms.end()) {
                iter = ms.lower_bound(nums[i]);
                if (iter != ms.begin()) {
                    --iter;
                }
            }

            auto next_num = static_cast<unsigned long long>(*iter);
            ms.erase(iter);

            result += next_num * multiplier;
        }

        if (result > std::numeric_limits<int>::max()) {
            return -1;
        }

        auto result_int = static_cast<int>(result);
        return result_int > input ? result_int : -1;
    }
};

}

#endif // FIND_NEXT_GREATER_ELEMENT_HPP
