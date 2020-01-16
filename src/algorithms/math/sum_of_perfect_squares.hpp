#ifndef SUM_OF_PERFECT_SQUARES_HPP
#define SUM_OF_PERFECT_SQUARES_HPP

/*
https://leetcode.com/problems/perfect-squares/
Given a positive integer n, find the least number of perfect square numbers
(for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

#include <vector>
#include "coin_change.hpp"

namespace Algo::Math {
    class SumOfPerfectSquares {
        static std::vector<int> getPerfectSquares(const int& maxValue) {
            std::vector<int> squares;

            int number = 1;
            while (true) {
                int square = number * number;
                if (square > maxValue) { break; }

                squares.push_back(square);
                ++number;
            }

            return squares;
        }

    public:
        static int numOfSquares(int value) {
            if (value < 0) { return -1; }
            if (value == 0) { return 0; }

            auto availableSquares = getPerfectSquares(value);
            return CoinChange::ChangeDP(availableSquares, value);
        }
    };
}

#endif //SUM_OF_PERFECT_SQUARES_HPP
