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

namespace Algo { namespace Other {

class ValidSudoku {
public:
    static bool isValid(std::vector<std::vector<char>>& sudoku) {
        const size_t SIZE = 9;
        if (sudoku.size() != SIZE) {
            return false;
        }

        for (size_t row = 0; row < sudoku.size(); ++row) {
            if (sudoku[row].size() != SIZE) {
                return false;
            }
        }

        auto check = [&](const size_t& rStart, const size_t& rEnd,
                         const size_t& cStart, const size_t& cEnd) -> bool {
            std::set<int> numbers;
            for(size_t row = rStart; row <= rEnd; ++row) {
                for(size_t col = cStart; col <= cEnd; ++col) {
                    if (sudoku[row][col] == '.') {
                        continue;
                    }

                    int num = sudoku[row][col] - '0';
                    if (num < 0 || num > 9) {
                        return false;
                    }

                    if (numbers.count(num) > 0) {
                        return false;
                    }

                    numbers.insert(num);
                }
            }

            return true;
        };

        for (size_t row = 0; row < SIZE; ++row) {
            if (!check(row, row, 0, SIZE - 1)) {
                return false;
            }
        }

        for (size_t col = 0; col < SIZE; ++col) {
            if (!check(0, SIZE - 1, col, col)) {
                return false;
            }
        }

        const size_t BOX_SIZE = SIZE / 3;
        for (size_t row = 0; row < SIZE; row += BOX_SIZE) {
            for (size_t col = 0; col < SIZE; col += BOX_SIZE) {
                if (!check(row, row + BOX_SIZE - 1,
                           col, col + BOX_SIZE - 1)) {
                    return false;
                }
            }
        }

        return true;
    }
};

} }

#endif // VALID_SUDOKU_HPP
