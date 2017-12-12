#ifndef MATRIX_ZERO_OUT_HPP_
#define MATRIX_ZERO_OUT_HPP_

// https://leetcode.com/problems/set-matrix-zeroes/description/
// Write an algorithm such that if an element in an MxN matrix is 0, its
// entire row and column are set to 0

#include <vector>
#include <unordered_set>
#include <algorithm>

template<typename T>
void MatrixZeroOut(std::vector<std::vector<T>>& matrix)
{
    std::unordered_set<size_t> zeroRows, zeroCols;
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                zeroRows.insert(i);
                zeroCols.insert(j);
            }
        }
    }

    for (const size_t& row : zeroRows)
    {
        std::fill(matrix[row].begin(), matrix[row].end(), 0);
    }

    for (const size_t& col : zeroCols)
    {
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            matrix[i][col] = 0;
        }
    }
}

#endif /* MATRIX_ZERO_OUT_HPP_ */
