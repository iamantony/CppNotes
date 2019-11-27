#include <boost/test/unit_test.hpp>
#include "algorithms/math/hamming_weight_of_array.hpp"

BOOST_AUTO_TEST_SUITE(TestHammingWeightOfArray)

BOOST_AUTO_TEST_CASE(zero_elements)
{
    HammingWeightOfArray::Solution solution;
    BOOST_CHECK(std::vector<int>({0}) == solution.countBits(0));
}

BOOST_AUTO_TEST_CASE(non_zero)
{
    HammingWeightOfArray::Solution solution;
    BOOST_CHECK(std::vector<int>({0,1,1,2,1,2}) == solution.countBits(5));
}

BOOST_AUTO_TEST_SUITE_END()
