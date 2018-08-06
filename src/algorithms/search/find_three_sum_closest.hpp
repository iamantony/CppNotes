#ifndef FIND_THREE_SUM_CLOSEST_HPP
#define FIND_THREE_SUM_CLOSEST_HPP

/*
https://leetcode.com/problems/3sum-closest/description/

Given an array nums of n integers and an integer target, find three integers
in nums such that the sum is closest to target. Return the sum of the three
integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <vector>
#include <limits>

namespace Algo::Search {

class Find3SumClosest {
public:
    static int Find(std::vector<int>& nums, const int& target) {
        if (nums.size() < 3) {
            return -1;
        }

        std::sort(nums.begin(), nums.end());

        long long closestSum = std::numeric_limits<int>::min();
        for (size_t i = 0; i < nums.size(); ++i) {
            // Skip duplicates after first run
            if (i > 0 && closestSum == target) {
                break;
            }

            size_t mid = i + 1, right = nums.size() - 1;
            while (mid < right) {
                long long sum = nums[i] + nums[mid] + nums[right];
                long long diff = std::abs(static_cast<long long>(target) - sum);
                long long diffPrev = std::abs(static_cast<long long>(target) -
                                              closestSum);
                if (diff < diffPrev) {
                    closestSum = sum;
                }

                if (sum == target) {
                    break;
                }
                else if (sum < target) {
                    ++mid;
                }
                else {
                    --right;
                }
            }
        }

        return static_cast<int>(closestSum);
    }
};

}


#endif // FIND_THREE_SUM_CLOSEST_HPP
