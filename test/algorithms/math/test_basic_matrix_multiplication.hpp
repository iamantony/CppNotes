#ifndef TEST_BASIC_MATRIX_MULTIPLICATION_HPP_
#define TEST_BASIC_MATRIX_MULTIPLICATION_HPP_

#include <boost/test/unit_test.hpp>

#include "types/matrix.hpp"
#include "algorithms/math/basic_matrix_multiplication.hpp"

BOOST_AUTO_TEST_CASE(test_bmm_empty_matrices)
{
    BOOST_CHECK(Matrix<int>() ==
            BasicMatrixMultiplication(Matrix<int>(), Matrix<int>()));

    Matrix<int> matrix(1, 1, 1);
    BOOST_CHECK(Matrix<int>() ==
            BasicMatrixMultiplication(matrix, Matrix<int>()));

    BOOST_CHECK(Matrix<int>() ==
            BasicMatrixMultiplication(Matrix<int>(), matrix));
}

BOOST_AUTO_TEST_CASE(test_bmm_matrices_with_wrong_dimensions)
{
    BOOST_CHECK(Matrix<int>() ==
        BasicMatrixMultiplication(Matrix<int>(1, 1, 1), Matrix<int>(2, 3, 1)));
}

BOOST_AUTO_TEST_CASE(test_bmm_square_matrices)
{
    Matrix<int> left(2, 2, 0);
    left.setRowValues(0, {1, 2});
    left.setRowValues(1, {3, 4});

    Matrix<int> right(2, 2, 0);
    right.setRowValues(0, {5, 6});
    right.setRowValues(1, {7, 8});

    Matrix<int> expected(2, 2, 0);
    expected.setRowValues(0, {19, 22});
    expected.setRowValues(1, {43, 50});

    BOOST_CHECK(expected == BasicMatrixMultiplication(left, right));
}

BOOST_AUTO_TEST_CASE(test_bmm_matrices)
{
    Matrix<int> left(2, 3, 0);
    left.setRowValues(0, {3, 8, 1});
    left.setRowValues(1, {-2, 5, 1});

    Matrix<int> right(3, 4, 0);
    right.setRowValues(0, {11, 9, 1, 0});
    right.setRowValues(1, {2, 0, 3, 15});
    right.setRowValues(2, {2, 6, 6, 7});

    Matrix<int> expected(2, 4, 0);
    expected.setRowValues(0, {51, 33, 33, 127});
    expected.setRowValues(1, {-10, -12, 19, 82});

    BOOST_CHECK(expected == BasicMatrixMultiplication(left, right));
}

#endif /* TEST_BASIC_MATRIX_MULTIPLICATION_HPP_ */
