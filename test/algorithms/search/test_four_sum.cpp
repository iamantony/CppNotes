#include <boost/test/unit_test.hpp>
#include "algorithms/search/find_four_sum.hpp"

BOOST_AUTO_TEST_SUITE(TestFindFourSum)

BOOST_AUTO_TEST_CASE(empty_input_array)
{
    Algo::Search::Find4Sum f4s;
    BOOST_CHECK(f4s.find({}, 0).empty());
}

BOOST_AUTO_TEST_CASE(array_size_4_valid_target)
{
    Algo::Search::Find4Sum f4s;
    const std::vector<std::vector<int>> expected = {{1, 2, 3, 4}};
    BOOST_CHECK(expected == f4s.find({4, 2, 1, 3}, 10));
}

BOOST_AUTO_TEST_CASE(array_size_4_invalid_target)
{
    Algo::Search::Find4Sum f4s;
    const std::vector<std::vector<int>> expected;
    BOOST_CHECK(expected == f4s.find({4, 2, 1, 3}, 11));
}

BOOST_AUTO_TEST_CASE(array_size_5_valid_target)
{
    Algo::Search::Find4Sum f4s;
    const std::vector<std::vector<int>> expected = {{-2, 1, 2, 3}};
    BOOST_CHECK(expected == f4s.find({4, 2, 1, 3, -2}, 4));
}

BOOST_AUTO_TEST_CASE(array_size_6_valid_target_0)
{
    Algo::Search::Find4Sum f4s;
    const std::vector<std::vector<int>> expected = {
        {-2, -1, 1, 2},
        {-2,  0, 0, 2},
        {-1,  0, 0, 1},
    };

    BOOST_CHECK(expected == f4s.find({1, 0, -1, 0, -2, 2}, 0));
}

BOOST_AUTO_TEST_SUITE_END()
