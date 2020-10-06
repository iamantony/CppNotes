#ifndef CPPNOTESMAIN_COLLECT_MAX_GOLD_FROM_GRID_HPP
#define CPPNOTESMAIN_COLLECT_MAX_GOLD_FROM_GRID_HPP

/*
https://leetcode.com/problems/path-with-maximum-gold/
In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of
gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:
- Every time you are located in a cell you will collect all the gold in that cell.
- From your position you can walk one step to the left, right, up or down.
- You can't visit the same cell more than once.
- Never visit a cell with 0 gold.
- You can start and stop collecting gold from any position in the grid that has some gold.


Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

Constraints:
- 1 <= grid.length, grid[i].length <= 15
- 0 <= grid[i][j] <= 100
- There are at most 25 cells containing gold.
*/

#include <vector>
#include <stack>

namespace Algo::DP {
    class CollectMaxGold {
        const int EMPTY = 0;

        struct Cell {
            size_t r = 0;
            size_t c = 0;
            bool checked = false;
        };

        size_t m = 0;
        size_t n = 0;

        std::vector<std::pair<size_t, size_t>> find_all_gold_cells(
            const std::vector<std::vector<int>>& grid,
            const std::vector<std::vector<bool>>& visited_grid)
        {
            std::vector<std::pair<size_t, size_t>> result;
            for (size_t i = 0; i < m; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    if (grid[i][j] != EMPTY) {
                        const auto neighbors = find_neighbor_gold_cell(grid, visited_grid, i, j);
                        if (neighbors.size() > 2) { continue; }

                        result.push_back({i, j});
                    }
                }
            }

            return result;
        }

        std::vector<std::pair<size_t, size_t>> find_neighbor_gold_cell(
            const std::vector<std::vector<int>>& grid,
            const std::vector<std::vector<bool>>& visited_grid,
            const size_t r,
            const size_t c)
        {
            std::vector<std::pair<size_t, size_t>> result;
            if (r > 0 && grid[r-1][c] != EMPTY && !visited_grid[r-1][c]) {
                result.push_back({r-1, c});
            }

            if (c < n - 1 && grid[r][c+1] != EMPTY && !visited_grid[r][c+1]) {
                result.push_back({r, c+1});
            }

            if (r < m - 1 && grid[r+1][c] != EMPTY && !visited_grid[r+1][c]) {
                result.push_back({r+1, c});
            }

            if (c > 0 && grid[r][c-1] != EMPTY && !visited_grid[r][c-1]) {
                result.push_back({r, c-1});
            }

            return result;
        }

        int count_visited_gold(
            const std::vector<std::vector<int>>& grid,
            const std::vector<std::vector<bool>>& visited_grid)
        {
            int result = 0;
            for (size_t i = 0; i < m; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    if (visited_grid[i][j]) {
                        result += grid[i][j];
                    }
                }
            }

            return result;
        }

    public:
        int getMaximumGold(const std::vector<std::vector<int>>& grid) {
            if (grid.empty() || grid.front().empty()) { return 0; }

            m = grid.size();
            n = grid.front().size();

            int max_gold = 0;
            std::vector<bool> row_line(n, false);
            std::vector<std::vector<bool>> visited_grid(m, row_line);

            const auto gold_cells = find_all_gold_cells(grid, visited_grid);
            for (size_t i = 0; i < gold_cells.size(); ++i) {
                std::stack<Cell> path;
                path.push({gold_cells[i].first, gold_cells[i].second, false});
                while (!path.empty()) {
                    const auto cr = path.top().r;
                    const auto cc = path.top().c;
                    if (path.top().checked) {
                        visited_grid[cr][cc] = false;
                        path.pop();
                        continue;
                    }

                    visited_grid[cr][cc] = true;
                    path.top().checked = true;

                    const auto neighbors = find_neighbor_gold_cell(grid, visited_grid, cr, cc);
                    if (!neighbors.empty()) {
                        for (const auto& [nr, nc] : neighbors) {
                            path.push({nr, nc, false});
                        }
                    }
                    else {
                        max_gold = std::max(max_gold, count_visited_gold(grid, visited_grid));
                        visited_grid[cr][cc] = false;
                        path.pop();
                    }
                }
            }

            return max_gold;
        }
    };
}

#endif //CPPNOTESMAIN_COLLECT_MAX_GOLD_FROM_GRID_HPP
