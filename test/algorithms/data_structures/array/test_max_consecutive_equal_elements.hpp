#ifndef TEST_MAX_CONSECUTIVE_EQUAL_ELEMENTS_HPP
#define TEST_MAX_CONSECUTIVE_EQUAL_ELEMENTS_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/max_consecutive_equal_elements.hpp"

BOOST_AUTO_TEST_CASE(test_maxcee_empty_arr)
{
    std::vector<int> array = {};
    BOOST_CHECK(0 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));
}

BOOST_AUTO_TEST_CASE(test_maxcee_no_ones)
{
    std::vector<int> array = {0, 0, 0};
    BOOST_CHECK(0 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));
}

BOOST_AUTO_TEST_CASE(test_maxcee_have_ones)
{
    std::vector<int> array = {0, 0, 0, 1};
    BOOST_CHECK(1 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));

    array = {1, 0, 0, 0, 1};
    BOOST_CHECK(1 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));

    array = {1, 0, 1, 1, 1, 0};
    BOOST_CHECK(3 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));
}

#endif // TEST_MAX_CONSECUTIVE_EQUAL_ELEMENTS_HPP
