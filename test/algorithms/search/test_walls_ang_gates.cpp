#include <boost/test/unit_test.hpp>
#include "algorithms/search/walls_and_gates.hpp"

const int WALL = -1;
const int GATE = 0;
const int EMPTY = 2147483647;

BOOST_AUTO_TEST_SUITE(TestWallsAndGates)

    BOOST_AUTO_TEST_CASE(empty_data)
    {
        {
            Algo::Search::WallsAndGates wg;
            std::vector<std::vector<int>> empty_rooms;
            wg.walk(empty_rooms);
            BOOST_CHECK(empty_rooms.empty());
        }

        {
            Algo::Search::WallsAndGates wg;
            std::vector<std::vector<int>> empty_rooms = {{}, {}};
            const auto expected = empty_rooms;
            wg.walk(empty_rooms);
            BOOST_CHECK(empty_rooms == expected);
        }
    }

    BOOST_AUTO_TEST_CASE(default_test_case)
    {
        std::vector<std::vector<int>> rooms = {
            {EMPTY, WALL,  GATE, EMPTY},
            {EMPTY, EMPTY, EMPTY, WALL},
            {EMPTY, WALL, EMPTY, WALL},
            {GATE, WALL, EMPTY, EMPTY}};

        const std::vector<std::vector<int>> expected = {
            {3, WALL,  GATE, 1},
            {2, 2, 1, WALL},
            {1, WALL, 2, WALL},
            {GATE, WALL, 3, 4}};

        Algo::Search::WallsAndGates wg;
        wg.walk(rooms);
        BOOST_CHECK(rooms == expected);
    }

    BOOST_AUTO_TEST_CASE(no_empty_cells)
    {
        std::vector<std::vector<int>> rooms = {
            {GATE, WALL,  WALL, GATE},
            {GATE, GATE, WALL, WALL},
            {GATE, WALL, WALL, WALL},
            {GATE, WALL, GATE, GATE}};

        const std::vector<std::vector<int>> expected = rooms;

        Algo::Search::WallsAndGates wg;
        wg.walk(rooms);
        BOOST_CHECK(rooms == expected);
    }

    BOOST_AUTO_TEST_CASE(no_gates)
    {
        std::vector<std::vector<int>> rooms = {
            {EMPTY, WALL,  WALL, EMPTY},
            {EMPTY, EMPTY, EMPTY, WALL},
            {EMPTY, WALL, EMPTY, WALL}};

        const std::vector<std::vector<int>> expected = rooms;

        Algo::Search::WallsAndGates wg;
        wg.walk(rooms);
        BOOST_CHECK(rooms == expected);
    }

BOOST_AUTO_TEST_SUITE_END()

