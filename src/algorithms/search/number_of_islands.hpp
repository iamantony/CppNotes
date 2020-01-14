#ifndef NUMBER_OF_ISLANDS_HPP
#define NUMBER_OF_ISLANDS_HPP

#include <array>
#include <unordered_set>
#include "types/ds/disjoint_set.hpp"

/*
https://leetcode.com/problems/number-of-islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is
surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110
11010
11000
00000

Output: 1

Example 2:
11000
11000
00100
00011

Output: 3
*/

namespace Algo::Other {
    class NumberOfIslands {
    public:
        // TC: O(n) where n is number of elements in input matrix
        // SC: O(n) (because of recursion)
        static size_t calc_recursive(std::vector<std::vector<char>> m) {
            if (m.empty()) { return 0; }

            const auto maxRow = m.size();
            const auto maxCol = m[0].size();

            size_t numOfIslands = 0;
            for (size_t r = 0; r < maxRow; ++r) {
                for (size_t c = 0; c < maxCol; ++c) {
                    if (m[r][c] != 1) { continue; }

                    ++numOfIslands;
                    search_neighbors_recursive(m, r, c, maxRow, maxCol);
                }
            }

            return numOfIslands;
        }

        // TC: O(n) where n is number of elements in input matrix
        // SC: O(n)
        static size_t calc_ds(const std::vector<std::vector<char>>& m) {
            if (m.empty()) { return 0; }

            const int rows = static_cast<int>(m.size());
            const int cols = static_cast<int>(m[0].size());

            Types::DS::DisjointSet ds(static_cast<size_t>(rows * cols));

            auto isValidPos = [rows, cols](int r, int c) {
                return r >= 0 && r < rows && c >= 0 && c < cols;
            };

            auto getMatrixValue = [&m](int r, int c) {
                return m[static_cast<size_t>(r)][static_cast<size_t>(c)];
            };

            auto dsIndex = [cols](int r, int c) {
                return static_cast<size_t>(r * cols + c);
            };

            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    if (getMatrixValue(r, c) != 1) { continue; }

                    static const size_t prevNeighbors = 2;
                    const std::array<int, 2> neighborsRow = {r, r - 1};
                    const std::array<int, 2> neighborsCol = {c - 1, c};

                    for (size_t n = 0; n < prevNeighbors; ++n) {
                        const auto nR = neighborsRow[n];
                        const auto nC = neighborsCol[n];
                        if (!isValidPos(nR, nC) || getMatrixValue(nR, nC) != 1) { continue; }

                        ds.makeUnion(dsIndex(nR, nC), dsIndex(r, c));
                    }
                }
            }

            std::unordered_set<size_t> uniqueParents;
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    if (getMatrixValue(r, c) != 1) { continue; }

                    uniqueParents.insert(ds.parent(dsIndex(r, c)));
                }
            }

            return uniqueParents.size();
        }

    private:
        static void search_neighbors_recursive(
            std::vector<std::vector<char>>& m,
            size_t row, size_t col,
            const size_t& maxRow, const size_t& maxCol)
        {
            if (row >= maxRow || col >= maxCol) { return; }
            if (m[row][col] != 1) { return; }

            m[row][col] = 0;
            if (col > 0) { search_neighbors_recursive(m, row, col - 1, maxRow, maxCol); }
            if (row > 0) { search_neighbors_recursive(m, row - 1, col, maxRow, maxCol); }
            search_neighbors_recursive(m, row, col + 1, maxRow, maxCol);
            search_neighbors_recursive(m, row + 1, col, maxRow, maxCol);
        }
    };
}

#endif //NUMBER_OF_ISLANDS_HPP
