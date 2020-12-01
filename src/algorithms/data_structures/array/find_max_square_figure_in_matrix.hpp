#ifndef CPPNOTESMAIN_FIND_MAX_SQUARE_FIGURE_IN_MATRIX_HPP
#define CPPNOTESMAIN_FIND_MAX_SQUARE_FIGURE_IN_MATRIX_HPP

/*
https://leetcode.com/problems/maximal-square/
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's
and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0

Constraints:
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 300
- matrix[i][j] is '0' or '1'.
*/

#include <vector>

namespace Algo::DS::Array {
    class FindMaxSquareInMatrix {
        size_t find_max_square(
            const std::vector<std::vector<char>>& matrix,
            const size_t& max_row,
            const size_t& max_col,
            const size_t& row,
            const size_t& col)
        {
            size_t length = 2;
            while (true) {
                const auto mr = row + length;
                const auto mc = col + length;
                if (mr > max_row || mc > max_col) { break; }

                auto have_zero = false;
                for (size_t j = col; j < mc; ++j) {
                    if (matrix[mr-1][j] == '0') {
                        have_zero = true;
                        break;
                    }
                }

                if (have_zero) { break; }

                for (size_t i = row; i < mr; ++i) {
                    if (matrix[i][mc-1] == '0') {
                        have_zero = true;
                        break;
                    }
                }

                if (have_zero) { break; }

                ++length;
            }

            return length - 1;
        }

    public:
        size_t find(std::vector<std::vector<char>>& matrix) {
            if (matrix.empty() || matrix.front().empty()) { return 0; }

            const auto max_row = matrix.size();
            const auto max_col = matrix.front().size();

            size_t max = 0;
            for (size_t i = 0; i < max_row; ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                    if (matrix[i][j] == '0') { continue; }

                    const auto found_square_length = find_max_square(matrix, max_row, max_col, i, j);
                    max = std::max(max, found_square_length);
                }
            }

            return max * max;
        }
    };
}

#endif //CPPNOTESMAIN_FIND_MAX_SQUARE_FIGURE_IN_MATRIX_HPP
