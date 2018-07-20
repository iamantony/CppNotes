#ifndef MATRIX_DIAGONAL_TRAVERSE_HPP
#define MATRIX_DIAGONAL_TRAVERSE_HPP

// https://leetcode.com/problems/diagonal-traverse/description/

/*
Given a matrix of M x N elements (M rows, N columns), return all elements
of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/

// https://leetcode.com/problems/spiral-matrix/description/

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of
the matrix in spiral order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <vector>
#include <algorithm>

namespace Algo::DS::Array {

class MatrixTraverse {
public:
    static std::vector<int> DiagonalTraverse(
            std::vector< std::vector<int> >& matrix) {
        std::vector<int> result;
        if (matrix.empty()) {
            return result;
        }

        const int maxRows = static_cast<int>(matrix.size());
        const int maxCols = static_cast<int>(matrix[0].size());
        size_t counter = 0;

        auto InsertTillValid = [&maxRows, &maxCols, &matrix](
                                std::vector<int>& vec, int r, int c)
        {
            while (r >= 0 && r < maxRows && c >= 0 && c < maxCols) {
                vec.push_back(
                    matrix[static_cast<size_t>(r)][static_cast<size_t>(c)]);

                --r, ++ c;
            }
        };

        auto AddToResult = [&result, &counter](std::vector<int>& vec) {
            if (counter % 2 != 0) {
                std::reverse(vec.begin(), vec.end());
            }

            result.insert(result.end(), vec.begin(), vec.end());
            ++counter;
        };

        for (int r = 0; r < maxRows; ++r) {
            std::vector<int> elements;
            int row = r, col = 0;
            InsertTillValid(elements, row, col);
            AddToResult(elements);
        }

        for (int c = 1; c < maxCols; ++c) {
            std::vector<int> elements;
            int row = maxRows - 1, col = c;
            InsertTillValid(elements, row, col);
            AddToResult(elements);
        }

        return result;
    }

    static std::vector<int> SpiralTraverse(
            std::vector< std::vector<int> >& matrix) {
        std::vector<int> result;
        if (matrix.empty()) {
            return result;
        }

        const size_t maxElements = matrix.size() * matrix[0].size();
        int row = 0, minRow = 0, maxRow = static_cast<int>(matrix.size()) - 1;
        int col = 0, minCol = 0, maxCol = static_cast<int>(matrix[0].size()) - 1;

        auto PushToResult = [&result, &matrix](const int& r, const int& c) {
            result.push_back(
                        matrix[static_cast<size_t>(r)][static_cast<size_t>(c)]);
        };

        while (result.size() < maxElements) {
            for (; result.size() < maxElements && col <= maxCol; ++col) {
                PushToResult(row, col);
            }

            --col, ++row;

            for (; result.size() < maxElements && row <= maxRow; ++row) {
                PushToResult(row, col);
            }

            --row, --col;
            --maxRow, --maxCol;

            for (; result.size() < maxElements && col >= minCol; --col) {
                PushToResult(row, col);
            }

            ++col, --row;

            for (; result.size() < maxElements && row > minRow; --row) {
                PushToResult(row, col);
            }

            ++minRow, ++minCol;
            row = minRow, col = minCol;
        }

        return result;
    }
};

}

#endif // MATRIX_DIAGONAL_TRAVERSE_HPP
