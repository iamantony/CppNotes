#ifndef STRASSEN_MATRIX_MULTIPLICATION_HPP_
#define STRASSEN_MATRIX_MULTIPLICATION_HPP_

#include "types/matrix.hpp"

// TODO:
// - add SubMatrix class for representing sub-matrices (store pointer to
// matrix, size of the sub-matrix and start point). Implement addition,
// subtraction, raw copy to separate matrix object.
// - implement Strassen algorithm

// Strassen algorithm for matrix multiplication

// @input: two square matrices. Size of the matrix should be power of 2.
// @output: result matrix
template<typename T>
Matrix<T> StrassenMatrixMultiplication(const Matrix<T>& left,
        const Matrix<T> right)
{

    return left + right;
}

#endif /* STRASSEN_MATRIX_MULTIPLICATION_HPP_ */
