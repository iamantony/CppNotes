#ifndef TEST_FIND_MAX_PRODUCT_OF_TWO_ELEMENTS_HPP
#define TEST_FIND_MAX_PRODUCT_OF_TWO_ELEMENTS_HPP

#include <limits>

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/find_max_product_of_two_elements.hpp"

BOOST_AUTO_TEST_CASE(test_fmpote_simple_test) {
    {
        std::vector<int> input { 9, 9 };
        long long expected = 81;
        BOOST_CHECK(expected == Algo::DS::Array::FindMaxProduct::Find(input));
    }

    {
        std::vector<int> input { 9, 8, 1 };
        long long expected = 72;
        BOOST_CHECK(expected == Algo::DS::Array::FindMaxProduct::Find(input));
    }

    {
        std::vector<int> input { 1, 2, 3 };
        long long expected = 6;
        BOOST_CHECK(expected == Algo::DS::Array::FindMaxProduct::Find(input));
    }

    {
        auto max = std::numeric_limits<int>::max();
        std::vector<int> input { 1, 2, 3, max, 5, max };
        long long expected =
                static_cast<long long>(max) * static_cast<long long>(max);
        BOOST_CHECK(expected == Algo::DS::Array::FindMaxProduct::Find(input));
    }

    {
        std::vector<int> input { 1, 2, 10, 7, 8, 7 };
        long long expected = 80;
        BOOST_CHECK(expected == Algo::DS::Array::FindMaxProduct::Find(input));
    }
}

#endif // TEST_FIND_MAX_PRODUCT_OF_TWO_ELEMENTS_HPP
