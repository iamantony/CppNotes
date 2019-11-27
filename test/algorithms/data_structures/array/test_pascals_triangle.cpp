#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/pascals_triangle.hpp"

BOOST_AUTO_TEST_SUITE(TestPascalTriangles)

BOOST_AUTO_TEST_CASE(invalid_row_num)
{
    const std::vector<std::vector<int>> expected;
    BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::Generate(-1));
    BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::Generate(0));
}

BOOST_AUTO_TEST_CASE(valid_row_num)
{
    {
        const std::vector<std::vector<int>> expected = {{1}};
        BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::Generate(1));
    }

    {
        const std::vector<std::vector<int>> expected = {
            {1},
            {1, 1}
        };

        BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::Generate(2));
    }

    {
        const std::vector<std::vector<int>> expected = {
            {1},
            {1, 1},
            {1, 2, 1}
        };

        BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::Generate(3));
    }

    {
        const std::vector<std::vector<int>> expected = {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1}
        };

        BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::Generate(4));
    }

    {
        const std::vector<std::vector<int>> expected = {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1}
        };

        BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::Generate(5));
    }
}

BOOST_AUTO_TEST_CASE(rowgen_invalid_row_num) {
    const std::vector<int> expected;
    BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::GenerateRow(-1));
    BOOST_CHECK(expected == Algo::DS::Array::PascalsTriangle::GenerateRow(-85));
}

BOOST_AUTO_TEST_CASE(rowgen_valid_row_num) {
    {
        const std::vector<int> expected = {1};
        BOOST_CHECK(expected ==
                    Algo::DS::Array::PascalsTriangle::GenerateRow(0));
    }

    {
        const std::vector<int> expected = {1, 1};
        BOOST_CHECK(expected ==
                    Algo::DS::Array::PascalsTriangle::GenerateRow(1));
    }

    {
        const std::vector<int> expected = {1, 2, 1};
        BOOST_CHECK(expected ==
                    Algo::DS::Array::PascalsTriangle::GenerateRow(2));
    }

    {
        const std::vector<int> expected = {1, 4, 6, 4, 1};
        BOOST_CHECK(expected ==
                    Algo::DS::Array::PascalsTriangle::GenerateRow(4));
    }
}

BOOST_AUTO_TEST_SUITE_END()
