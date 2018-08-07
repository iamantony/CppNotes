#ifndef CONTAINER_WITH_MOST_WATER_HPP
#define CONTAINER_WITH_MOST_WATER_HPP

/*
https://leetcode.com/problems/container-with-most-water/description/

Given n non-negative integers a1, a2, ..., an , where each represents a point
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include <vector>
#include <algorithm>

namespace Algo::Math {

class ContainerWithMostWater {
public:
    static int Search(const std::vector<int>& c) {
        if (c.size() < 2) {
            return 0;
        }

        int maxArea = 0;
        size_t left = 0, right = c.size() - 1;
        while (left < right) {
            maxArea = std::max(maxArea,
                std::min(c[left], c[right]) * static_cast<int>(right - left));
            if (c[left] < c[right]) {
                ++left;
            }
            else {
                --right;
            }
        }

        return maxArea;
    }
};

}

#endif // CONTAINER_WITH_MOST_WATER_HPP
