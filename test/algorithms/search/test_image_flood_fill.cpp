#include <boost/test/unit_test.hpp>
#include "algorithms/search/image_flood_fill.hpp"

BOOST_AUTO_TEST_SUITE(TestImageFloodFill)

BOOST_AUTO_TEST_CASE(empty_image)
{
    const std::vector<std::vector<int>> image;
    const size_t pixelRow = 0;
    const size_t pixelCol = 0;
    const int newColor = 0;
    const std::vector<std::vector<int>> expected = image;
    BOOST_CHECK(
        expected == Algo::Search::ImageFloodFill::fill(image, pixelRow, pixelCol, newColor));
}

BOOST_AUTO_TEST_CASE(image_with_zero_columns)
{
    const std::vector<std::vector<int>> image(3, std::vector<int>());
    const size_t pixelRow = 0;
    const size_t pixelCol = 0;
    const int newColor = 0;
    const std::vector<std::vector<int>> expected = image;
    BOOST_CHECK(
        expected == Algo::Search::ImageFloodFill::fill(image, pixelRow, pixelCol, newColor));
}

BOOST_AUTO_TEST_CASE(invalid_pixel_coordinates)
{
    const std::vector<std::vector<int>> image = {
        {1, 2},
        {3, 4}
    };

    const size_t pixelRow = 10;
    const size_t pixelCol = 20;
    const int newColor = 0;
    const std::vector<std::vector<int>> expected = image;
    BOOST_CHECK(
        expected == Algo::Search::ImageFloodFill::fill(image, pixelRow, pixelCol, newColor));
}

BOOST_AUTO_TEST_CASE(fill_all_image_with_new_color)
{
    const std::vector<std::vector<int>> image = {
        {2, 2},
        {2, 2}
    };

    const size_t pixelRow = 1;
    const size_t pixelCol = 0;
    const int newColor = 8;
    const std::vector<std::vector<int>> expected = {
        {8, 8},
        {8, 8}
    };

    BOOST_CHECK(
        expected == Algo::Search::ImageFloodFill::fill(image, pixelRow, pixelCol, newColor));
}

BOOST_AUTO_TEST_CASE(fill_only_one_pixel)
{
    const std::vector<std::vector<int>> image = {
        {1, 2, 3},
        {20, 30, 40}
    };

    const size_t pixelRow = 0;
    const size_t pixelCol = 2;
    const int newColor = 100;
    const std::vector<std::vector<int>> expected = {
        {1, 2, 100},
        {20, 30, 40}
    };

    BOOST_CHECK(
        expected == Algo::Search::ImageFloodFill::fill(image, pixelRow, pixelCol, newColor));
}

BOOST_AUTO_TEST_CASE(leercode_test_case_1)
{
    const std::vector<std::vector<int>> image = {
        {0, 0, 0},
        {0, 1, 1}
    };

    const size_t pixelRow = 1;
    const size_t pixelCol = 1;
    const int newColor = 1;
    const std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 1, 1}
    };

    BOOST_CHECK(
        expected == Algo::Search::ImageFloodFill::fill(image, pixelRow, pixelCol, newColor));
}

BOOST_AUTO_TEST_SUITE_END()
