#ifndef TEST_READ_LAST_LINES_HPP_
#define TEST_READ_LAST_LINES_HPP_

#include <boost/test/unit_test.hpp>
#include <filesystem>
#include <iostream>
#include <queue>

#include "files/read_last_lines.hpp"

BOOST_AUTO_TEST_CASE(test_rll_invalid_args)
{
    BOOST_CHECK(std::queue<std::string>() == ReadLastLines(std::string(), 0));
    BOOST_CHECK(std::queue<std::string>() == ReadLastLines(std::string(), 10));
}

BOOST_AUTO_TEST_CASE(test_rll_invalid_file)
{
    BOOST_CHECK(std::queue<std::string>() == ReadLastLines("hhh", 10));
}

BOOST_AUTO_TEST_CASE(test_rll)
{
    std::queue<std::string> expected;
    expected.push("third line");
    expected.push("fourth line");
    expected.push("last line");

    const auto test_file = std::filesystem::current_path() / "data" / "text_file.txt";
    BOOST_CHECK(expected == ReadLastLines(test_file.string(), 3));
}

#endif /* TEST_READ_LAST_LINES_HPP_ */
