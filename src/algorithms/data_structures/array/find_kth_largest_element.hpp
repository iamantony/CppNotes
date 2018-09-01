#ifndef FIND_KTH_LARGEST_ELEMENT_HPP
#define FIND_KTH_LARGEST_ELEMENT_HPP

/*
https://leetcode.com/problems/kth-largest-element-in-an-array/description/
Find the kth largest element in an unsorted array. Note that it is the kth
largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include <vector>
#include <random>

namespace Algo::DS::Array {

class KthLargestElement {
public:
    static int Find(std::vector<int>& nums, size_t k) {
        if (nums.empty() || k == 0 || k > nums.size()) {
            return 0;
        }

        k = nums.size() - k;
        size_t start = 0, end = nums.size() - 1;
        std::mt19937 mt(42);
        while (true) {
            if (start >= end){
                break;
            }

            std::uniform_int_distribution<size_t> dist(start, end);
            size_t pivotPos = dist(mt);
            std::swap(nums[start], nums[pivotPos]);
            pivotPos = start;
            for (size_t i = start + 1; i <= end; ++i) {
                if (nums[i] < nums[start]) {
                    ++pivotPos;
                    std::swap(nums[pivotPos], nums[i]);
                }
            }

            std::swap(nums[start], nums[pivotPos]);

            if (pivotPos == k) {
                break;
            }
            else if (pivotPos < k) {
                start = pivotPos + 1;
            }
            else {
                end = pivotPos == 0 ? 0 : pivotPos - 1;
            }
        }

        return nums[k];
    }
};

}

#endif // FIND_KTH_LARGEST_ELEMENT_HPP
