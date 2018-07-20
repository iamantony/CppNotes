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
};

}

#endif // MATRIX_DIAGONAL_TRAVERSE_HPP
