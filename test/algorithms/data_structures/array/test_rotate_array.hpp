#ifndef TEST_ROTATE_ARRAY_HPP
#define TEST_ROTATE_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/rotate_array.hpp"

BOOST_AUTO_TEST_CASE(test_rotarr_empty)
{
    std::vector<int> nums;
    std::vector<int> expected;

    {
        Algo::DS::Array::RotateArray::rotatePlainArray(nums, 0);
        BOOST_CHECK(nums == expected);

        Algo::DS::Array::RotateArray::rotateViaJumps(nums, 0);
        BOOST_CHECK(nums == expected);

        Algo::DS::Array::RotateArray::rotateViaReverse(nums, 0);
        BOOST_CHECK(nums == expected);
    }

    {
        Algo::DS::Array::RotateArray::rotatePlainArray(nums, 5);
        BOOST_CHECK(nums == expected);

        Algo::DS::Array::RotateArray::rotateViaJumps(nums, 5);
        BOOST_CHECK(nums == expected);

        Algo::DS::Array::RotateArray::rotateViaReverse(nums, 5);
        BOOST_CHECK(nums == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_rotarr_invalid_k)
{
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = nums;

    {
        Algo::DS::Array::RotateArray::rotatePlainArray(nums, 0);
        BOOST_CHECK(nums == expected);

        Algo::DS::Array::RotateArray::rotateViaJumps(nums, 0);
        BOOST_CHECK(nums == expected);

        Algo::DS::Array::RotateArray::rotateViaReverse(nums, 0);
        BOOST_CHECK(nums == expected);
    }

    {
        Algo::DS::Array::RotateArray::rotatePlainArray(nums, -1);
        BOOST_CHECK(nums == expected);

        Algo::DS::Array::RotateArray::rotateViaJumps(nums, -1);
        BOOST_CHECK(nums == expected);

        Algo::DS::Array::RotateArray::rotateViaReverse(nums, -1);
        BOOST_CHECK(nums == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_rotarr_valid_arr)
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    std::vector<int> expected = {4, 5, 1, 2, 3};

    {
        std::vector<int> numbers = nums;
        Algo::DS::Array::RotateArray::rotatePlainArray(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        Algo::DS::Array::RotateArray::rotateViaJumps(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        Algo::DS::Array::RotateArray::rotateViaReverse(numbers, k);
        BOOST_CHECK(numbers == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_rotarr_k_bigger_than_arr_size)
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 24;
    std::vector<int> expected = {2, 3, 4, 5, 1};

    {
        std::vector<int> numbers = nums;
        Algo::DS::Array::RotateArray::rotatePlainArray(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        Algo::DS::Array::RotateArray::rotateViaJumps(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        Algo::DS::Array::RotateArray::rotateViaReverse(numbers, k);
        BOOST_CHECK(numbers == expected);
    }
}

#endif // TEST_ROTATE_ARRAY_HPP
