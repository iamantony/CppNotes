#ifndef BASIC_MATRIX_MULTIPLICATION_HPP_
#define BASIC_MATRIX_MULTIPLICATION_HPP_

#include "types/matrix.hpp"

// Basic algorithm for matrix multiplication
// https://en.wikipedia.org/wiki/Matrix_multiplication
// @input: two matrices. Number of columns of first (left) matrix must be
// equal to number of rows of second (right) matrix.
// @output: result matrix
template<typename T>
DS::Matrix<T> BasicMatrixMultiplication(const DS::Matrix<T>& left,
        const DS::Matrix<T> right)
{
    if (left.empty() ||
            right.empty() ||
            left.getColsNum() != right.getRowsNum())
    {
        return DS::Matrix<T>();
    }

    size_t rows = left.getRowsNum();
    size_t cols = right.getColsNum();
    DS::Matrix<T> result(rows, cols, T());

    size_t limit = left.getColsNum();
    for (size_t r = 0; r < rows; ++r)
    {
        for (size_t c = 0; c < cols; ++c)
        {
            T value = T();
            for(size_t leftCol = 0, rightRow = 0; leftCol < limit;
                    ++leftCol, ++rightRow)
            {
                value += left.getValue(r, leftCol) *
                        right.getValue(rightRow, c);
            }

            result.setValue(r, c, value);
        }
    }

    return result;
}

#endif /* BASIC_MATRIX_MULTIPLICATION_HPP_ */
