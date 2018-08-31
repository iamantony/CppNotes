#ifndef TEST_DUPLICATES_IN_ARRAY_HPP
#define TEST_DUPLICATES_IN_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/duplicates_in_array.hpp"

BOOST_AUTO_TEST_CASE(test_dia_empty_arr)
{
    {
        std::vector<int> numbers = {};
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::Contains(numbers));
    }

    {
        std::vector<int> numbers = {};
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsWithinDistance(
                        numbers, distance));
    }

    {
        std::vector<int> numbers = {};
        int difference = 0;
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }
}

BOOST_AUTO_TEST_CASE(test_dia_no_duplicates)
{
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::Contains(numbers));
    }

    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsWithinDistance(
                        numbers, distance));
    }

    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 3};
        size_t distance = 4;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsWithinDistance(
                        numbers, distance));
    }

    {
        std::vector<int> numbers = {0};
        int difference = 0;
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {0, 1, 0};
        int difference = 0;
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {10, 14};
        int difference = 3;
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {10, 6};
        int difference = 3;
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {10, 6, 11};
        int difference = 3;
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {-1, -1};
        int difference = -1;
        size_t distance = 1;
        BOOST_CHECK(!Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }
}

BOOST_AUTO_TEST_CASE(test_dia_have_duplicates)
{
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 3};
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::Contains(numbers));
    }

    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 3};
        size_t distance = 3;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsWithinDistance(
                        numbers, distance));
    }

    {
        std::vector<int> numbers = {10, 7};
        int difference = 3;
        size_t distance = 1;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {10, 10};
        int difference = 3;
        size_t distance = 1;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {10, 13};
        int difference = 3;
        size_t distance = 1;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {0, 1, 0};
        int difference = 1;
        size_t distance = 1;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {0, 3, 6, 9, 12};
        int difference = 3;
        size_t distance = 3;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {0, std::numeric_limits<int>::max()};
        int difference = std::numeric_limits<int>::max();
        size_t distance = 1;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {1, 3, 1};
        int difference = 1;
        size_t distance = 2;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }

    {
        std::vector<int> numbers = {-2147483648, -2147483647};
        int difference = 3;
        size_t distance = 3;
        BOOST_CHECK(Algo::DS::Array::DuplicatesInArray::ContainsNearbyAlmostDuplicates(
                        numbers, difference, distance));
    }
}

#endif // TEST_DUPLICATES_IN_ARRAY_HPP
