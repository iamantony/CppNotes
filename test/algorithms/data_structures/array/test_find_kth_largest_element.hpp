#ifndef TEST_FIND_KTH_LARGEST_ELEMENT_HPP
#define TEST_FIND_KTH_LARGEST_ELEMENT_HPP

#include <boost/test/unit_test.hpp>

#include <limits>
#include <algorithm>
#include <iostream>

#include "algorithms/data_structures/array/find_kth_largest_element.hpp"

BOOST_AUTO_TEST_CASE(test_fkthle_invalid_args)
{
    {
        std::vector<int> numbers = {};
        size_t k = 10;
        int expected = 0;
        BOOST_CHECK(expected ==
                    Algo::DS::Array::KthLargestElement::Find(numbers, k));
    }

    {
        std::vector<int> numbers = {1};
        size_t k = 10;
        int expected = 0;
        BOOST_CHECK(expected ==
                    Algo::DS::Array::KthLargestElement::Find(numbers, k));
    }
}

BOOST_AUTO_TEST_CASE(test_fkthle_valid_args)
{
    {
        std::vector<int> numbers = {1};
        size_t k = 1;
        int expected = 1;
        BOOST_CHECK(expected ==
                    Algo::DS::Array::KthLargestElement::Find(numbers, k));
    }

    {
        std::vector<int> numbers = {1, 2};
        size_t k = 1;
        int expected = 2;
        BOOST_CHECK(expected ==
                    Algo::DS::Array::KthLargestElement::Find(numbers, k));
    }

    {
        std::vector<int> numbers = {2, 1};
        size_t k = 1;
        int expected = 2;
        BOOST_CHECK(expected ==
                    Algo::DS::Array::KthLargestElement::Find(numbers, k));
    }

    {
        std::vector<int> numbers = {2, 1};
        size_t k = 2;
        int expected = 1;
        BOOST_CHECK(expected ==
                    Algo::DS::Array::KthLargestElement::Find(numbers, k));
    }

    {
        std::vector<int> numbers = {2, 1, 7, 3, 6, 5};
        size_t k = 4;
        int expected = 3;
        BOOST_CHECK(expected ==
                    Algo::DS::Array::KthLargestElement::Find(numbers, k));
    }

    {
        std::vector<int> numbers = {3,2,3,1,2,4,5,5,6};
        size_t k = 4;
        int expected = 4;
        BOOST_CHECK(expected ==
                    Algo::DS::Array::KthLargestElement::Find(numbers, k));
    }
}

BOOST_AUTO_TEST_CASE(test_fkthle_valid_args_rand) {
    std::mt19937 mt(42);
    std::uniform_int_distribution<size_t> distSize(0, 1000);
    std::uniform_int_distribution<int> distValues(
              std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    for (size_t i = 0; i < 100; ++i) {
        size_t size = distSize(mt);
        std::vector<int> nums(size, 0);
        for (int& value : nums) {
            value = distValues(mt);
        }

        std::uniform_int_distribution<size_t> distK(0, size);
        size_t k = distK(mt);

        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());
        const int expected = sortedNums[sortedNums.size() - k];
        const int result = Algo::DS::Array::KthLargestElement::Find(nums, k);
        if (expected != result) {
            std::cout << "WRONG" << std::endl;
        }
    }
}

#endif // TEST_FIND_KTH_LARGEST_ELEMENT_HPP
