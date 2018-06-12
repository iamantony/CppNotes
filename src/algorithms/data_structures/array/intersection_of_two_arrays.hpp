#ifndef INTERSECTION_OF_TWO_ARRAYS_HPP
#define INTERSECTION_OF_TWO_ARRAYS_HPP

// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

// Note:
// Each element in the result should appear as many times as it shows in both
// arrays. The result can be in any order.

// Follow up:
// - What if the given array is already sorted? How would you optimize your
// algorithm?
// - What if nums1's size is small compared to nums2's size? Which algorithm is
// better?
// - What if elements of nums2 are stored on disk, and the memory is limited
// such that you cannot load all elements into the memory at once?

#include <vector>
#include <map>
#include <algorithm>

namespace Algo { namespace DS { namespace Array {

class Intersection {
public:
    static std::vector<int> GetIntersection(std::vector<int>& nums1,
                                            std::vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return std::vector<int>();
        }

        std::vector<int>& smallArr =
                (nums1.size() > nums2.size()) ? nums2 : nums1;

        std::vector<int>& bigArr =
                (nums1.size() > nums2.size()) ? nums1 : nums2;

        std::map<int, int> numbersMap;
        for (int& number : smallArr) {
            ++numbersMap[number];
        }

        std::vector<int> intersection;
        for (int& number : bigArr) {
            if (numbersMap.count(number) > 0) {
                intersection.push_back(number);
                --numbersMap[number];
                if (numbersMap[number] <= 0) {
                    numbersMap.erase(number);
                }
            }
        }

        return intersection;
    }
};

} } }

#endif // INTERSECTION_OF_TWO_ARRAYS_HPP
