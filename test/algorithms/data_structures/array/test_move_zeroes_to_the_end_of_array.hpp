#ifndef TEST_MOVE_ZEROES_TO_THE_END_OF_ARRAY_HPP
#define TEST_MOVE_ZEROES_TO_THE_END_OF_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/move_zeroes_to_the_end_of_array.hpp"

BOOST_AUTO_TEST_CASE(test_mztea_empty_arr)
{
    MoveZerosToEnd::Solution solution;
    std::vector<int> digits = {};
    solution.moveZeroes(digits);
    BOOST_CHECK(digits.empty());
}

BOOST_AUTO_TEST_CASE(test_mztea_no_zeroes)
{
    MoveZerosToEnd::Solution solution;
    std::vector<int> digits = {1, 2};
    std::vector<int> expected = {1, 2};
    solution.moveZeroes(digits);
    BOOST_CHECK(expected == digits);
}

BOOST_AUTO_TEST_CASE(test_mztea_have_zeroes)
{
    MoveZerosToEnd::Solution solution;
    std::vector<int> digits = {0, 1, 0, 0, 2, 0};
    std::vector<int> expected = {1, 2, 0, 0, 0, 0};
    solution.moveZeroes(digits);
    BOOST_CHECK(expected == digits);
}

#endif // TEST_MOVE_ZEROES_TO_THE_END_OF_ARRAY_HPP
