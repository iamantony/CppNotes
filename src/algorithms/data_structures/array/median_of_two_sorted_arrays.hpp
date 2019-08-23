#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS_HPP
#define MEDIAN_OF_TWO_SORTED_ARRAYS_HPP

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log (m+n)).

#include <vector>
#include <limits>
#include <iostream>

namespace MedianOfTwoSortedArrays {
class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1,
                                  const std::vector<int>& nums2) {
        if (nums1.empty()) {
            if (nums2.empty()) {
                return 0.0;
            }
            else {
                return GetMedianOfVector(nums2);
            }
        }
        else if (nums2.empty()) {
            return GetMedianOfVector(nums1);
        }

        size_t itN1 = 0, itN2 = 0;

        // Set start postion of itN1 - middle of 'nums1' vector
        itN1 = nums1.size() / 2;

        // Special function to recalc itN2
        auto UpdateIterN2 = [&itN1, &itN2, &nums1, &nums2]() {
            itN2 = (nums1.size() + nums2.size() + 1) / 2 - itN1;
        };

        UpdateIterN2();

        while(true) {
            if ((itN2 == 0 || itN1 == nums1.size() ||
                        nums2.at(itN2 - 1) <= nums1.at(itN1)) &&
                (itN1 == 0 || itN2 == nums2.size() ||
                        nums1.at(itN1 - 1) <= nums2.at(itN2))) {
                // Perfect!
                break;
            }
            else if (itN2 > 0 && itN1 < nums1.size() &&
                     nums2.at(itN2 - 1) > nums1.at(itN1)) {
                // itN1 is too small, we need to increase it
                ++itN1;
            }
            else if (itN1 > 0 && itN2 < nums2.size() &&
                     nums1.at(itN1 - 1) > nums2.at(itN2)) {
                // itN1 is too big, let's decrease it
                --itN1;
            }
            else {
                std::cout << "Error: we entered invalid case" << std::endl;
                return -1.0;
            }

            UpdateIterN2();
        }

        const int defaultMin = std::numeric_limits<int>::min();
        const int defaultMax = std::numeric_limits<int>::max();

        double median = 0.0;
        size_t numOfAllElements = nums1.size() + nums2.size();
        if (numOfAllElements % 2 == 0) {
            int firstElem = std::max(GetElem(nums1, itN1 -1, defaultMin),
                                     GetElem(nums2, itN2 - 1, defaultMin));

            int secondElem = std::min(GetElem(nums1, itN1, defaultMax),
                                      GetElem(nums2, itN2, defaultMax));

            median = static_cast<double>(firstElem + secondElem) / 2;
        }
        else {
            median = std::max(GetElem(nums1, itN1 -1, defaultMin),
                              GetElem(nums2, itN2 - 1, defaultMin));
        }

        return median;
    }

private:
    double GetMedianOfVector(const std::vector<int>& vec) {
        if (vec.empty()) {
            return 0.0;
        }

        if (vec.size() % 2 == 0) {
            size_t middleIndex = vec.size() / 2;
            double sumOfMiddleElements = vec.at(middleIndex - 1) +
                    vec.at(middleIndex);

            return sumOfMiddleElements / 2.0;
        }

        return vec.at(vec.size() / 2);
    }

    int GetElem(const std::vector<int>& vec, const size_t& iter,
                const int& defaultValue) {
        if (iter < vec.size()) {
            return vec.at(iter);
        }

        return defaultValue;
    }
};

}

#endif // MEDIAN_OF_TWO_SORTED_ARRAYS_HPP
