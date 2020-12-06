#ifndef CPPNOTESMAIN_ROTTEN_ORANGES_HPP
#define CPPNOTESMAIN_ROTTEN_ORANGES_HPP

/*
https://leetcode.com/problems/rotting-oranges/
In a given grid, each cell can have one of three values:
- the value 0 representing an empty cell;
- the value 1 representing a fresh orange;
- the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1 instead.

Example 1:
Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because
rotting only happens 4-directionally.

Example 3:
Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

Note:
* 1 <= grid.length <= 10
* 1 <= grid[0].length <= 10
* grid[i][j] is only 0, 1, or 2.
*/

#include <vector>

namespace Algo::DS::Array {
    class RottenOranges {
        const int FO = 1;
        const int RT = 2;
        const int NR = 12;
        const std::vector<std::pair<int, int>> shifts = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        size_t num_of_rotten_oranges(
            std::vector<std::vector<int>>& grid,
            const size_t maxR,
            const size_t maxC)
        {
            size_t result = 0;
            for (size_t r = 0; r < maxR; ++r) {
                for (size_t c = 0; c < maxC; ++c) {
                    if (grid[r][c] == NR) { grid[r][c] = RT; }
                    if (grid[r][c] == RT) { ++result; }
                }
            }

            return result;
        }

        bool has_fresh_oranges(
            const std::vector<std::vector<int>>& grid,
            const size_t maxR,
            const size_t maxC)
        {
            for (size_t r = 0; r < maxR; ++r) {
                for (size_t c = 0; c < maxC; ++c) {
                    if (grid[r][c] == FO) { return true; }
                }
            }

            return false;
        }

    public:
        size_t minutes_when_all_oranges_become_rotten(std::vector<std::vector<int>>& grid) {
            if (grid.empty() || grid.front().empty()) { return -1; }

            const auto maxR = grid.size();
            const auto maxC = grid.front().size();

            auto rotten_oranges = num_of_rotten_oranges(grid, maxR, maxC);
            if (rotten_oranges == 0) {
                if (!has_fresh_oranges(grid, maxR, maxC)) { return 0; }

                return -1;
            }

            size_t result = 0;
            while (true) {
                for (size_t r = 0; r < maxR; ++r) {
                    for (size_t c = 0; c < maxC; ++c) {
                        if (grid[r][c] != RT) { continue; }

                        for (const auto& [rs, cs] : shifts) {
                            if ((r == 0 && rs < 0) || r + rs >= maxR) { continue; }
                            if ((c == 0 && cs < 0) || c + cs >= maxC) { continue; }

                            if (grid[r+rs][c+cs] == FO) { grid[r+rs][c+cs] = NR; }
                        }
                    }
                }

                const auto new_rotten_num = num_of_rotten_oranges(grid, maxR, maxC);
                if (new_rotten_num > rotten_oranges) {
                    rotten_oranges = new_rotten_num;
                    ++result;
                }
                else {
                    if (has_fresh_oranges(grid, maxR, maxC)) { return -1; }

                    break;
                }
            }

            return result;
        }
    };
}

#endif //CPPNOTESMAIN_ROTTEN_ORANGES_HPP
