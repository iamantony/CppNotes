#ifndef MERGE_SORTED_ARRAYS_HPP
#define MERGE_SORTED_ARRAYS_HPP

/*
https://leetcode.com/problems/merge-sorted-array/
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
sorted array.

Note:
- The number of elements initialized in nums1 and nums2 are m and n respectively.
- You may assume that nums1 has enough space (size that is greater or equal
to m + n) to hold additional elements from nums2.
- Do it in O(1) space

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

#include <vector>

namespace Algo::DS::Array {

class MergeSortedArrays {
public:
    static void Merge(std::vector<int>& first, const int& fSize,
                      std::vector<int>& second, const int& sSize) {
        if (fSize < 0 || sSize < 0 || fSize + sSize == 0) {
            return;
        }

        int i = fSize + sSize - 1, fIter = fSize - 1, sIter = sSize - 1;
        while (i >= 0) {
            const size_t ii = static_cast<size_t>(i);
            const size_t ffIter = static_cast<size_t>(fIter);
            const size_t ssIter = static_cast<size_t>(sIter);

            if (fIter >= 0 && (sIter < 0 || first[ffIter] > second[ssIter])) {
                first[ii] = first[ffIter];
                --fIter;
            }
            else {
                first[ii] = second[ssIter];
                --sIter;
            }

            --i;
        }
    }
};

}

#endif // MERGE_SORTED_ARRAYS_HPP
