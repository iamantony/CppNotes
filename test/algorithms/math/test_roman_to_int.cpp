#include <boost/test/unit_test.hpp>
#include "algorithms/math/roman_to_int.hpp"

BOOST_AUTO_TEST_SUITE(ConversionOfRomanToIntegerNumber)

BOOST_AUTO_TEST_CASE(main_numbers)
{
    BOOST_CHECK(1 == Algo::Math::RomanToInt::Convert("I"));
    BOOST_CHECK(5 == Algo::Math::RomanToInt::Convert("V"));
    BOOST_CHECK(10 == Algo::Math::RomanToInt::Convert("X"));
    BOOST_CHECK(50 == Algo::Math::RomanToInt::Convert("L"));
    BOOST_CHECK(100 == Algo::Math::RomanToInt::Convert("C"));
    BOOST_CHECK(500 == Algo::Math::RomanToInt::Convert("D"));
    BOOST_CHECK(1000 == Algo::Math::RomanToInt::Convert("M"));
}

BOOST_AUTO_TEST_CASE(main_susbstract_numbers)
{
    BOOST_CHECK(4 == Algo::Math::RomanToInt::Convert("IV"));
    BOOST_CHECK(9 == Algo::Math::RomanToInt::Convert("IX"));
    BOOST_CHECK(40 == Algo::Math::RomanToInt::Convert("XL"));
    BOOST_CHECK(90 == Algo::Math::RomanToInt::Convert("XC"));
    BOOST_CHECK(400 == Algo::Math::RomanToInt::Convert("CD"));
    BOOST_CHECK(900 == Algo::Math::RomanToInt::Convert("CM"));
}

BOOST_AUTO_TEST_CASE(main_valid_numbers)
{
    BOOST_CHECK(2 == Algo::Math::RomanToInt::Convert("II"));
    BOOST_CHECK(3 == Algo::Math::RomanToInt::Convert("III"));
    BOOST_CHECK(8 == Algo::Math::RomanToInt::Convert("VIII"));
    BOOST_CHECK(14 == Algo::Math::RomanToInt::Convert("XIV"));
    BOOST_CHECK(39 == Algo::Math::RomanToInt::Convert("XXXIX"));
    BOOST_CHECK(44 == Algo::Math::RomanToInt::Convert("XLIV"));
    BOOST_CHECK(58 == Algo::Math::RomanToInt::Convert("LVIII"));
    BOOST_CHECK(82 == Algo::Math::RomanToInt::Convert("LXXXII"));
    BOOST_CHECK(3994 == Algo::Math::RomanToInt::Convert("MMMCMXCIV"));
}

BOOST_AUTO_TEST_SUITE_END()
