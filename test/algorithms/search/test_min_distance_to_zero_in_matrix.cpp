#include <boost/test/unit_test.hpp>
#include "algorithms/search/min_distance_to_zero_in_matrix.hpp"

BOOST_AUTO_TEST_SUITE(TestMinDistanceToZeroInMatrix)

    BOOST_AUTO_TEST_CASE(empty_matrix)
    {
        const std::vector<std::vector<int>> matrix;
        const std::vector<std::vector<int>> expected = matrix;
        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDFS(matrix));
        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDP(matrix));
    }

    BOOST_AUTO_TEST_CASE(matrix_with_zero_columns)
    {
        const std::vector<std::vector<int>> matrix(3, std::vector<int>());
        const std::vector<std::vector<int>> expected = matrix;
        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDFS(matrix));
        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDP(matrix));
    }

    BOOST_AUTO_TEST_CASE(leercode_test_case_1)
    {
        const std::vector<std::vector<int>> matrix = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        };

        const std::vector<std::vector<int>> expected = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        };

        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDFS(matrix));
        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDP(matrix));
    }

    BOOST_AUTO_TEST_CASE(leercode_test_case_2)
    {
        const std::vector<std::vector<int>> matrix = {
            {0, 0, 0},
            {0, 1, 0},
            {1, 1, 1}
        };

        const std::vector<std::vector<int>> expected = {
            {0, 0, 0},
            {0, 1, 0},
            {1, 2, 1}
        };

        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDFS(matrix));
        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDP(matrix));
    }

    BOOST_AUTO_TEST_CASE(long_sequence_of_ones)
    {
        const std::vector<std::vector<int>> matrix = {
            {0, 0, 1, 1, 1, 0},
            {0, 1, 1, 1, 1, 0}
        };

        const std::vector<std::vector<int>> expected = {
            {0, 0, 1, 2, 1, 0},
            {0, 1, 2, 2, 1, 0}
        };

        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDFS(matrix));
        BOOST_CHECK(expected == Algo::Search::MinDistanceInMatrix::findDP(matrix));
    }

BOOST_AUTO_TEST_SUITE_END()
