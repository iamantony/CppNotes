#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/remove_elements_equal_to_value.hpp"

BOOST_AUTO_TEST_SUITE(TestRemoveElementsEqualToValue)

BOOST_AUTO_TEST_CASE(empty_arr)
{
    std::vector<int> digits = {};
    Algo::DS::Array::RemoveElement::MoveZerosToTheEnd(digits);
    BOOST_CHECK(digits.empty());
}

BOOST_AUTO_TEST_CASE(no_zeroes)
{
    std::vector<int> digits = {1, 2};
    std::vector<int> expected = {1, 2};
    Algo::DS::Array::RemoveElement::MoveZerosToTheEnd(digits);
    BOOST_CHECK(expected == digits);
}

BOOST_AUTO_TEST_CASE(have_zeroes)
{
    std::vector<int> digits = {0, 1, 0, 0, 2, 0};
    std::vector<int> expected = {1, 2, 0, 0, 0, 0};
    Algo::DS::Array::RemoveElement::MoveZerosToTheEnd(digits);
    BOOST_CHECK(expected == digits);
}

BOOST_AUTO_TEST_SUITE_END()
