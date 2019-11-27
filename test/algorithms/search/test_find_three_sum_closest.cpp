#include <boost/test/unit_test.hpp>
#include "algorithms/search/find_three_sum_closest.hpp"

BOOST_AUTO_TEST_SUITE(TestFindThreeSumClosest)

BOOST_AUTO_TEST_CASE(vector_invalid_size)
{
    {
        std::vector<int> nums = {};
        int target = 0;
        int expected = -1;
        BOOST_CHECK(expected ==
                    Algo::Search::Find3SumClosest::Find(nums, target));
    }

    {
        std::vector<int> nums = {1};
        int target = 0;
        int expected = -1;
        BOOST_CHECK(expected ==
                    Algo::Search::Find3SumClosest::Find(nums, target));
    }

    {
        std::vector<int> nums = {1, 2};
        int target = 0;
        int expected = -1;
        BOOST_CHECK(expected ==
                    Algo::Search::Find3SumClosest::Find(nums, target));
    }
}

BOOST_AUTO_TEST_CASE(valid_sum)
{
    {
        std::vector<int> nums = {1, 1, 1};
        int target = 10;
        int expected = 3;
        BOOST_CHECK(expected ==
                    Algo::Search::Find3SumClosest::Find(nums, target));
    }

    {
        std::vector<int> nums = {4, 1, 1, 1};
        int target = 10;
        int expected = 6;
        BOOST_CHECK(expected ==
                    Algo::Search::Find3SumClosest::Find(nums, target));
    }

    {
        std::vector<int> nums = {-1, 2, 1, -4};
        int target = 1;
        int expected = 2;
        BOOST_CHECK(expected ==
                    Algo::Search::Find3SumClosest::Find(nums, target));
    }

    {
        std::vector<int> nums = {0, 1, 2, 3, 1, 0, 5, 0};
        int target = 0;
        int expected = 0;
        BOOST_CHECK(expected ==
                    Algo::Search::Find3SumClosest::Find(nums, target));
    }

    {
        std::vector<int> nums = {1, 1, -1, -1, 3};
        int target = -1;
        int expected = -1;
        BOOST_CHECK(expected ==
                    Algo::Search::Find3SumClosest::Find(nums, target));
    }
}

BOOST_AUTO_TEST_SUITE_END()
