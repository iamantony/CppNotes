#ifndef CPPNOTESMAIN_TRAPPING_RAIN_WATER_HPP
#define CPPNOTESMAIN_TRAPPING_RAIN_WATER_HPP

/*
https://leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

#include <vector>

namespace Algo::DS::Array {
    class TrappingRainWater {
    public:
        int trap(const std::vector<int>& height) {
            int result = 0;
            if (height.size() < 3) { return result; }

            std::vector<int> left_max(height.size(), 0);
            left_max[0] = height[0];
            for (size_t i = 1; i < height.size(); ++i) {
                left_max[i] = std::max(left_max[i-1], height[i]);
            }

            std::vector<int> right_max(height.size(), 0);
            right_max[height.size() - 1] = height[height.size() - 1];
            for (size_t i = height.size() - 2; i >= 0 ; --i) {
                right_max[i] = std::max(right_max[i+1], height[i]);
                if (i == 0) { break; }
            }

            for (size_t i = 0; i < height.size(); ++i) {
                result += std::min(left_max[i], right_max[i]) - height[i];
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_TRAPPING_RAIN_WATER_HPP
