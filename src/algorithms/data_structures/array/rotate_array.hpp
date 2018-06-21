#ifndef ROTATE_ARRAY_HPP
#define ROTATE_ARRAY_HPP

// https://leetcode.com/problems/rotate-array/description/

// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
// [5,6,7,1,2,3,4].

#include <vector>

namespace Algo::DS::Array {

class RotateArray {
public:
    // Rotate using vector properties and functions
    // TC: O(n)
    // SC: O(k)
    static void rotate(std::vector<int>& nums, int k) {
        if (nums.size() < 2 || k <= 0) {
            return;
        }

        int numSize = static_cast<int>(nums.size());
        k = k % numSize;

        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
    }

    // rotate vector as if it was just an array. Use additional memory
    // TC: O(n)
    // SC: O(n)
    static void rotatePlainArray(std::vector<int>& nums, int k) {
        if (nums.size() < 2 || k <= 0) {
            return;
        }

        size_t kk = static_cast<size_t>(k);
        kk = kk % nums.size();

        std::vector<int> rotated(nums.size());
        for (size_t i = nums.size() - kk, j = 0; i < nums.size(); ++i, ++j) {
            rotated[j] = nums[i];
        }

        for (size_t i = 0, j = kk; j < nums.size(); ++i, ++j) {
            rotated[j] = nums[i];
        }

        nums = rotated;
    }

    // rotate via jumps
    // TC: O(n)
    // SC: O(1)
    static void rotateViaJumps(std::vector<int>& nums, int k) {
        if (nums.size() < 2 || k <= 0) {
            return;
        }

        size_t kk = static_cast<size_t>(k);
        kk = kk % nums.size();

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

        size_t kk = static_cast<size_t>(k);
        kk = kk % nums.size();

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, kk - 1);
        reverse(nums, kk, nums.size() - 1);
    }

private:
    static void reverse(std::vector<int>& nums, size_t start, size_t end) {
        while (start < end) {
            int temp = nums[end];
            nums[end] = nums[start];
            nums[start] = temp;
            ++start;
            --end;
        }
    }
};

}

#endif // ROTATE_ARRAY_HPP

