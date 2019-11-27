#include <boost/test/unit_test.hpp>
#include <string>
#include "algorithms/strings/is_str_permutation.hpp"

BOOST_AUTO_TEST_SUITE(TestIsStrPermutation)

BOOST_AUTO_TEST_CASE(empty_str)
{
    BOOST_CHECK(IsPermutationSort(std::string(), std::string()));
    BOOST_CHECK(IsPermutationCount(std::string(), std::string()));
}

BOOST_AUTO_TEST_CASE(diff_size)
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

BOOST_AUTO_TEST_CASE(same_str)
{
    BOOST_CHECK(IsPermutationSort("aburoiwjhkc", "aburoiwjhkc"));
    BOOST_CHECK(IsPermutationCount("aburoiwjhkc", "aburoiwjhkc"));
}

BOOST_AUTO_TEST_CASE(long_str)
{
    BOOST_CHECK(IsPermutationSort("aburowijhkc", "aburoiwjhkc"));
    BOOST_CHECK(IsPermutationCount("aburowijhkc", "aburoiwjhkc"));
}

BOOST_AUTO_TEST_CASE(not_case)
{
    BOOST_CHECK(false == IsPermutationSort("aburowijhkc", "aburpiwjhkc"));
    BOOST_CHECK(false == IsPermutationCount("aburowijhkc", "aburpiwjhkc"));
}

BOOST_AUTO_TEST_SUITE_END()
