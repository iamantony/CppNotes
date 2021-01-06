#ifndef CPPNOTESMAIN_MAX_XOR_OF_TWO_NUMBERS_IN_ARRAY_HPP
#define CPPNOTESMAIN_MAX_XOR_OF_TWO_NUMBERS_IN_ARRAY_HPP

/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.

Follow up: Could you do this in O(n) runtime?

Example 1:
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:
Input: nums = [0]
Output: 0

Example 3:
Input: nums = [2,4]
Output: 6

Example 4:
Input: nums = [8,10,2]
Output: 10

Example 5:
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

Constraints:
* 1 <= nums.length <= 2 * 104
* 0 <= nums[i] <= 231 - 1
*/

#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

namespace Algo::DS::Tree {
    class MaxXOROfTwoNums {
        struct Node {
            Node* zero = nullptr;
            Node* one = nullptr;
        };

        size_t find_max_bit_string_size(const std::vector<int>& nums) {
            int max_num = nums.front();
            for (const auto& n : nums) { max_num = std::max(max_num, n); }

            const auto str = std::bitset<32>(max_num).to_string();
            auto iter = std::find(str.begin(), str.end(), '1');
            return iter == str.end() ? 1 : std::distance(iter, str.end());
        }

        std::string convert_to_bit_string(int n, size_t max_size) {
            auto str = std::bitset<32>(n).to_string();
            const auto offset = str.size() - max_size;
            return str.substr(offset);
        }

    public:
        int find(const std::vector<int>& nums) {
            if (nums.size() < 2) { return 0; }

            const auto max_bit_string_size = find_max_bit_string_size(nums);

            Node root;
            int max_xor = 0;
            for (const auto& n : nums) {
                Node* cur_node = &root;
                Node* xor_node = &root;
                int cur_xor = 0;
                const auto str = convert_to_bit_string(n, max_bit_string_size);
                for (const auto& b : str) {
                    if (b == '0') {
                        if (cur_node->zero == nullptr) {
                            cur_node->zero = new Node();
                        }

                        cur_node = cur_node->zero;
                    }
                    else {
                        if (cur_node->one == nullptr) {
                            cur_node->one = new Node();
                        }

                        cur_node = cur_node->one;
                    }

                    const auto opposite_bit = b == '0' ? '1' : '0';
                    if (opposite_bit == '0') {
                        if (xor_node->zero != nullptr) {
                            cur_xor = (cur_xor << 1) | 1;
                            xor_node = xor_node->zero;
                        }
                        else {
                            cur_xor = cur_xor << 1;
                            xor_node = xor_node->one;
                        }
                    }
                    else {
                        if (xor_node->one != nullptr) {
                            cur_xor = (cur_xor << 1) | 1;
                            xor_node = xor_node->one;
                        }
                        else {
                            cur_xor = cur_xor << 1;
                            xor_node = xor_node->zero;
                        }
                    }
                }

                max_xor = std::max(max_xor, cur_xor);
            }

            return max_xor;
        }
    };
}

#endif //CPPNOTESMAIN_MAX_XOR_OF_TWO_NUMBERS_IN_ARRAY_HPP
