#ifndef TEST_MATRIX_DIAGONAL_TRAVERSE_HPP
#define TEST_MATRIX_DIAGONAL_TRAVERSE_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/matrix_diagonal_traverse.hpp"

BOOST_AUTO_TEST_CASE(test_mdt_empty_matrix)
{
    std::vector<std::vector<int>> matrix;
    BOOST_CHECK(Algo::DS::Array::MatrixTraverse::DiagonalTraverse(matrix).empty());
}

BOOST_AUTO_TEST_CASE(test_mdt_valid_matrix)
{
    {
        std::vector<std::vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        std::vector<int> expected = {1, 2, 4, 7, 5, 3, 6, 8, 9};

        BOOST_CHECK(expected ==
                    Algo::DS::Array::MatrixTraverse::DiagonalTraverse(matrix));
    }

    {
        std::vector<std::vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16},
            {17, 18, 19, 20}
        };

        std::vector<int> expected = {1, 2, 5, 9, 6, 3, 4, 7, 10, 13, 17, 14,
                                     11, 8, 12, 15, 18, 19, 16, 20};

        BOOST_CHECK(expected ==
                    Algo::DS::Array::MatrixTraverse::DiagonalTraverse(matrix));
    }
}

#endif // TEST_MATRIX_DIAGONAL_TRAVERSE_HPP
