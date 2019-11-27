#include <boost/test/unit_test.hpp>
#include <numeric>
#include "algorithms/math/reverse_integer.hpp"

BOOST_AUTO_TEST_SUITE(TestReverseInteger)

BOOST_AUTO_TEST_CASE(zero)
{
    int value = 0;
    int expected = 0;
    BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
}

BOOST_AUTO_TEST_CASE(small_value)
{
    {
        int value = 8;
        int expected = 8;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }

    {
        int value = -4;
        int expected = -4;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }
}

BOOST_AUTO_TEST_CASE(decent_value)
{
    {
        int value = 132;
        int expected = 231;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }

    {
        int value = -7891;
        int expected = -1987;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }
}

BOOST_AUTO_TEST_CASE(value_with_zero)
{
    {
        int value = 10;
        int expected = 1;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }

    {
        int value = -12050;
        int expected = -5021;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }
}

BOOST_AUTO_TEST_CASE(huge_value)
{
    {
        int value = std::numeric_limits<int>::max();
        int expected = 0;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }

    {
        int value = std::numeric_limits<int>::min();
        int expected = 0;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }

    {
        int value = 1534236469;
        int expected = 0;
        BOOST_CHECK(expected == Algo::Math::ReverseInteger::Reverse(value));
    }
}

BOOST_AUTO_TEST_SUITE_END()
