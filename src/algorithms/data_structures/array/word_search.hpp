#ifndef CPPNOTESMAIN_WORD_SEARCH_HPP
#define CPPNOTESMAIN_WORD_SEARCH_HPP

/*
https://leetcode.com/problems/word-search/
Given an m x n board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells
are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
* m == board.length
* n = board[i].length
* 1 <= m, n <= 200
* 1 <= word.length <= 103
* board and word consists only of lowercase and uppercase English letters.
*/

#include <vector>
#include <string>

namespace Algo::DS::Array {
    class WordSearch {
        const std::vector<int> r_shifts = {-1, 0, 1, 0};
        const std::vector<int> c_shifts = {0, 1, 0, -1};
        const char VC = '%';

        size_t m_max_r;
        size_t m_max_c;
        size_t m_w_pos;

        bool search(
            std::vector<std::vector<char>>& board, const std::string& word, size_t r, size_t c)
        {
            board[r][c] = VC;

            const auto cur_pos = m_w_pos;
            const auto next_w_pos = m_w_pos + 1;
            if (next_w_pos >= word.size()) { return true; }

            for (size_t i = 0; i < r_shifts.size(); ++i)  {
                const auto nr = r + r_shifts[i];
                const auto nc = c + c_shifts[i];
                if (nr >= m_max_r || nc >= m_max_c) { continue; }

                if (board[nr][nc] == word[next_w_pos]) {
                    m_w_pos = next_w_pos;
                    if (search(board, word, nr, nc)) { return true; }
                }
            }

            board[r][c] = word[m_w_pos];
            if (m_w_pos > 0) { --m_w_pos; }

            return false;
        }

    public:
        bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
            if (word.empty()) { return true; }

            m_max_r = board.size();
            m_max_c = board.front().size();
            m_w_pos = 0;

            for (size_t r = 0; r < m_max_r; ++r) {
                for (size_t c = 0; c < m_max_c; ++c) {
                    if (board[r][c] == word.front()) {
                        if (search(board, word, r, c)) { return true; }
                    }
                }
            }

            return false;
        }
    };
}

#endif //CPPNOTESMAIN_WORD_SEARCH_HPP
