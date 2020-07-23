#ifndef CPPNOTESMAIN_JUMP_GAME_HPP
#define CPPNOTESMAIN_JUMP_GAME_HPP

#include <vector>

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
    };
}

#endif //CPPNOTESMAIN_JUMP_GAME_HPP
