#ifndef CPPNOTESMAIN_WALLS_AND_GATES_HPP
#define CPPNOTESMAIN_WALLS_AND_GATES_HPP

/*
https://leetcode.com/problems/walls-and-gates/
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as
you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate,
it should be filled with INF.

Example:
Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

#include <algorithm>
#include <array>
#include <vector>
#include <queue>

namespace Algo::Search {
    class WallsAndGates {
        static const int WALL = -1;
        static const int GATE = 0;

        size_t m_row_num;
        size_t m_col_num;

        bool get_rooms_size(const std::vector<std::vector<int>>& rooms) {
            m_row_num = rooms.size();
            if (m_row_num == 0) { return false; }

            m_col_num = rooms.front().size();
            if (m_col_num == 0) { return false; }

            return true;
        }

        std::queue<std::pair<size_t, size_t>> find_gates(
            const std::vector<std::vector<int>>& rooms)
        {
            std::queue<std::pair<size_t, size_t>> gates;
            for (size_t i = 0; i < m_row_num; ++i) {
                for (size_t j = 0; j < m_col_num; ++j) {
                    if (rooms[i][j] == GATE) { gates.push({i, j}); }
                }
            }

            return gates;
        }

    public:
        void walk(std::vector<std::vector<int>>& rooms) {
            if (!get_rooms_size(rooms)) { return; }

            auto rooms_queue = find_gates(rooms);
            while (!rooms_queue.empty()) {
                const auto [row, col] = rooms_queue.front();
                rooms_queue.pop();

                const auto distance = rooms[row][col] + 1;
                const std::array<size_t, 4> row_sequence = {row - 1, row, row + 1, row};
                const std::array<size_t, 4> col_sequence = {col, col + 1, col, col - 1};
                for (size_t i = 0; i < row_sequence.size(); ++i) {
                    const auto room_row = row_sequence[i];
                    const auto room_col = col_sequence[i];
                    if (room_row >= m_row_num || room_col >= m_col_num) { continue; }

                    const auto& room_val = rooms[room_row][room_col];
                    if (room_val == WALL || room_val == GATE) { continue; }

                    const auto new_distance = std::min(distance, room_val);
                    if (new_distance < room_val) {
                        rooms[room_row][room_col] = new_distance;
                        rooms_queue.push({room_row, room_col});
                    }
                }
            }
        }
    };
}

#endif //CPPNOTESMAIN_WALLS_AND_GATES_HPP
