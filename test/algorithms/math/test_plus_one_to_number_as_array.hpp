#ifndef TEST_PLUS_ONE_TO_NUMBER_AS_ARRAY_HPP
#define TEST_PLUS_ONE_TO_NUMBER_AS_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/plus_one_to_number_as_array.hpp"

BOOST_AUTO_TEST_CASE(test_potnaa_empty_arr)
{
    PlusOne::Solution solution;
    std::vector<int> digits = {};
    BOOST_CHECK(std::vector<int>() == solution.plusOne(digits));
}

BOOST_AUTO_TEST_CASE(test_potnaa_zero_num)
{
    PlusOne::Solution solution;
    std::vector<int> digits = {0};
    std::vector<int> expected = {1};
    BOOST_CHECK(expected == solution.plusOne(digits));
}

BOOST_AUTO_TEST_CASE(test_potnaa_simple_num)
{
    PlusOne::Solution solution;
    std::vector<int> digits = {1, 2, 3};
    std::vector<int> expected = {1, 2, 4};
    BOOST_CHECK(expected == solution.plusOne(digits));
}

BOOST_AUTO_TEST_CASE(test_potnaa_nine_on_the_end)
{
    PlusOne::Solution solution;
    std::vector<int> digits = {1, 2, 9};
    std::vector<int> expected = {1, 3, 0};
    BOOST_CHECK(expected == solution.plusOne(digits));
}

BOOST_AUTO_TEST_CASE(test_potnaa_nines_to_the_middle)
{
    PlusOne::Solution solution;
    std::vector<int> digits = {1, 9, 9};
    std::vector<int> expected = {2, 0, 0};
    BOOST_CHECK(expected == solution.plusOne(digits));
}

BOOST_AUTO_TEST_CASE(test_potnaa_all_nines)
{
    PlusOne::Solution solution;
    std::vector<int> digits = {9, 9, 9};
    std::vector<int> expected = {1, 0, 0, 0};
    BOOST_CHECK(expected == solution.plusOne(digits));
}

#endif // TEST_PLUS_ONE_TO_NUMBER_AS_ARRAY_HPP
