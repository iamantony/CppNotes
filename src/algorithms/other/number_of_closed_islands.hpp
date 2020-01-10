#ifndef NUMBER_OF_CLOSED_ISLANDS_HPP
#define NUMBER_OF_CLOSED_ISLANDS_HPP

/*
https://leetcode.com/problems/number-of-closed-islands/
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally
connected group of 0s and a closed island is an island totally (all left, top, right, bottom)
surrounded by 1s.

Return the number of closed islands.

Example 1:
Input: grid =
 [[1,1,1,1,1,1,1,0],
  [1,0,0,0,0,1,1,0],
  [1,0,1,0,1,1,1,0],
  [1,0,0,0,0,1,0,1],
  [1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:
Input: grid =
 [[0,0,1,0,0],
  [0,1,0,1,0],
  [0,1,1,1,0]]
Output: 1

Example 3:
Input: grid =
 [[1,1,1,1,1,1,1],
  [1,0,0,0,0,0,1],
  [1,0,1,1,1,0,1],
  [1,0,1,0,1,0,1],
  [1,0,1,1,1,0,1],
  [1,0,0,0,0,0,1],
  [1,1,1,1,1,1,1]]
Output: 2

Constraints:
1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

#include <vector>

namespace Algo::Other {
    class NumberOfClosedIslands {
        static const int WATER = 1;
        static const int LAND = 0;

    public:
        // TC: O(n) where n is number of elements in input matrix
        // SC: O(n)
        static size_t calc_recursive(std::vector<std::vector<int>> m) {
            if (m.empty()) { return 0; }

            const auto maxRow = m.size();
            const auto maxCol = m[0].size();

            size_t numOfClosedIslands = 0;
            for (size_t r = 0; r < maxRow; ++r) {
                for (size_t c = 0; c < maxCol; ++c) {
                    if (m[r][c] != LAND) { continue; }

                    bool border_found = false;
                    search_neighbors_recursive(m, r, c, maxRow, maxCol, border_found);
                    if (!border_found) {
                        ++numOfClosedIslands;
                    }
                }
            }

            return numOfClosedIslands;
        }

    private:
        static void search_neighbors_recursive(
            std::vector<std::vector<int>>& m,
            size_t row, size_t col,
            const size_t& maxRow, const size_t& maxCol,
            bool& border_found)
        {
            if (row >= maxRow || col >= maxCol) {
                border_found = true;
                return;
            }

            if (m[row][col] != LAND) { return; }

            m[row][col] = WATER;

            if (col > 0) {
                search_neighbors_recursive(m, row, col - 1, maxRow, maxCol, border_found);
            }
            else {
                border_found = true;
            }

            if (row > 0) {
                search_neighbors_recursive(m, row - 1, col, maxRow, maxCol, border_found);
            }
            else {
                border_found = true;
            }

            search_neighbors_recursive(m, row, col + 1, maxRow, maxCol, border_found);
            search_neighbors_recursive(m, row + 1, col, maxRow, maxCol, border_found);
        }
    };
}

#endif //NUMBER_OF_CLOSED_ISLANDS_HPP
