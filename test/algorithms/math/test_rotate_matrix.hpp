#ifndef TEST_ROTATE_MATRIX_HPP_
#define TEST_ROTATE_MATRIX_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "algorithms/math/rotate_matrix.hpp"

auto areMatricesEqual = [](int** first, int** second, const int& size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (first[i][j] != second[i][j])
            {
                return false;
            }
        }
    }

    return true;
};

auto createMatrix = [](const int& size)
{
    int** matrix = new int*[size];
    for (int i = 0 ; i < size; ++i)
    {
        matrix[i] = new int[size];
    }

    return matrix;
};

auto deleteMatrix = [](int** matrix, const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
};

BOOST_AUTO_TEST_CASE(test_rot_matrix_2x2)
{
    int** matrix = createMatrix(2);
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    matrix[1][1] = 4;

    int** expected = createMatrix(2);
    expected[0][0] = 3;
    expected[0][1] = 1;
    expected[1][0] = 4;
    expected[1][1] = 2;

    RotateMatrix(matrix, 2);

    BOOST_CHECK(areMatricesEqual(matrix, expected, 2));

    deleteMatrix(matrix, 2);
    deleteMatrix(expected, 2);
}

BOOST_AUTO_TEST_CASE(test_rot_matrix_3x3)
{
    int** matrix = createMatrix(3);
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    int** expected = createMatrix(3);
    expected[0][0] = 7;
    expected[0][1] = 4;
    expected[0][2] = 1;
    expected[1][0] = 8;
    expected[1][1] = 5;
    expected[1][2] = 2;
    expected[2][0] = 9;
    expected[2][1] = 6;
    expected[2][2] = 3;

    RotateMatrix(matrix, 3);

    BOOST_CHECK(areMatricesEqual(matrix, expected, 3));

    deleteMatrix(matrix, 3);
    deleteMatrix(expected, 3);
}

BOOST_AUTO_TEST_CASE(test_rot_matrix_4x4)
{
    int** matrix = createMatrix(4);
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[0][3] = 4;
    matrix[1][0] = 5;
    matrix[1][1] = 6;
    matrix[1][2] = 7;
    matrix[1][3] = 8;
    matrix[2][0] = 9;
    matrix[2][1] = 10;
    matrix[2][2] = 11;
    matrix[2][3] = 12;
    matrix[3][0] = 13;
    matrix[3][1] = 14;
    matrix[3][2] = 15;
    matrix[3][3] = 16;

    int** expected = createMatrix(4);
    expected[0][0] = 13;
    expected[0][1] = 9;
    expected[0][2] = 5;
    expected[0][3] = 1;
    expected[1][0] = 14;
    expected[1][1] = 10;
    expected[1][2] = 6;
    expected[1][3] = 2;
    expected[2][0] = 15;
    expected[2][1] = 11;
    expected[2][2] = 7;
    expected[2][3] = 3;
    expected[3][0] = 16;
    expected[3][1] = 12;
    expected[3][2] = 8;
    expected[3][3] = 4;

    RotateMatrix(matrix, 4);

    BOOST_CHECK(areMatricesEqual(matrix, expected, 4));

    deleteMatrix(matrix, 4);
    deleteMatrix(expected, 4);
}

#endif /* TEST_ROTATE_MATRIX_HPP_ */
