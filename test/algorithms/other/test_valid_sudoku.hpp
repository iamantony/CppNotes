#ifndef TEST_VALID_SUDOKU_HPP
#define TEST_VALID_SUDOKU_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/other/valid_sudoku.hpp"

BOOST_AUTO_TEST_CASE(test_vsud_empty_arr)
{
    ValidSudoku::Solution solution;
    std::vector<std::vector<char>> board = {};
    BOOST_CHECK(false == solution.isValidSudoku(board));
}

BOOST_AUTO_TEST_CASE(test_vsud_valid_board)
{
    ValidSudoku::Solution solution;
    std::vector<std::vector<char>> board =
        { {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
          {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'4', '.', '1', '.', '.', '.', '.', '.', '.'},
          {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'6', '.', '.', '.', '.', '5', '.', '.', '.'},
          {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'9', '.', '.', '.', '.', '.', '.', '.', '7'} };
    BOOST_CHECK(true == solution.isValidSudoku(board));
}

#endif // TEST_VALID_SUDOKU_HPP
