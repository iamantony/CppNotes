#include <boost/test/unit_test.hpp>
#include "algorithms/search/number_of_islands.hpp"

BOOST_AUTO_TEST_SUITE(TestNumberOfIslands)

BOOST_AUTO_TEST_CASE(empty_matrix)
{
    const std::vector<std::vector<char>> matrix = {};
    BOOST_CHECK(0 == Algo::Search::NumberOfIslands::calc_recursive(matrix));
    BOOST_CHECK(0 == Algo::Search::NumberOfIslands::calc_ds(matrix));
}

BOOST_AUTO_TEST_CASE(matrix_one_elem_no_islands)
{
    const std::vector<std::vector<char>> matrix = { { 0 } };
    BOOST_CHECK(0 == Algo::Search::NumberOfIslands::calc_recursive(matrix));
    BOOST_CHECK(0 == Algo::Search::NumberOfIslands::calc_ds(matrix));
}

BOOST_AUTO_TEST_CASE(matrix_one_elem_have_islands)
{
    const std::vector<std::vector<char>> matrix = { { 1 } };
    BOOST_CHECK(1 == Algo::Search::NumberOfIslands::calc_recursive(matrix));
    BOOST_CHECK(1 == Algo::Search::NumberOfIslands::calc_ds(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_no_islands)
{
    const std::vector<std::vector<char>> matrix =
        { {0, 0, 0},
          {0, 0, 0},
          {0, 0, 0} };

    BOOST_CHECK(0 == Algo::Search::NumberOfIslands::calc_recursive(matrix));
    BOOST_CHECK(0 == Algo::Search::NumberOfIslands::calc_ds(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_2x4_have_islands)
{
    const std::vector<std::vector<char>> matrix =
        { {0, 0, 0, 1},
          {0, 0, 0, 1} };

    BOOST_CHECK(1 == Algo::Search::NumberOfIslands::calc_recursive(matrix));
    BOOST_CHECK(1 == Algo::Search::NumberOfIslands::calc_ds(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_4x5_have_islands)
{
    const std::vector<std::vector<char>> matrix =
        { {1, 1, 1, 1, 0},
          {1, 1, 0, 1, 0},
          {1, 1, 0, 0, 0},
          {0, 0, 0, 0, 0},};

    BOOST_CHECK(1 == Algo::Search::NumberOfIslands::calc_recursive(matrix));
    BOOST_CHECK(1 == Algo::Search::NumberOfIslands::calc_ds(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_4x4_have_islands)
{
    const std::vector<std::vector<char>> matrix =
        { {1, 1, 0, 0},
          {1, 1, 0, 0},
          {0, 0, 1, 0},
          {0, 0, 0, 1},};

    BOOST_CHECK(3 == Algo::Search::NumberOfIslands::calc_recursive(matrix));
    BOOST_CHECK(3 == Algo::Search::NumberOfIslands::calc_ds(matrix));
}

BOOST_AUTO_TEST_SUITE_END()
