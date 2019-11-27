#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/plus_one_to_number_as_array.hpp"

BOOST_AUTO_TEST_SUITE(TestPlusOneToNumberAsArray)

BOOST_AUTO_TEST_CASE(empty_arr)
{
    std::vector<int> digits = {};
    BOOST_CHECK(std::vector<int>() == Algo::DS::Array::PlusOneToVector::Add(digits));
}

BOOST_AUTO_TEST_CASE(zero_num)
{
    std::vector<int> digits = {0};
    std::vector<int> expected = {1};
    BOOST_CHECK(expected == Algo::DS::Array::PlusOneToVector::Add(digits));
}

BOOST_AUTO_TEST_CASE(simple_num)
{
    std::vector<int> digits = {1, 2, 3};
    std::vector<int> expected = {1, 2, 4};
    BOOST_CHECK(expected == Algo::DS::Array::PlusOneToVector::Add(digits));
}

BOOST_AUTO_TEST_CASE(nine_on_the_end)
{
    std::vector<int> digits = {1, 2, 9};
    std::vector<int> expected = {1, 3, 0};
    BOOST_CHECK(expected == Algo::DS::Array::PlusOneToVector::Add(digits));
}

BOOST_AUTO_TEST_CASE(nines_to_the_middle)
{
    std::vector<int> digits = {1, 9, 9};
    std::vector<int> expected = {2, 0, 0};
    BOOST_CHECK(expected == Algo::DS::Array::PlusOneToVector::Add(digits));
}

BOOST_AUTO_TEST_CASE(nines_on_edges)
{
    std::vector<int> digits = {9, 0, 9};
    std::vector<int> expected = {9, 1, 0};
    BOOST_CHECK(expected == Algo::DS::Array::PlusOneToVector::Add(digits));
}

BOOST_AUTO_TEST_CASE(all_nines)
{
    std::vector<int> digits = {9, 9, 9};
    std::vector<int> expected = {1, 0, 0, 0};
    BOOST_CHECK(expected == Algo::DS::Array::PlusOneToVector::Add(digits));
}

BOOST_AUTO_TEST_CASE(extra_zero)
{
    std::vector<int> digits = {0, 2, 9};
    std::vector<int> expected = {3, 0};
    BOOST_CHECK(expected == Algo::DS::Array::PlusOneToVector::Add(digits));
}

BOOST_AUTO_TEST_SUITE_END()
