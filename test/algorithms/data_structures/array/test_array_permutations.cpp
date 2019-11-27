#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/array_permutations.hpp"

BOOST_AUTO_TEST_SUITE(TestArrayPermutations)

BOOST_AUTO_TEST_CASE(empty_array)
{
    std::vector<int> array;
    std::vector<std::vector<int>> expected;
    BOOST_CHECK(expected == Algo::DS::Array::ArrayPermutations::GetAll(array));
}

BOOST_AUTO_TEST_CASE(array_with_one_elem)
{
    std::vector<int> array = {0};
    std::vector<std::vector<int>> expected = { {0} };
    BOOST_CHECK(expected == Algo::DS::Array::ArrayPermutations::GetAll(array));
}

BOOST_AUTO_TEST_CASE(array_with_two_elems)
{
    std::vector<int> array = {0, 1};
    std::vector<std::vector<int>> expected = { {0, 1}, {1, 0} };
    BOOST_CHECK(expected == Algo::DS::Array::ArrayPermutations::GetAll(array));
}

BOOST_AUTO_TEST_CASE(array_with_three_elems)
{
    std::vector<int> array = {0, 1, 2};
    std::vector<std::vector<int>> expected = { {0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                                               {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    BOOST_CHECK(expected == Algo::DS::Array::ArrayPermutations::GetAll(array));
}

BOOST_AUTO_TEST_CASE(array_with_three_non_unique_elems)
{
    std::vector<int> array = {1, 1, 2};
    std::vector<std::vector<int>> expected = { {1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    BOOST_CHECK(expected == Algo::DS::Array::ArrayPermutations::GetUnique(array));
}

BOOST_AUTO_TEST_SUITE_END()
