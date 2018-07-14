#ifndef FAST_SUM_OF_MATRIX_HPP
#define FAST_SUM_OF_MATRIX_HPP

// https://leetcode.com/problems/range-sum-query-2d-immutable/description/

/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle
defined by its upper left corner (row1, col1) and
lower right corner (row2, col2).

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

#include <vector>

namespace Algo::DS::Array {

class NumMatrix {
public:
    NumMatrix(const std::vector<std::vector<int>>& matrix) {
        m_matrixSums = matrix;

        for (std::vector<int>& row : m_matrixSums) {
            int sum = 0;
            for (size_t i = 0; i < row.size(); ++i) {
                row[i] = sum + row[i];
                sum = row[i];
            }
        }
    }

    int sumRegion(const int& row1, const int& col1,
                  const int& row2, const int& col2)
    {
        if (m_matrixSums.size() == 0 || row1 < 0 || row2 < row1 ||
                col1 < 0 || col2 < col1) {
            return 0;
        }

        size_t sRow1 = static_cast<size_t>(row1);
        size_t sRow2 = static_cast<size_t>(row2);
        size_t sCol1 = static_cast<size_t>(col1);
        size_t sCol2 = static_cast<size_t>(col2);
        if (sRow1 >= m_matrixSums.size() ||
                sRow2 >= m_matrixSums.size() ||
                sCol1 >= m_matrixSums[0].size() ||
                sCol2 >= m_matrixSums[0].size())
        {
            return 0;
        }

        int sum = 0;
        for (size_t row = sRow1; row <= sRow2; ++row) {
            if (0 == sCol1) {
                sum += m_matrixSums[row][sCol2];
            }
            else {
                sum += m_matrixSums[row][sCol2] -
                        m_matrixSums[row][sCol1 - 1];
            }
        }

        return sum;
    }

private:
    std::vector<std::vector<int>> m_matrixSums;
};

}

#endif // FAST_SUM_OF_MATRIX_HPP
