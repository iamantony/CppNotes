#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS_HPP
#define MEDIAN_OF_TWO_SORTED_ARRAYS_HPP

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log (m+n)).

#include <vector>

namespace MedianOfTwoSortedArrays
{

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1,
                                  std::vector<int>& nums2)
    {
        auto getMedian = [](const std::vector<int>& array) -> double
        {
            if (array.empty())
            {
                return 0.0;
            }

            if (1 == (array.size() % 2))
            {
                size_t index = array.size() / 2;
                return static_cast<double>(array.at(index));
            }
            else
            {
                size_t index = array.size() / 2;
                return (static_cast<double>(array.at(index)) +
                        static_cast<double>(array.at(index - 1))) / 2;
            }
        };

        if (nums1.empty())
        {
            return getMedian(nums2);
        }
        else if (nums2.empty())
        {
            return getMedian(nums1);
        }

        return (getMedian(nums1) + getMedian(nums2)) / 2;
    }
};

}

#endif // MEDIAN_OF_TWO_SORTED_ARRAYS_HPP

