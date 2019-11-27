#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/max_consecutive_equal_elements.hpp"

BOOST_AUTO_TEST_SUITE(TestMaxConsecutiveEqualElements)

BOOST_AUTO_TEST_CASE(empty_arr)
{
    std::vector<int> array = {};
    BOOST_CHECK(0 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));
}

BOOST_AUTO_TEST_CASE(no_ones)
{
    std::vector<int> array = {0, 0, 0};
    BOOST_CHECK(0 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));
}

BOOST_AUTO_TEST_CASE(have_ones)
{
    std::vector<int> array = {0, 0, 0, 1};
    BOOST_CHECK(1 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));

    array = {1, 0, 0, 0, 1};
    BOOST_CHECK(1 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));

    array = {1, 0, 1, 1, 1, 0};
    BOOST_CHECK(3 == Algo::DS::Array::MaxConsecutiveElems::MaxOnes(array));
}

BOOST_AUTO_TEST_SUITE_END()
