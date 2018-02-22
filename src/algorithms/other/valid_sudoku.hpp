#ifndef VALID_SUDOKU_HPP
#define VALID_SUDOKU_HPP

// https://leetcode.com/problems/valid-sudoku/description/

// Determine if a Sudoku is valid, according to rules:
// - Each row must have the numbers 1-9 occuring just once.
// - Each column must have the numbers 1-9 occuring just once.
// - And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.

// The Sudoku board could be partially filled, where empty cells are filled
// with the character '.'.

#include <vector>
#include <set>

namespace ValidSudoku {

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        const size_t BOARD_DIMENSION = 9;
        if (board.size() != BOARD_DIMENSION) {
            return false;
        }

        for (auto line : board) {
            if (line.size() != BOARD_DIMENSION) {
                return false;
            }
        }

        // Check rows
        {
            for (auto line : board) {
                std::set<char> numbers;
                for (char element : line) {
                    if (element == '.') {
                        continue;
                    }

                    if (numbers.count(element) > 0) {
                        return false;
                    }

                    numbers.insert(element);
                }
            }
        }

        // Check columns
        {
            for (size_t col = 0; col < BOARD_DIMENSION; ++col) {
                std::set<char> numbers;
                for (size_t row = 0; row < BOARD_DIMENSION; ++row) {
                    char& element = board[row][col];
                    if (element == '.') {
                        continue;
                    }

                    if (numbers.count(element) > 0) {
                        return false;
                    }

                    numbers.insert(element);
                }
            }
        }

        // Check 3x3 boxes
        {
            const size_t BOX_DIMENSION = BOARD_DIMENSION / 3;

            auto checkBox = [&board, &BOX_DIMENSION](const size_t& rowStart,
                    const size_t& colStart) -> bool {

                std::set<char> numbers;
                for (size_t row = rowStart; row < rowStart + BOX_DIMENSION;
                     ++row)
                {
                    for (size_t col = colStart; col < colStart + BOX_DIMENSION;
                         ++col)
                    {
                        char& element = board[row][col];
                        if (element == '.') {
                            continue;
                        }

                        if (numbers.count(element) > 0) {
                            return false;
                        }

                        numbers.insert(element);
                    }
                }

                return true;
            };

            for (size_t row = 0; row < BOARD_DIMENSION; row += BOX_DIMENSION) {
                for (size_t col = 0; col < BOARD_DIMENSION;
                     col += BOX_DIMENSION) {
                    if (!checkBox(row, col)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

}

#endif // VALID_SUDOKU_HPP
