#include <boost/test/unit_test.hpp>
#include "algorithms/dp/open_rooms_with_keys.hpp"

BOOST_AUTO_TEST_SUITE(TestOpenRoomsWithKeys)

    BOOST_AUTO_TEST_CASE(no_rooms)
    {
        const std::vector<std::vector<int>> rooms;
        const bool expected = true;
        BOOST_CHECK(expected == Algo::DP::RoomsWithKeys::canOpenAll(rooms));
    }

    BOOST_AUTO_TEST_CASE(not_able_to_go_to_one_room)
    {
        const std::vector<std::vector<int>> rooms = {{1,3}, {3,0,1}, {2}, {0}};
        const bool expected = false;
        BOOST_CHECK(expected == Algo::DP::RoomsWithKeys::canOpenAll(rooms));
    }

    BOOST_AUTO_TEST_CASE(all_rooms_available)
    {
        const std::vector<std::vector<int>> rooms = {{2}, {}, {1}};
        const bool expected = true;
        BOOST_CHECK(expected == Algo::DP::RoomsWithKeys::canOpenAll(rooms));
    }

BOOST_AUTO_TEST_SUITE_END()
