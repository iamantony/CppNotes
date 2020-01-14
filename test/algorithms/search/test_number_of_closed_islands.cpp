#include <boost/test/unit_test.hpp>
#include "algorithms/search/number_of_closed_islands.hpp"

BOOST_AUTO_TEST_SUITE(TestNumberOfClosedIslands)

BOOST_AUTO_TEST_CASE(empty_matrix)
{
    const std::vector<std::vector<int>> matrix = {};
    BOOST_CHECK(0 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_CASE(matrix_one_elem_one_island)
{
    const std::vector<std::vector<int>> matrix = { { 0 } };
    BOOST_CHECK(0 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_CASE(matrix_one_elem_no_islands)
{
    const std::vector<std::vector<int>> matrix = { { 1 } };
    BOOST_CHECK(0 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_no_islands)
{
    const std::vector<std::vector<int>> matrix =
        { {1, 1, 1},
          {1, 1, 1},
          {1, 1, 1} };

    BOOST_CHECK(0 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_2x4_island_on_border)
{
    const std::vector<std::vector<int>> matrix =
        { {1, 1, 1, 0},
          {1, 1, 1, 0} };

    BOOST_CHECK(0 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_4x4_have_islands)
{
    const std::vector<std::vector<int>> matrix =
        { {0, 0, 1, 1},
          {0, 0, 1, 1},
          {1, 1, 0, 1},
          {1, 1, 1, 0},};

    BOOST_CHECK(1 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_8x5_have_two_islands)
{
    const std::vector<std::vector<int>> matrix =
        {{1,1,1,1,1,1,1,0},
         {1,0,0,0,0,1,1,0},
         {1,0,1,0,1,1,1,0},
         {1,0,0,0,0,1,0,1},
         {1,1,1,1,1,1,1,0}};

    BOOST_CHECK(2 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_4x3_have_island)
{
    const std::vector<std::vector<int>> matrix =
        {{0,0,1,0,0},
         {0,1,0,1,0},
         {0,1,1,1,0}};

    BOOST_CHECK(1 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_7x7_have_two_islands)
{
    const std::vector<std::vector<int>> matrix =
        {{1,1,1,1,1,1,1},
         {1,0,0,0,0,0,1},
         {1,0,1,1,1,0,1},
         {1,0,1,0,1,0,1},
         {1,0,1,1,1,0,1},
         {1,0,0,0,0,0,1},
         {1,1,1,1,1,1,1}};

    BOOST_CHECK(2 == Algo::Search::NumberOfClosedIslands::calc_recursive(matrix));
}

BOOST_AUTO_TEST_SUITE_END()
