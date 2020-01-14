#include <boost/test/unit_test.hpp>
#include "algorithms/search/max_area_of_island.hpp"

BOOST_AUTO_TEST_SUITE(TestMaxAreaOfIsland)

BOOST_AUTO_TEST_CASE(empty_matrix)
{
    std::vector<std::vector<int>> matrix = {};
    BOOST_CHECK(0 == Algo::Other::MaxAreaOfIsland::find(matrix));
}

BOOST_AUTO_TEST_CASE(matrix_one_elem_no_islands)
{
    std::vector<std::vector<int>> matrix = { { 0 } };
    BOOST_CHECK(0 == Algo::Other::MaxAreaOfIsland::find(matrix));
}

BOOST_AUTO_TEST_CASE(matrix_one_elem_one_island)
{
    std::vector<std::vector<int>> matrix = { { 1 } };
    BOOST_CHECK(1 == Algo::Other::MaxAreaOfIsland::find(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_all_land)
{
    std::vector<std::vector<int>> matrix =
        { {1, 1, 1},
          {1, 1, 1},
          {1, 1, 1} };

    BOOST_CHECK(9 == Algo::Other::MaxAreaOfIsland::find(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_2x4_island_on_border)
{
    std::vector<std::vector<int>> matrix =
        { {1, 1, 1, 0},
          {1, 1, 1, 0} };

    BOOST_CHECK(6 == Algo::Other::MaxAreaOfIsland::find(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_4x4_two_equal_islands)
{
    std::vector<std::vector<int>> matrix =
        { {0, 0, 1, 1},
          {0, 0, 1, 1},
          {1, 1, 0, 1},
          {1, 1, 1, 0}};

    BOOST_CHECK(5 == Algo::Other::MaxAreaOfIsland::find(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_4x3_one_island)
{
    std::vector<std::vector<int>> matrix =
        {{0,0,1,0,0},
         {0,1,0,1,0},
         {0,1,1,1,0}};

    BOOST_CHECK(5 == Algo::Other::MaxAreaOfIsland::find(matrix));
}

BOOST_AUTO_TEST_CASE(valid_matrix_7x7_have_two_islands)
{
    std::vector<std::vector<int>> matrix =
        {{1,1,1,1,1,1,1},
         {1,0,0,0,0,0,1},
         {1,0,1,1,1,0,1},
         {1,0,1,0,1,0,1},
         {1,0,1,1,1,0,1},
         {1,0,0,0,0,0,1},
         {1,1,1,1,1,1,1}};

    BOOST_CHECK(24 == Algo::Other::MaxAreaOfIsland::find(matrix));
}

BOOST_AUTO_TEST_SUITE_END()
