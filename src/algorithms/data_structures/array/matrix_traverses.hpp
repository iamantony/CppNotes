#ifndef MATRIX_DIAGONAL_TRAVERSE_HPP
#define MATRIX_DIAGONAL_TRAVERSE_HPP

/*
// https://leetcode.com/problems/diagonal-traverse/description/
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

// https://leetcode.com/problems/spiral-matrix/description/
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
#include <iostream>

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

    enum class Direction
    {
        Left = 0,
        Down = 1,
        Right = 2,
        Up = 3
    };

    static std::vector<int> SpiralTraverse(
            std::vector< std::vector<int> >& matrix) {
        if (matrix.empty()) {
            return {};
        }

        size_t top = 0;
        size_t bottom = matrix.size();
        size_t left = 0;
        size_t right = matrix[0].size();
        Direction direction = Direction::Left;

        std::vector<int> result;
        result.reserve(matrix.size() * matrix[0].size());
        while (top < bottom && left < right) {
            switch(direction) {
                case Direction::Left: {
                    for (size_t i = left; i < right; ++i) {
                        result.push_back(matrix[top][i]);
                    }

                    ++top;
                    direction = Direction::Down;
                    break;
                }
                case Direction::Down: {
                    for (size_t i = top; i < bottom; ++i) {
                        result.push_back(matrix[i][right - 1]);
                    }

                    --right;
                    direction = Direction::Right;
                    break;
                }
                case Direction::Right: {
                    for (size_t i = right - 1; i >= left; --i) {
                        result.push_back(matrix[bottom - 1][i]);
                        if (i == 0) {
                            break;
                        }
                    }

                    --bottom;
                    direction = Direction::Up;
                    break;
                }
                case Direction::Up: {
                    for (size_t i = bottom - 1; i >= top; --i) {
                        result.push_back(matrix[i][left]);
                        if (i == 0) {
                            break;
                        }
                    }

                    ++left;
                    direction = Direction::Left;
                    break;
                }
                default:
                    break;
            }
        }

        return result;
    }
};

}

#endif // MATRIX_DIAGONAL_TRAVERSE_HPP
