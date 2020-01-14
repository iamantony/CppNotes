#include <boost/test/unit_test.hpp>
#include "algorithms/search/capture_surrounded_regions.hpp"

BOOST_AUTO_TEST_SUITE(TestCaptureSurroundedRegions)

BOOST_AUTO_TEST_CASE(empty_matrix)
{
    std::vector<std::vector<char>> matrix = {};
    const std::vector<std::vector<char>> expected = {};
    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_CASE(matrix_one_elem_one_island)
{
    std::vector<std::vector<char>> matrix = {{'O'}};
    const std::vector<std::vector<char>> expected = {{'O'}};
    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_CASE(matrix_one_elem_no_islands)
{
    std::vector<std::vector<char>> matrix = { { 'X' } };
    const std::vector<std::vector<char>> expected = {{'X'}};
    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_CASE(valid_matrix_no_islands)
{
    std::vector<std::vector<char>> matrix =
        { {'X', 'X', 'X'},
          {'X', 'X', 'X'},
          {'X', 'X', 'X'} };

    const std::vector<std::vector<char>> expected = matrix;
    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_CASE(valid_matrix_2x4_island_on_border)
{
    std::vector<std::vector<char>> matrix =
        { {'X', 'X', 'X', 'O'},
          {'X', 'X', 'X', 'O'} };

    const std::vector<std::vector<char>> expected = matrix;
    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_CASE(valid_matrix_4x4_have_islands)
{
    std::vector<std::vector<char>> matrix =
        { {'O', 'O', 'X', 'X'},
          {'O', 'O', 'X', 'X'},
          {'X', 'X', 'O', 'X'},
          {'X', 'X', 'X', 'O'}};

    const std::vector<std::vector<char>> expected =
        { {'O', 'O', 'X', 'X'},
          {'O', 'O', 'X', 'X'},
          {'X', 'X', 'X', 'X'},
          {'X', 'X', 'X', 'O'}};

    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_CASE(valid_matrix_8x5_have_two_islands)
{
    std::vector<std::vector<char>> matrix =
        {{'X','X','X','X','X','X','X','O'},
         {'X','O','O','O','O','X','X','O'},
         {'X','O','X','O','X','X','X','O'},
         {'X','O','O','O','O','X','O','X'},
         {'X','X','X','X','X','X','X','O'}};

    const std::vector<std::vector<char>> expected =
        {{'X','X','X','X','X','X','X','O'},
         {'X','X','X','X','X','X','X','O'},
         {'X','X','X','X','X','X','X','O'},
         {'X','X','X','X','X','X','X','X'},
         {'X','X','X','X','X','X','X','O'}};

    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_CASE(valid_matrix_4x3_have_island)
{
    std::vector<std::vector<char>> matrix =
        {{'O','O','X','O','O'},
         {'O','X','O','X','O'},
         {'O','X','X','X','O'}};

    const std::vector<std::vector<char>> expected =
        {{'O','O','X','O','O'},
         {'O','X','X','X','O'},
         {'O','X','X','X','O'}};

    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_CASE(valid_matrix_7x7_have_two_islands)
{
    std::vector<std::vector<char>> matrix =
        {{'X','X','X','X','X','X','X'},
         {'X','O','O','O','O','O','X'},
         {'X','O','X','X','X','O','X'},
         {'X','O','X','O','X','O','X'},
         {'X','O','X','X','X','O','X'},
         {'X','O','O','O','O','O','X'},
         {'X','X','X','X','X','X','X'}};

    const std::vector<std::vector<char>> expected =
        {{'X','X','X','X','X','X','X'},
         {'X','X','X','X','X','X','X'},
         {'X','X','X','X','X','X','X'},
         {'X','X','X','X','X','X','X'},
         {'X','X','X','X','X','X','X'},
         {'X','X','X','X','X','X','X'},
         {'X','X','X','X','X','X','X'}};

    Algo::Search::CaptureSurroundedRegions::capture(matrix);
    BOOST_CHECK(matrix == expected);
}

BOOST_AUTO_TEST_SUITE_END()
