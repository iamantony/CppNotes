#include <boost/test/unit_test.hpp>
#include "algorithms/greedy/jump_game.hpp"

BOOST_AUTO_TEST_SUITE(TestJumpGame)

    BOOST_AUTO_TEST_CASE(test_get_min_jumps)
    {
        {
            const std::vector<int> nums;
            const int expected = 0;
            BOOST_CHECK(expected == Algo::Greedy::JumpGame::min_jumps_from_beginning_to_end_dp(nums));
        }

        {
            const std::vector<int> nums = {0};
            const int expected = 0;
            BOOST_CHECK(expected == Algo::Greedy::JumpGame::min_jumps_from_beginning_to_end_dp(nums));
        }

        {
            const std::vector<int> nums = {1,1};
            const int expected = 1;
            BOOST_CHECK(expected == Algo::Greedy::JumpGame::min_jumps_from_beginning_to_end_dp(nums));
        }

        {
            const std::vector<int> nums = {1,1,1};
            const int expected = 2;
            BOOST_CHECK(expected == Algo::Greedy::JumpGame::min_jumps_from_beginning_to_end_dp(nums));
        }

        {
            const std::vector<int> nums = {2,0,1,5,1};
            const int expected = 3;
            BOOST_CHECK(expected == Algo::Greedy::JumpGame::min_jumps_from_beginning_to_end_dp(nums));
        }

        {
            const std::vector<int> nums = {5,4,1,0,1};
            const int expected = 1;
            BOOST_CHECK(expected == Algo::Greedy::JumpGame::min_jumps_from_beginning_to_end_dp(nums));
        }
    }

BOOST_AUTO_TEST_SUITE_END()
