#ifndef TEST_SUMMARY_RANGES_HPP
#define TEST_SUMMARY_RANGES_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/summary_ranges.hpp"

BOOST_AUTO_TEST_CASE(test_sumrng_empty_arr)
{
    std::vector<int> v;
    std::vector<std::string> expected;
    BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
}

BOOST_AUTO_TEST_CASE(test_sumrng_no_compression)
{
    {
        std::vector<int> v = {0};
        std::vector<std::string> expected = { "0" };
        BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
    }

    {
        std::vector<int> v = {0, 4};
        std::vector<std::string> expected = { "0", "4" };
        BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
    }
}

BOOST_AUTO_TEST_CASE(test_sumrng_compress_to_one)
{
    {
        std::vector<int> v = {0, 1};
        std::vector<std::string> expected = { "0->1" };
        BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
    }

    {
        std::vector<int> v = {0, 1, 2, 3};
        std::vector<std::string> expected = { "0->3" };
        BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
    }
}

BOOST_AUTO_TEST_CASE(test_sumrng_several_compressions)
{
    {
        std::vector<int> v = {0, 2, 3, 4, 10};
        std::vector<std::string> expected = { "0", "2->4", "10" };
        BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
    }

    {
        std::vector<int> v = {0, 1, 2, 3, 8, 9, 10};
        std::vector<std::string> expected = { "0->3", "8->10" };
        BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
    }

    {
        std::vector<int> v = {0, 1, 2, 4, 5, 7};
        std::vector<std::string> expected = { "0->2", "4->5", "7" };
        BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
    }

    {
        std::vector<int> v = {0, 2, 3, 4, 6, 8, 9};
        std::vector<std::string> expected = { "0", "2->4", "6", "8->9" };
        BOOST_CHECK(expected == Algo::DS::Array::SummaryRanges::Create(v));
    }
}

#endif // TEST_SUMMARY_RANGES_HPP
