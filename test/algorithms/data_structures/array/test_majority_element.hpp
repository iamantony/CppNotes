#ifndef TEST_MAJORITY_ELEMENT_HPP
#define TEST_MAJORITY_ELEMENT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/majority_element.hpp"

BOOST_AUTO_TEST_CASE(test_majelem_diff_arrays)
{
    {
        std::vector<int> nums = {0};
        int expected = 0;
        BOOST_CHECK(expected == Algo::DS::Array::MajorityElement::Find(nums));
    }

    {
        std::vector<int> nums = {0, 0};
        int expected = 0;
        BOOST_CHECK(expected == Algo::DS::Array::MajorityElement::Find(nums));
    }

    {
        std::vector<int> nums = {0, 1, 1};
        int expected = 1;
        BOOST_CHECK(expected == Algo::DS::Array::MajorityElement::Find(nums));
    }

    {
        std::vector<int> nums = {0, 1, 0, 1, 0};
        int expected = 0;
        BOOST_CHECK(expected == Algo::DS::Array::MajorityElement::Find(nums));
    }

    {
        std::vector<int> nums = {0, 0, 0, 1, 1};
        int expected = 0;
        BOOST_CHECK(expected == Algo::DS::Array::MajorityElement::Find(nums));
    }

    {
        std::vector<int> nums = {1, 2, 3, 4, 4};
        int expected = -1;
        BOOST_CHECK(expected == Algo::DS::Array::MajorityElement::Find(nums));
    }

    {
        std::vector<int> nums = {512766168, 717383758, 5, 126144732, 5, 573799007, 5, 5, 5, 405079772};
        int expected = -1;
        BOOST_CHECK(expected == Algo::DS::Array::MajorityElement::Find(nums));
    }
}

#endif // TEST_MAJORITY_ELEMENT_HPP
