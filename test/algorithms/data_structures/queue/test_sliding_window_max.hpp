#ifndef TEST_SLIDING_WINDOW_MAX_HPP
#define TEST_SLIDING_WINDOW_MAX_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/queue/sliding_window_max.hpp"

BOOST_AUTO_TEST_CASE(test_slwmax_test) {
    {
        const std::vector<int> input = {};
        const size_t window_size = 0;
        const std::vector<int> expected = {};
        const auto result =
                Algo::DS::Queue::SlidingWindow<int>::Max(input, window_size);
        BOOST_CHECK(expected == result);
    }

    {
        const std::vector<int> input = {1};
        const size_t window_size = 1;
        const std::vector<int> expected = {1};
        const auto result =
                Algo::DS::Queue::SlidingWindow<int>::Max(input, window_size);
        BOOST_CHECK(expected == result);
    }

    {
        const std::vector<int> input = {2, 3, 4};
        const size_t window_size = 1;
        const std::vector<int> expected = {2, 3, 4};
        const auto result =
                Algo::DS::Queue::SlidingWindow<int>::Max(input, window_size);
        BOOST_CHECK(expected == result);
    }

    {
        const std::vector<int> input = {1, 3, -1, -3, 5, 3, 6, 7};
        const size_t window_size = 3;
        const std::vector<int> expected = {3, 3, 5, 5, 6, 7};
        const auto result =
                Algo::DS::Queue::SlidingWindow<int>::Max(input, window_size);
        BOOST_CHECK(expected == result);
    }

    {
        const std::vector<int> input = {7, 2, 4};
        const size_t window_size = 2;
        const std::vector<int> expected = {7, 4};
        const auto result =
                Algo::DS::Queue::SlidingWindow<int>::Max(input, window_size);
        BOOST_CHECK(expected == result);
    }
}

#endif // TEST_SLIDING_WINDOW_MAX_HPP
