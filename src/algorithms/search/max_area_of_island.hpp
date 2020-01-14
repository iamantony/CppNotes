#ifndef MAX_AREA_OF_ISLAND_HPP
#define MAX_AREA_OF_ISLAND_HPP

/*
https://leetcode.com/problems/max-area-of-island/
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land)
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are
surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum
area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected
4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]

Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

#include <vector>
#include <stack>

namespace Algo::Search {
    class MaxAreaOfIsland {
        static const int WATER = 0;
        static const int LAND = 1;

        static size_t islandArea(
            std::vector<std::vector<int>>& m,
            size_t r, size_t c,
            const size_t& maxR, const size_t maxC)
        {
            if (r >= maxR || c >= maxC) { return 0; }
            if (m[r][c] != LAND) { return 0; }

            size_t area = 0;
            std::stack<std::pair<size_t, size_t>> stack;
            stack.push({r, c});
            while (!stack.empty()) {
                const auto [posR, posC] = stack.top();
                stack.pop();

                if (m[posR][posC] != LAND) { continue; }

                ++area;
                m[posR][posC] = WATER;

                std::vector<std::pair<size_t, size_t>> neighbors = {
                    {posR, (posC > 0 ? posC - 1 : maxC)},
                    {(posR > 0 ? posR - 1 : maxR), posC},
                    {posR, posC + 1},
                    {posR + 1, posC}
                };

                for (auto& [nR, nC] : neighbors) {
                    if (nR >= maxR || nC >= maxC || m[nR][nC] != LAND) { continue; }

                    stack.push({nR, nC});
                }
            }

            return area;
        }

    public:
        static size_t find(std::vector<std::vector<int>>& m) {
            if (m.empty()) { return 0; }

            const auto maxRow = m.size();
            const auto maxCol = m[0].size();

            size_t maxArea = 0;
            for (size_t r = 0; r < maxRow; ++r) {
                for (size_t c = 0; c < maxCol; ++c) {
                    maxArea = std::max(maxArea, islandArea(m, r, c, maxRow, maxCol));
                }
            }

            return maxArea;
        }
    };
}

#endif //MAX_AREA_OF_ISLAND_HPP
