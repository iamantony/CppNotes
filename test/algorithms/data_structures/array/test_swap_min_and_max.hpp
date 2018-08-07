#ifndef TEST_SWAP_MIN_AND_MAX_HPP
#define TEST_SWAP_MIN_AND_MAX_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/swap_min_and_max.hpp"

BOOST_AUTO_TEST_CASE(test_swmm_empty_arr)
{
    std::vector<int> v;
    std::vector<int> expected;
    Algo::DS::Array::SwapMinMax::Swap(v);
    BOOST_CHECK(v == expected);
}

BOOST_AUTO_TEST_CASE(test_swmm_arr_one_elem)
{
    std::vector<int> v = {0};
    std::vector<int> expected = {0};
    Algo::DS::Array::SwapMinMax::Swap(v);
    BOOST_CHECK(v == expected);
}

BOOST_AUTO_TEST_CASE(test_swmm_valid_arr)
{
    {
        std::vector<int> v = {0, 1};
        std::vector<int> expected = {1, 0};
        Algo::DS::Array::SwapMinMax::Swap(v);
        BOOST_CHECK(v == expected);
    }

    {
        std::vector<int> v = {1, 0};
        std::vector<int> expected = {0, 1};
        Algo::DS::Array::SwapMinMax::Swap(v);
        BOOST_CHECK(v == expected);
    }

    {
        std::vector<int> v = {7, 16, 9, 0, 1, 2, 3, 4, 7, 10};
        std::vector<int> expected = {7, 0, 9, 16, 1, 2, 3, 4, 7, 10};
        Algo::DS::Array::SwapMinMax::Swap(v);
        BOOST_CHECK(v == expected);
    }
}

#endif // TEST_SWAP_MIN_AND_MAX_HPP
