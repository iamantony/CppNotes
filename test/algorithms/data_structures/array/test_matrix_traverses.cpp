#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/matrix_traverses.hpp"

BOOST_AUTO_TEST_SUITE(TestMatrixTraverses)

BOOST_AUTO_TEST_CASE(empty_matrix)
{
    std::vector<std::vector<int>> matrix;
    BOOST_CHECK(Algo::DS::Array::MatrixTraverse::DiagonalTraverse(matrix).empty());
    BOOST_CHECK(Algo::DS::Array::MatrixTraverse::SpiralTraverse(matrix).empty());
}

BOOST_AUTO_TEST_CASE(diagonal_traverse_valid_matrix)
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

BOOST_AUTO_TEST_CASE(spiral_traverse_valid_matrix)
{
    {
        std::vector<std::vector<int>> matrix = {
            {1}
        };

        std::vector<int> expected = {1};
        BOOST_CHECK(expected ==
                    Algo::DS::Array::MatrixTraverse::SpiralTraverse(matrix));
    }

    {
        std::vector<std::vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        std::vector<int> expected = {1, 2, 3, 6, 9, 8, 7, 4, 5};
        BOOST_CHECK(expected ==
                    Algo::DS::Array::MatrixTraverse::SpiralTraverse(matrix));
    }

    {
        std::vector<std::vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };

        std::vector<int> expected = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
        BOOST_CHECK(expected ==
                    Algo::DS::Array::MatrixTraverse::SpiralTraverse(matrix));
    }

    {
        std::vector<std::vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16},
            {17, 18, 19, 20}
        };

        std::vector<int> expected = {1, 2, 3, 4, 8, 12, 16, 20, 19, 18, 17,
                                    13, 9, 5, 6, 7, 11, 15, 14, 10};

        BOOST_CHECK(expected ==
                    Algo::DS::Array::MatrixTraverse::SpiralTraverse(matrix));
    }
}

BOOST_AUTO_TEST_SUITE_END()
