#ifndef TEST_FIND_THREE_SUM_HPP
#define TEST_FIND_THREE_SUM_HPP

#include <limits>
#include <chrono>
#include <iostream>

#include <boost/test/unit_test.hpp>

#include "algorithms/search/find_three_sum.hpp"

BOOST_AUTO_TEST_CASE(test_fthreesum_vector_invalid_size)
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

BOOST_AUTO_TEST_CASE(test_fthreesum_no_triplets)
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

BOOST_AUTO_TEST_CASE(test_fthreesum_one_triplet)
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

BOOST_AUTO_TEST_CASE(test_fthreesum_two_equal_triplets)
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

BOOST_AUTO_TEST_CASE(test_fthreesum_two_triplets)
{
    {
        std::vector<int> nums = {-2, -1, 0, 1, 2};
        std::vector<std::vector<int>> expected = { {-2, 0, 2}, {-1, 0, 1} };
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
    }
}

BOOST_AUTO_TEST_CASE(test_fthreesum_huge_input)
{
    {
        std::vector<int> nums(100, 0);
        std::vector<std::vector<int>> expected = { {0, 0, 0} };

        auto start = std::chrono::high_resolution_clock::now();
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindNaive(nums));
        auto stop = std::chrono::high_resolution_clock::now();
//        std::cout << "FindNaive: " <<
//                     std::chrono::duration<double>(stop-start).count() <<
//                     "ms" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithHash(nums));
        stop = std::chrono::high_resolution_clock::now();
//        std::cout << "FindWithHash: " <<
//                     std::chrono::duration<double>(stop-start).count() <<
//                     "s" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        BOOST_CHECK(expected == Algo::Search::Find3Sum::FindWithSorting(nums));
        stop = std::chrono::high_resolution_clock::now();
//        std::cout << "FindWithSorting: " <<
//                     std::chrono::duration<double>(stop-start).count() <<
//                     "s" << std::endl;
    }
}

#endif // TEST_FIND_THREE_SUM_HPP
