#ifndef INTERSECTION_OF_TWO_ARRAYS_HPP
#define INTERSECTION_OF_TWO_ARRAYS_HPP

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

namespace Algo::DS::HashMap {
    class IntersectionOfTwoArray {
    public:
        /* https://leetcode.com/problems/intersection-of-two-arrays/
           Given two arrays, write a function to compute their intersection.

           Example 1:
           Input: nums1 = [1,2,2,1], nums2 = [2,2]
           Output: [2]

           Example 2:
           Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
           Output: [9,4]

           Note:
           Each element in the result must be unique.
           The result can be in any order.
         */
        static std::vector<int> find_unique(
            const std::vector<int>& nums1, const std::vector<int>& nums2)
        {
            if (nums1.empty() || nums2.empty()) { return {}; }

            const auto& small_arr = (nums1.size() > nums2.size()) ? nums2 : nums1;
            const auto& big_arr = (nums1.size() > nums2.size()) ? nums1 : nums2;
            std::unordered_set<int> unique_nums(small_arr.begin(), small_arr.end());
            std::vector<int> result;
            for (const auto& i : big_arr) {
                if (unique_nums.count(i) == 0) { continue; }

                result.push_back(i);
                unique_nums.erase(i);
            }

            return result;
        }

        /*
           https://leetcode.com/problems/intersection-of-two-arrays-ii/
           Given two arrays, write a function to compute their intersection.

           Example 1:
           Input: nums1 = [1,2,2,1], nums2 = [2,2]
           Output: [2,2]

           Example 2:
           Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
           Output: [4,9]

           Note:
           Each element in the result should appear as many times as it shows in both arrays.
           The result can be in any order.

           Follow up:
           What if the given array is already sorted? How would you optimize your algorithm?
           What if nums1's size is small compared to nums2's size? Which algorithm is better?
           What if elements of nums2 are stored on disk, and the memory is limited such that you
           cannot load all elements into the memory at once?
         */
        static std::vector<int> find_all(
            const std::vector<int>& nums1, const std::vector<int>& nums2)
        {
            if (nums1.empty() || nums2.empty()) { return {}; }

            const auto& small_arr = (nums1.size() > nums2.size()) ? nums2 : nums1;
            const auto& big_arr = (nums1.size() > nums2.size()) ? nums1 : nums2;
            std::unordered_map<int, int> numbersMap;
            for (const auto& number : small_arr) {
                ++numbersMap[number];
            }

            std::vector<int> intersection;
            for (const auto& number : big_arr) {
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
}

#endif // INTERSECTION_OF_TWO_ARRAYS_HPP
