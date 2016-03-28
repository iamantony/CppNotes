#ifndef IS_STR_PERMUTATION_HPP_
#define IS_STR_PERMUTATION_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <string>

#include "ctci5/data_structs/is_str_permutation.hpp"

BOOST_AUTO_TEST_CASE(test_is_str_perm_empty_str)
{
    BOOST_CHECK(IsPermutationSort(std::string(), std::string()));
    BOOST_CHECK(IsPermutationCount(std::string(), std::string()));
}

BOOST_AUTO_TEST_CASE(test_is_str_perm_diff_size)
{
    BOOST_CHECK(false == IsPermutationSort(std::string(), "abc"));
    BOOST_CHECK(false == IsPermutationCount(std::string(), "abc"));

    BOOST_CHECK(false == IsPermutationSort("abc", std::string()));
    BOOST_CHECK(false == IsPermutationCount("abc", std::string()));
}

BOOST_AUTO_TEST_CASE(test_is_str_perm)
{
    BOOST_CHECK(IsPermutationSort("abc", "bac"));
    BOOST_CHECK(IsPermutationCount("abc", "bac"));
}

BOOST_AUTO_TEST_CASE(test_is_str_perm_same_str)
{
    BOOST_CHECK(IsPermutationSort("aburoiwjhkc", "aburoiwjhkc"));
    BOOST_CHECK(IsPermutationCount("aburoiwjhkc", "aburoiwjhkc"));
}

BOOST_AUTO_TEST_CASE(test_is_str_perm_long_str)
{
    BOOST_CHECK(IsPermutationSort("aburowijhkc", "aburoiwjhkc"));
    BOOST_CHECK(IsPermutationCount("aburowijhkc", "aburoiwjhkc"));
}

BOOST_AUTO_TEST_CASE(test_is_str_perm_not_case)
{
    BOOST_CHECK(false == IsPermutationSort("aburowijhkc", "aburpiwjhkc"));
    BOOST_CHECK(false == IsPermutationCount("aburowijhkc", "aburpiwjhkc"));
}

#endif /* IS_STR_PERMUTATION_HPP_ */
