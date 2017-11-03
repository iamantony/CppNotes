#ifndef TESTSTRPERMUTATIONS_HPP_
#define TESTSTRPERMUTATIONS_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <string>
#include <algorithm>

#include "algorithms/strings/str_permutations.hpp"

BOOST_AUTO_TEST_CASE(test_strperm_empty_str)
{
    BOOST_CHECK(std::vector<std::string>() ==
            GetStrPermutations(std::string()));
}

BOOST_AUTO_TEST_CASE(test_strperm_str_one_char)
{
    std::vector<std::string> expected;
    expected.push_back("a");

    BOOST_CHECK(expected == GetStrPermutations("a"));
}

BOOST_AUTO_TEST_CASE(test_strperm_str_two_chars)
{
    std::vector<std::string> expected;
    expected.push_back("ab");
    expected.push_back("ba");

    std::vector<std::string> result = GetStrPermutations("ab");
    for (const std::string& str : expected)
    {
        auto number = std::count(result.begin(), result.end(), str);
        BOOST_CHECK(1 == number);
    }
}

BOOST_AUTO_TEST_CASE(test_strperm_str_three_chars)
{
    std::vector<std::string> expected;
    expected.push_back("abc");
    expected.push_back("bac");
    expected.push_back("bca");
    expected.push_back("cba");
    expected.push_back("acb");
    expected.push_back("cab");

    std::vector<std::string> result = GetStrPermutations("abc");
    for (const std::string& str : expected)
    {
        auto number = std::count(result.begin(), result.end(), str);
        BOOST_CHECK(1 == number);
    }
}

BOOST_AUTO_TEST_CASE(test_strperm_str_many_chars)
{
    std::string string("gkhdf");
    std::sort(string.begin(), string.end());

    std::vector<std::string> expected;
    while(std::next_permutation(string.begin(), string.end()))
    {
        std::string permStr = string;
        expected.push_back(permStr);
    }

    std::vector<std::string> result = GetStrPermutations(string);
    for (const std::string& str : expected)
    {
        auto number = std::count(result.begin(), result.end(), str);
        BOOST_CHECK(1 == number);
    }
}

#endif /* TESTSTRPERMUTATIONS_HPP_ */
