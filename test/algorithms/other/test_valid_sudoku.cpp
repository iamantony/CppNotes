#include <boost/test/unit_test.hpp>
#include "algorithms/other/valid_sudoku.hpp"

BOOST_AUTO_TEST_SUITE(TestValidSudoku)

BOOST_AUTO_TEST_CASE(empty_arr)
{
    std::vector<std::vector<char>> sudoku = {};
    BOOST_CHECK(false == Algo::Other::ValidSudoku::isValid(sudoku));
}

BOOST_AUTO_TEST_CASE(valid_board)
{
    std::vector<std::vector<char>> sudoku =
        { {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
          {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'4', '.', '1', '.', '.', '.', '.', '.', '.'},
          {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'6', '.', '.', '.', '.', '5', '.', '.', '.'},
          {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
          {'9', '.', '.', '.', '.', '.', '.', '.', '7'} };
    BOOST_CHECK(true == Algo::Other::ValidSudoku::isValid(sudoku));
}

BOOST_AUTO_TEST_SUITE_END()
