#ifndef COIN_CHANGE_HPP
#define COIN_CHANGE_HPP

/*
https://leetcode.com/problems/coin-change/
You are given coins of different denominations and a total amount of money
amount. Write a function to compute the fewest number of coins that you need
to make up that amount. If that amount of money cannot be made up by any
combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.
*/

#include <algorithm>
#include <vector>
#include <limits>

namespace Algo::DP {
    class CoinChange {
        static int MakeChange(std::vector<int> coins, int amount) {
            int number_of_coins = 0;
            while (amount > 0)
            {
                if (coins.empty()) {
                    return -1;
                }

                const auto coin_value = *(coins.rbegin());
                coins.resize(coins.size() - 1);

                const auto coins_num = amount / coin_value;
                if (coins_num == 0) {
                    continue;
                }

                number_of_coins += coins_num;
                amount = amount % coin_value;
            }

            return number_of_coins;
        }

    public:
        static int ChangeGreedy(std::vector<int> coins, int amount) {
            if (coins.empty() || amount < 0) {
                return -1;
            }

            std::sort(coins.begin(), coins.end());
            return MakeChange(coins, amount);
        }

        static int ChangeDP(const std::vector<int> coins, int amount) {
            if (coins.empty() || amount < 0) {
                return -1;
            }

            const auto UIntMax = std::numeric_limits<uint32_t>::max();
            std::vector<uint32_t> table(static_cast<size_t>(amount + 1), UIntMax);
            table[0] = 0;

            for (int val = 1; val <= amount; ++val) {
                for (size_t c = 0; c < coins.size(); ++c) {
                    if (coins[c] > val) { continue; }

                    auto index = static_cast<size_t>(val - coins[c]);
                    auto sub_res = table[index];
                    if (sub_res < UIntMax &&
                            sub_res + 1 < table[static_cast<size_t>(val)]) {
                        table[static_cast<size_t>(val)] = sub_res + 1;
                    }
                }
            }

            const auto result = table[static_cast<size_t>(amount)];
            return result == UIntMax ? -1 : static_cast<int>(result);
        }
    };
}

#endif // COIN_CHANGE_HPP
