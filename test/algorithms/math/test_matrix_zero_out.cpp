#include <boost/test/unit_test.hpp>
#include "algorithms/math/matrix_zero_out.hpp"

BOOST_AUTO_TEST_SUITE(TestMatrixZeroOut)

BOOST_AUTO_TEST_CASE(empty_array)
{
    std::vector<std::vector<int>> matrix;
    MatrixZeroOut(matrix);

    BOOST_CHECK(std::vector<std::vector<int>>() == matrix);
}

BOOST_AUTO_TEST_CASE(array)
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4},
            {0, 5, 6, 7},
            {8, 9, 0, 10}};

    MatrixZeroOut(matrix);

    std::vector<std::vector<int>> expected = {{0, 2, 0, 4},
                {0, 0, 0, 0},
                {0, 0, 0, 0}};

    BOOST_CHECK(expected == matrix);
}

BOOST_AUTO_TEST_SUITE_END()
