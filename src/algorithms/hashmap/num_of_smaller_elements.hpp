#ifndef NUM_OF_SMALLER_ELEMENTS_HPP
#define NUM_OF_SMALLER_ELEMENTS_HPP

/*
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
That is, for each nums[i] you have to count the number of valid j's such that j != i and
nums[j] < nums[i].

Return the answer in an array.

Example 1:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation:
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1).
For nums[3]=2 there exist one smaller number than it (1).
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

Example 2:
Input: nums = [6,5,4,8]
Output: [2,1,0,3]

Example 3:
Input: nums = [7,7,7,7]
Output: [0,0,0,0]

Constraints:
2 <= nums.length <= 500
0 <= nums[i] <= 100
*/

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace Algo::HashMap {
    class NumOfSmallerElements {
    public:
        static std::vector<int> count(const std::vector<int>& nums) {
            auto v = nums;
            std::sort(v.begin(), v.end());

            int counter = 0;
            std::unordered_map<int, int> count_map;
            for (auto iter = v.begin(); iter != v.end(); ++iter) {
                if (count_map.count(*iter) == 0) {
                    count_map[*iter] = counter;

                    auto greater_iter = std::upper_bound(iter, v.end(), *iter);
                    counter += static_cast<int>(std::distance(iter, greater_iter));
                }
            }

            std::vector<int> result(nums.size(), 0);
            for (size_t i = 0; i < nums.size(); ++i) {
                result[i] = count_map[nums[i]];
            }

            return result;
        }
    };
}

#endif //NUM_OF_SMALLER_ELEMENTS_HPP
