#ifndef CAPTURE_SURROUNDED_REGIONS_HPP
#define CAPTURE_SURROUNDED_REGIONS_HPP

/*
https://leetcode.com/problems/surrounded-regions/
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board
are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the
border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected
horizontally or vertically.
*/

#include <vector>
#include <algorithm>
#include <stack>

namespace Algo::Search {
    class CaptureSurroundedRegions {
        static const char O = 'O';
        static const char X = 'X';
        static const char RESERVE = 'R';

        static void reserveBorderElements(
            std::vector<std::vector<char>>& m, const char elementValue, const char reserveValue)
        {
            if (m.empty()) { return; }

            const size_t maxR = m.size();
            const size_t maxC = m[0].size();

            for (size_t c = 0; c < maxC; ++c) {
                reserveNeighborElements(m, 0, c, maxR, maxC, elementValue, reserveValue);
                reserveNeighborElements(m, maxR - 1, c, maxR, maxC, elementValue, reserveValue);
            }

            for (size_t r = 0; r < maxR; ++r) {
                reserveNeighborElements(m, r, 0, maxR, maxC, elementValue, reserveValue);
                reserveNeighborElements(m, r, maxC - 1, maxR, maxC, elementValue, reserveValue);
            }
        }

        static void reserveNeighborElements(
            std::vector<std::vector<char>>& m,
            const size_t r, const size_t c,
            const size_t& maxR, const size_t& maxC,
            const char elementValue, const char reserveValue)
        {
            if (r >= maxR || c >= maxC) { return; }
            if (m[r][c] != elementValue) { return; }

            std::stack<std::pair<size_t, size_t>> stack;
            stack.push({r, c});
            while (!stack.empty()) {
                const auto [posR, posC] = stack.top();
                stack.pop();

                m[posR][posC] = reserveValue;

                std::vector<std::pair<size_t, size_t>> neighbors = {
                    {(posR > 0 ? posR - 1 : maxR), posC},
                    {posR, (posC > 0 ? posC - 1 : maxC)},
                    {posR, posC + 1},
                    {posR + 1, posC},
                };

                for (auto& [row, col] : neighbors) {
                    if (row >= maxR || col >= maxC || m[row][col] != elementValue) { continue; }

                    stack.push({row, col});
                }
            }
        }

        static void replace(
            std::vector<std::vector<char>>& m, const char oldValue, const char newValue)
        {
            auto replacer = [oldValue, newValue](std::vector<char>& line) {
                std::replace(line.begin(), line.end(), oldValue, newValue);
            };

            std::for_each(m.begin(), m.end(), replacer);
        }

    public:
        static void capture(std::vector<std::vector<char>>& m) {
            reserveBorderElements(m, O, RESERVE);
            replace(m, O, X);
            replace(m, RESERVE, O);
        }
    };
}

#endif //CAPTURE_SURROUNDED_REGIONS_HPP
