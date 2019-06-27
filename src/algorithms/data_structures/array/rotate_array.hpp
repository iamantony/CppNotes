#ifndef ROTATE_ARRAY_HPP
#define ROTATE_ARRAY_HPP

// https://leetcode.com/problems/rotate-array/description/

// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
// [5,6,7,1,2,3,4].

#include <algorithm>
#include <vector>

namespace Algo::DS::Array {

class RotateArray {
public:
    // rotate vector as if it was just an array. Use additional memory
    // TC: O(n)
    // SC: O(n)
    static void rotatePlainArray(std::vector<int>& nums, int k) {
        if (nums.size() < 2 || k <= 0) {
            return;
        }

        k = k % static_cast<int>(nums.size());

        std::vector<int> rotated;
        rotated.reserve(nums.size());

        std::copy(nums.end() - k, nums.end(), std::back_inserter(rotated));
        std::copy(nums.begin(), nums.end() - k, std::back_inserter(rotated));

        nums = rotated;
    }

    // rotate via jumps
    // TC: O(n)
    // SC: O(1)
    static void rotateViaJumps(std::vector<int>& nums, int k) {
        if (nums.size() < 2 || k <= 0) {
            return;
        }

        size_t kk = static_cast<size_t>(k) % nums.size();

        for (size_t count = 0, startPos = 0; count < nums.size(); ++startPos) {
            size_t currentPos = startPos;
            int prevNum = nums[startPos];
            do {
                size_t nextPos = (currentPos + kk) % nums.size();

                int tempNum = nums[nextPos];
                nums[nextPos] = prevNum;
                prevNum = tempNum;

                currentPos = nextPos;
                ++count;
            } while (startPos != currentPos);
        }
    }

    // rotate via reverse
    // TC: O(3n)
    // SC: O(1)
    static void rotateViaReverse(std::vector<int>& nums, int k) {
        if (nums.size() < 2 || k <= 0) {
            return;
        }

        k = k % static_cast<int>(nums.size());

        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
}

#endif // ROTATE_ARRAY_HPP
