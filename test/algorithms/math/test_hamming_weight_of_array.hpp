#ifndef TEST_HAMMING_WEIGHT_OF_ARRAY_HPP
#define TEST_HAMMING_WEIGHT_OF_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/hamming_weight_of_array.hpp"

BOOST_AUTO_TEST_CASE(test_hwoa_zero)
{
    HammingWeightOfArray::Solution solution;
    BOOST_CHECK(std::vector<int>({0}) == solution.countBits(0));
}

BOOST_AUTO_TEST_CASE(test_hwoa_not_zero)
{
    HammingWeightOfArray::Solution solution;
    BOOST_CHECK(std::vector<int>({0,1,1,2,1,2}) == solution.countBits(5));
}

#endif // TEST_HAMMING_WEIGHT_OF_ARRAY_HPP
