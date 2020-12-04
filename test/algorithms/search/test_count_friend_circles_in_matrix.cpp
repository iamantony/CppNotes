#include <boost/test/unit_test.hpp>
#include "algorithms/search/count_friend_circles_in_matrix.hpp"

BOOST_AUTO_TEST_SUITE(TestCountFriendCirclesInMatrix)

    BOOST_AUTO_TEST_CASE(empty_matrix)
    {
        std::vector<std::vector<int>> matrix = {};
        const size_t expected = 0;
        BOOST_CHECK(expected == Algo::Search::FriendCircles::count(matrix));
    }

    BOOST_AUTO_TEST_CASE(only_one_friend)
    {
        std::vector<std::vector<int>> matrix = {{1}};
        const size_t expected = 1;
        BOOST_CHECK(expected == Algo::Search::FriendCircles::count(matrix));
    }

    BOOST_AUTO_TEST_CASE(two_friends_two_circles)
    {
        std::vector<std::vector<int>> matrix = {
            {1, 0},
            {0, 1}
        };

        const size_t expected = 2;
        BOOST_CHECK(expected == Algo::Search::FriendCircles::count(matrix));
    }

    BOOST_AUTO_TEST_CASE(two_friends_one_circle)
    {
        std::vector<std::vector<int>> matrix = {
            {1, 1},
            {1, 1}
        };

        const size_t expected = 1;
        BOOST_CHECK(expected == Algo::Search::FriendCircles::count(matrix));
    }

    BOOST_AUTO_TEST_CASE(three_friends_two_circles)
    {
        std::vector<std::vector<int>> matrix = {
            {1, 0, 0},
            {0, 1, 1},
            {0, 1, 1}
        };

        const size_t expected = 2;
        BOOST_CHECK(expected == Algo::Search::FriendCircles::count(matrix));
    }

    BOOST_AUTO_TEST_CASE(four_friends_two_circles)
    {
        std::vector<std::vector<int>> matrix = {
            {1, 1, 0, 0},
            {1, 1, 0, 1},
            {0, 0, 1, 0},
            {0, 1, 1, 0}
        };

        const size_t expected = 2;
        BOOST_CHECK(expected == Algo::Search::FriendCircles::count(matrix));
    }

    BOOST_AUTO_TEST_CASE(five_friends_three_circles)
    {
        std::vector<std::vector<int>> matrix = {
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0},
            {0, 0, 1, 0, 1}
        };

        const size_t expected = 3;
        BOOST_CHECK(expected == Algo::Search::FriendCircles::count(matrix));
    }

    BOOST_AUTO_TEST_CASE(four_friends_one_circle)
    {
        std::vector<std::vector<int>> matrix = {
            {1, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 1},
            {1, 0, 1, 1}
        };

        const size_t expected = 1;
        BOOST_CHECK(expected == Algo::Search::FriendCircles::count(matrix));
    }

BOOST_AUTO_TEST_SUITE_END()
