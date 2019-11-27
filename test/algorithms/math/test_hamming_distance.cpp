#include <boost/test/unit_test.hpp>
#include "algorithms/math/hamming_distance.hpp"

BOOST_AUTO_TEST_SUITE(TestHammingDistance)

BOOST_AUTO_TEST_CASE(str_empty_strings)
{
    HammingDistance::Solution solution;
    BOOST_CHECK(0 == solution.HammingDistanceForStrings(std::string(),
                                                        std::string()));
}

BOOST_AUTO_TEST_CASE(str_one_empty_string)
{
    HammingDistance::Solution solution;
    BOOST_CHECK(-1 == solution.HammingDistanceForStrings(std::string("123"),
                                                        std::string()));

    BOOST_CHECK(-1 == solution.HammingDistanceForStrings(std::string(),
                                                        std::string("1234")));
}

BOOST_AUTO_TEST_CASE(str_strings_of_dif_size)
{
    HammingDistance::Solution solution;
    BOOST_CHECK(-1 == solution.HammingDistanceForStrings("asdf", "bv"));
    BOOST_CHECK(-1 == solution.HammingDistanceForStrings("a", "bvt"));
}

BOOST_AUTO_TEST_CASE(str_equal_strings)
{
    HammingDistance::Solution solution;
    BOOST_CHECK(0 == solution.HammingDistanceForStrings("abc1", "abc1"));
}

BOOST_AUTO_TEST_CASE(str_dif_strings)
{
    HammingDistance::Solution solution;
    BOOST_CHECK(2 == solution.HammingDistanceForStrings("abb2", "abc1"));
    BOOST_CHECK(4 == solution.HammingDistanceForStrings("zabbee", "aabc1d"));
}

BOOST_AUTO_TEST_CASE(int_nulls)
{
    HammingDistance::Solution solution;
    BOOST_CHECK(0 == solution.HammingDistanceForInts(0, 0));
    BOOST_CHECK(0 == solution.HammingDistanceForIntsFast(0, 0));
}

BOOST_AUTO_TEST_CASE(int_diff_values)
{
    HammingDistance::Solution solution;
    BOOST_CHECK(1 == solution.HammingDistanceForInts(1, 0));
    BOOST_CHECK(1 == solution.HammingDistanceForInts(2, 0));
    BOOST_CHECK(8 == solution.HammingDistanceForInts(143, 5628));
    BOOST_CHECK(25 == solution.HammingDistanceForInts(-143, 5628));

    BOOST_CHECK(1 == solution.HammingDistanceForIntsFast(1, 0));
    BOOST_CHECK(1 == solution.HammingDistanceForIntsFast(2, 0));
    BOOST_CHECK(8 == solution.HammingDistanceForIntsFast(143, 5628));
}

BOOST_AUTO_TEST_SUITE_END()
