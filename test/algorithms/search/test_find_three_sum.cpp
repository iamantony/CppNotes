#include <boost/test/unit_test.hpp>
#include "algorithms/search/find_three_sum.hpp"

BOOST_AUTO_TEST_SUITE(TestFind3Sum)

BOOST_AUTO_TEST_CASE(vector_invalid_size)
{
    {
        std::vector<int> nums = {};
        std::vector<std::vector<int>> expected = {};
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }

    {
        std::vector<int> nums = {1};
        std::vector<std::vector<int>> expected = {};
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }

    {
        std::vector<int> nums = {1, 2};
        std::vector<std::vector<int>> expected = {};
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }
}

BOOST_AUTO_TEST_CASE(no_triplets)
{
    {
        std::vector<int> nums = {1, 1, 1};
        std::vector<std::vector<int>> expected = {};
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }

    {
        std::vector<int> nums = {4, 1, 1, 1};
        std::vector<std::vector<int>> expected = {};
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }
}

BOOST_AUTO_TEST_CASE(one_triplet)
{
    {
        std::vector<int> nums = {0, 0, 0};
        std::vector<std::vector<int>> expected = { {0, 0, 0} };
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }

    {
        std::vector<int> nums = {1, 2, 0, -1};
        std::vector<std::vector<int>> expected = { {-1, 0, 1} };
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }
}

BOOST_AUTO_TEST_CASE(two_equal_triplets)
{
    {
        std::vector<int> nums = {-2, 0, 2, -2};
        std::vector<std::vector<int>> expected = { {-2, 0, 2} };
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }

    {
        std::vector<int> nums = {-2, -1, 0, 1, -1};
        std::vector<std::vector<int>> expected = { {-1, 0, 1} };
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }
}

BOOST_AUTO_TEST_CASE(two_triplets)
{
    {
        std::vector<int> nums = {-2, -1, 0, 1, 2};
        std::vector<std::vector<int>> expected = { {-2, 0, 2}, {-1, 0, 1} };
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }
}

BOOST_AUTO_TEST_CASE(huge_input)
{
    {
        std::vector<int> nums(100, 0);
        std::vector<std::vector<int>> expected = { {0, 0, 0} };

        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }
}

BOOST_AUTO_TEST_SUITE_END()
