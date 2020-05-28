#include <boost/test/unit_test.hpp>
#include <string>
#include "algorithms/data_structures/string/is_str_permutation.hpp"

BOOST_AUTO_TEST_SUITE(TestIsStrPermutation)

BOOST_AUTO_TEST_CASE(empty_str)
{
    BOOST_CHECK(Algo::DS::String::IsPermutationSort(std::string(), std::string()));
    BOOST_CHECK(Algo::DS::String::IsPermutationCount(std::string(), std::string()));
}

BOOST_AUTO_TEST_CASE(diff_size)
{
    BOOST_CHECK(false == Algo::DS::String::IsPermutationSort(std::string(), "abc"));
    BOOST_CHECK(false == Algo::DS::String::IsPermutationCount(std::string(), "abc"));

    BOOST_CHECK(false == Algo::DS::String::IsPermutationSort("abc", std::string()));
    BOOST_CHECK(false == Algo::DS::String::IsPermutationCount("abc", std::string()));
}

BOOST_AUTO_TEST_CASE(test_is_str_perm)
{
    BOOST_CHECK(Algo::DS::String::IsPermutationSort("abc", "bac"));
    BOOST_CHECK(Algo::DS::String::IsPermutationCount("abc", "bac"));
}

BOOST_AUTO_TEST_CASE(same_str)
{
    BOOST_CHECK(Algo::DS::String::IsPermutationSort("aburoiwjhkc", "aburoiwjhkc"));
    BOOST_CHECK(Algo::DS::String::IsPermutationCount("aburoiwjhkc", "aburoiwjhkc"));
}

BOOST_AUTO_TEST_CASE(long_str)
{
    BOOST_CHECK(Algo::DS::String::IsPermutationSort("aburowijhkc", "aburoiwjhkc"));
    BOOST_CHECK(Algo::DS::String::IsPermutationCount("aburowijhkc", "aburoiwjhkc"));
}

BOOST_AUTO_TEST_CASE(not_case)
{
    BOOST_CHECK(false == Algo::DS::String::IsPermutationSort("aburowijhkc", "aburpiwjhkc"));
    BOOST_CHECK(false == Algo::DS::String::IsPermutationCount("aburowijhkc", "aburpiwjhkc"));
}

BOOST_AUTO_TEST_SUITE_END()
