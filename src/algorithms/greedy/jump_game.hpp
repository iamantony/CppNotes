#ifndef CPPNOTESMAIN_JUMP_GAME_HPP
#define CPPNOTESMAIN_JUMP_GAME_HPP

#include <vector>
#include <cstdint>

namespace Algo::Greedy {
    class JumpGame {
    public:
        /*
        https://leetcode.com/problems/jump-game/
        Given an array of non-negative integers, you are initially positioned at the first index of
        the array.

        Each element in the array represents your maximum jump length at that position.

        Determine if you are able to reach the last index.

        Example 1:
        Input: nums = [2,3,1,1,4]
        Output: true
        Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

        Example 2:
        Input: nums = [3,2,1,0,4]
        Output: false
        Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0,
        which makes it impossible to reach the last index.

        Constraints:
        1 <= nums.length <= 3 * 10^4
        0 <= nums[i][j] <= 10^5
        */
        static bool can_jump_from_beginning_to_end(const std::vector<int>& nums) {
            int size = static_cast<int>(nums.size());
            auto last_pos = size - 1;
            for (auto i = size - 2; i >= 0; --i) {
                if (i + nums[static_cast<size_t>(i)] >= last_pos) {
                    last_pos = i;
                }
            }

            return last_pos == 0;
        }

        /*
        https://leetcode.com/problems/jump-game-ii/
        Given an array of non-negative integers, you are initially positioned at the first index of
        the array.

        Each element in the array represents your maximum jump length at that position.

        Your goal is to reach the last index in the minimum number of jumps.

        Example:
        Input: [2,3,1,1,4]
        Output: 2
        Explanation: The minimum number of jumps to reach the last index is 2.
            Jump 1 step from index 0 to 1, then 3 steps to the last index.

        Note:
        You can assume that you can always reach the last index.
        */
        static int min_jumps_from_beginning_to_end_dp(const std::vector<int>& nums) {
            if (nums.size() < 2) { return 0; }

            std::vector<bool> cells(nums.size(), false);
            cells.back() = true;

            const auto size = static_cast<int>(nums.size());
            for (int i = size - 2; i >= 0; --i) {
                const auto ii = static_cast<size_t>(i);
                const auto max_index = static_cast<size_t>(std::min(i + nums[ii], size - 1));
                for (auto j = ii + 1; j <= max_index; ++j) {
                    if (cells[j]) {
                        cells[ii] = true;
                        break;
                    }
                }
            }

            int min_jumps = 0;
            size_t pos = 0;
            while (pos < nums.size() - 1) {
                const auto max_index =
                    std::min(pos + static_cast<size_t>(nums[pos]), nums.size() - 1);
                if (max_index == nums.size() - 1) {
                    ++min_jumps;
                    break;
                }

                size_t next_pos = pos;
                size_t max_next_jump_index = 0;
                for (auto i = pos + 1; i <= max_index; ++i) {
                    if (!cells[i]) { continue; }

                    auto max_jump_index = i + static_cast<size_t>(nums[i]);
                    if (max_jump_index > max_next_jump_index) {
                        max_next_jump_index = max_jump_index;
                        next_pos = i;
                    }
                }

                if (next_pos == pos) { return -1; }

                pos = next_pos;
                ++min_jumps;
            }

            return min_jumps;
        }

        static int min_jumps_from_beginning_to_end_greedy(const std::vector<int>& nums) {
            if (nums.size() < 2) return 0;

            // max position one could reach starting from index <= i
            size_t maxPos = static_cast<size_t>(nums[0]);
            // max number of steps one could do inside this jump
            size_t maxSteps = static_cast<size_t>(nums[0]);

            int jumps = 1;
            for (size_t i = 1; i < nums.size(); ++i) {
                // if to reach this point one needs one more jump
                if (maxSteps < i) {
                    ++jumps;
                    maxSteps = maxPos;
                }

                maxPos = std::max(maxPos, static_cast<size_t>(nums[i]) + i);
            }

            return jumps;
        }
    };
}

#endif //CPPNOTESMAIN_JUMP_GAME_HPP
