#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/find_first_and_last_pos.hpp"

BOOST_AUTO_TEST_SUITE(TestFindFirstAndLastPos)

BOOST_AUTO_TEST_CASE(empty_array)
{
    std::vector<int> nums = { };
    int target = 10;
    std::vector<int> expected = {-1, -1};
    BOOST_CHECK(expected ==
        Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
}

BOOST_AUTO_TEST_CASE(array_with_one_elem)
{
    {
        std::vector<int> nums = { 1 };
        int target = 10;
        std::vector<int> expected = {-1, -1};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }

    {
        std::vector<int> nums = { 10 };
        int target = 10;
        std::vector<int> expected = {0, 0};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }
}

BOOST_AUTO_TEST_CASE(array_with_two_elems)
{
    {
        std::vector<int> nums = { 1, 2 };
        int target = 10;
        std::vector<int> expected = {-1, -1};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }

    {
        std::vector<int> nums = { 10, 11 };
        int target = 10;
        std::vector<int> expected = {0, 0};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }

    {
        std::vector<int> nums = { 10, 11 };
        int target = 11;
        std::vector<int> expected = {1, 1};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }

    {
        std::vector<int> nums = { 10, 10 };
        int target = 10;
        std::vector<int> expected = {0, 1};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }
}

BOOST_AUTO_TEST_CASE(array_with_three_elems)
{
    {
        std::vector<int> nums = { 1, 2, 2 };
        int target = 10;
        std::vector<int> expected = {-1, -1};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }

    {
        std::vector<int> nums = { 10, 11, 12 };
        int target = 11;
        std::vector<int> expected = {1, 1};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }

    {
        std::vector<int> nums = { 10, 10, 10 };
        int target = 10;
        std::vector<int> expected = {0, 2};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }
}

BOOST_AUTO_TEST_CASE(array_with_many_elems)
{
    {
        std::vector<int> nums = { 5, 7, 7, 8, 8, 10 };
        int target = 7;
        std::vector<int> expected = {1, 2};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }

    {
        std::vector<int> nums = { 5, 7, 7, 8, 8, 10 };
        int target = 6;
        std::vector<int> expected = {-1, -1};
        BOOST_CHECK(expected ==
            Algo::DS::Array::FindFirstAndLastPos::Find(nums, target));
    }
}

BOOST_AUTO_TEST_SUITE_END()
