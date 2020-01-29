#ifndef MIN_DISTANCE_TO_ZERO_IN_MATRIX_HPP
#define MIN_DISTANCE_TO_ZERO_IN_MATRIX_HPP

/*
https://leetcode.com/problems/01-matrix/
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Example 2:
Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]

Note:
- The number of elements of the given matrix will not exceed 10,000.
- There are at least one 0 in the given matrix.
- The cells are adjacent in only four directions: up, down, left and right.
*/

#include <vector>
#include <queue>
#include <unordered_set>

namespace Algo::Search {
    class MinDistanceInMatrix {
    public:
        static std::vector<std::vector<int>> findDFS(const std::vector<std::vector<int>>& m) {
            const auto maxRow = m.size();
            if (maxRow <= 0) { return m; }

            const auto maxCol = m[0].size();
            if (maxCol <= 0) { return m; }

            const auto MAX_DIST_VALUE = std::numeric_limits<int>::max();
            std::vector<std::vector<int>> dist(maxRow, std::vector<int>(maxCol, MAX_DIST_VALUE));

            std::queue<std::pair<size_t, size_t>> queue;
            for (size_t r = 0; r < maxRow; ++r) {
                for (size_t c = 0; c < maxCol; ++c) {
                    if (m[r][c] == 0) {
                        dist[r][c] = 0;
                        queue.push({r, c});
                    }
                }
            }

            while (!queue.empty()) {
                const auto [pRow, pCol] = queue.front();
                queue.pop();

                const auto pValue = dist[pRow][pCol];

                const std::vector<std::pair<size_t, size_t>> neighbors = {
                    {pRow > 0 ? pRow - 1 : maxRow, pCol},
                    {pRow, pCol + 1},
                    {pRow + 1, pCol},
                    {pRow, pCol > 0 ? pCol - 1: maxCol}
                };

                for (const auto& [nRow, nCol] : neighbors) {
                    if (nRow >= maxRow || nCol >= maxCol) { continue; }

                    if (dist[nRow][nCol] > pValue + 1) {
                        dist[nRow][nCol] = pValue + 1;
                        queue.push({nRow, nCol});
                    }
                }
            }

            return dist;
        }

        static std::vector<std::vector<int>> findDP(const std::vector<std::vector<int>>& m) {
            const auto maxRow = m.size();
            if (maxRow <= 0) { return m; }

            const auto maxCol = m[0].size();
            if (maxCol <= 0) { return m; }

            const auto MAX_DIST_VALUE = std::numeric_limits<int>::max() - 100000;
            std::vector<std::vector<int>> dist(maxRow, std::vector<int>(maxCol, MAX_DIST_VALUE));

            for (size_t r = 0; r < maxRow; ++r) {
                for (size_t c = 0; c < maxCol; ++c) {
                    if (m[r][c] == 0) {
                        dist[r][c] = 0;
                    }
                    else {
                        if (r > 0) {
                            dist[r][c] = std::min(dist[r][c], dist[r - 1][c] + 1);
                        }

                        if (c > 0) {
                            dist[r][c] = std::min(dist[r][c], dist[r][c - 1] + 1);
                        }
                    }
                }
            }

            for (size_t r = maxRow - 1; ; --r) {
                for (size_t c = maxCol - 1; ; --c) {
                    if (r < maxRow - 1) {
                        dist[r][c] = std::min(dist[r][c], dist[r + 1][c] + 1);
                    }

                    if (c < maxCol - 1) {
                        dist[r][c] = std::min(dist[r][c], dist[r][c + 1] + 1);
                    }

                    if (c == 0) {
                        break;
                    }
                }

                if (r == 0) {
                    break;
                }
            }

            return dist;
        }
    };
}

#endif //MIN_DISTANCE_TO_ZERO_IN_MATRIX_HPP
