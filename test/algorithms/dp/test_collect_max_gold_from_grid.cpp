#include <boost/test/unit_test.hpp>
#include "algorithms/dp/collect_max_gold_from_grid.hpp"

BOOST_AUTO_TEST_SUITE(TestCollectMaxGold)

    BOOST_AUTO_TEST_CASE(test_input) {
        {
            const int expected = 24;
            const std::vector<std::vector<int>> grid = {
                {0, 6, 0},
                {5, 8, 7},
                {0, 9, 0}
            };

            Algo::DP::CollectMaxGold collector;
            BOOST_CHECK(expected == collector.getMaximumGold(grid));
        }

        {
            const int expected = 60;
            const std::vector<std::vector<int>> grid = {
                {1,0,7,0,0,0},
                {2,0,6,0,1,0},
                {3,5,6,7,4,2},
                {4,3,1,0,2,0},
                {3,0,5,0,20,0}
            };

            Algo::DP::CollectMaxGold collector;
            BOOST_CHECK(expected == collector.getMaximumGold(grid));
        }
    }

BOOST_AUTO_TEST_SUITE_END()
