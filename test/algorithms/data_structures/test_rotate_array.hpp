#ifndef TEST_ROTATE_ARRAY_HPP
#define TEST_ROTATE_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/rotate_array.hpp"

BOOST_AUTO_TEST_CASE(test_rotarr_empty)
{
    RotateArray::Solution solution;
    std::vector<int> nums;
    std::vector<int> expected;

    {
        solution.rotate(nums, 0);
        BOOST_CHECK(nums == expected);

        solution.rotatePlainArray(nums, 0);
        BOOST_CHECK(nums == expected);

        solution.rotateViaJumps(nums, 0);
        BOOST_CHECK(nums == expected);

        solution.rotateViaReverse(nums, 0);
        BOOST_CHECK(nums == expected);
    }

    {
        solution.rotate(nums, 5);
        BOOST_CHECK(nums == expected);

        solution.rotatePlainArray(nums, 5);
        BOOST_CHECK(nums == expected);

        solution.rotateViaJumps(nums, 5);
        BOOST_CHECK(nums == expected);

        solution.rotateViaReverse(nums, 5);
        BOOST_CHECK(nums == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_rotarr_invalid_k)
{
    RotateArray::Solution solution;
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> expected = nums;

    {
        solution.rotate(nums, 0);
        BOOST_CHECK(nums == expected);

        solution.rotatePlainArray(nums, 0);
        BOOST_CHECK(nums == expected);

        solution.rotateViaJumps(nums, 0);
        BOOST_CHECK(nums == expected);

        solution.rotateViaReverse(nums, 0);
        BOOST_CHECK(nums == expected);
    }

    {
        solution.rotate(nums, -1);
        BOOST_CHECK(nums == expected);

        solution.rotatePlainArray(nums, -1);
        BOOST_CHECK(nums == expected);

        solution.rotateViaJumps(nums, -1);
        BOOST_CHECK(nums == expected);

        solution.rotateViaReverse(nums, -1);
        BOOST_CHECK(nums == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_rotarr_valid_arr)
{
    RotateArray::Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    std::vector<int> expected = {4, 5, 1, 2, 3};

    {
        std::vector<int> numbers = nums;
        solution.rotate(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        solution.rotatePlainArray(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        solution.rotateViaJumps(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        solution.rotateViaReverse(numbers, k);
        BOOST_CHECK(numbers == expected);
    }
}

BOOST_AUTO_TEST_CASE(test_rotarr_k_bigger_than_arr_size)
{
    RotateArray::Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 24;
    std::vector<int> expected = {2, 3, 4, 5, 1};

    {
        std::vector<int> numbers = nums;
        solution.rotate(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        solution.rotatePlainArray(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        solution.rotateViaJumps(numbers, k);
        BOOST_CHECK(numbers == expected);
    }

    {
        std::vector<int> numbers = nums;
        solution.rotateViaReverse(numbers, k);
        BOOST_CHECK(numbers == expected);
    }
}

#endif // TEST_ROTATE_ARRAY_HPP

