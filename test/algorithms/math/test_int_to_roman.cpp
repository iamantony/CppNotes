#include <limits>
#include <boost/test/unit_test.hpp>
#include "algorithms/math/int_to_roman.hpp"

BOOST_AUTO_TEST_SUITE(ConversionOfIntegerToRomanNumber)

BOOST_AUTO_TEST_CASE(invalid_numbers)
{
    BOOST_CHECK(Algo::Math::IntToRoman::Convert(
                    std::numeric_limits<int>::min()).empty());

    BOOST_CHECK(Algo::Math::IntToRoman::Convert(-12).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::Convert(-1).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::Convert(0).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::Convert(4000).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::Convert(4001).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::Convert(15000).empty());

    BOOST_CHECK(Algo::Math::IntToRoman::Convert(
                    std::numeric_limits<int>::max()).empty());

    BOOST_CHECK(Algo::Math::IntToRoman::ConvertSimple(
                    std::numeric_limits<int>::min()).empty());

    BOOST_CHECK(Algo::Math::IntToRoman::ConvertSimple(-12).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::ConvertSimple(-1).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::ConvertSimple(0).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::ConvertSimple(4000).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::ConvertSimple(4001).empty());
    BOOST_CHECK(Algo::Math::IntToRoman::ConvertSimple(15000).empty());

    BOOST_CHECK(Algo::Math::IntToRoman::ConvertSimple(
                    std::numeric_limits<int>::max()).empty());
}

BOOST_AUTO_TEST_CASE(main_numbers)
{
    BOOST_CHECK(std::string("I") == Algo::Math::IntToRoman::Convert(1));
    BOOST_CHECK(std::string("V") == Algo::Math::IntToRoman::Convert(5));
    BOOST_CHECK(std::string("X") == Algo::Math::IntToRoman::Convert(10));
    BOOST_CHECK(std::string("L") == Algo::Math::IntToRoman::Convert(50));
    BOOST_CHECK(std::string("C") == Algo::Math::IntToRoman::Convert(100));
    BOOST_CHECK(std::string("D") == Algo::Math::IntToRoman::Convert(500));
    BOOST_CHECK(std::string("M") == Algo::Math::IntToRoman::Convert(1000));

    BOOST_CHECK(std::string("I") == Algo::Math::IntToRoman::ConvertSimple(1));
    BOOST_CHECK(std::string("V") == Algo::Math::IntToRoman::ConvertSimple(5));
    BOOST_CHECK(std::string("X") == Algo::Math::IntToRoman::ConvertSimple(10));
    BOOST_CHECK(std::string("L") == Algo::Math::IntToRoman::ConvertSimple(50));
    BOOST_CHECK(std::string("C") == Algo::Math::IntToRoman::ConvertSimple(100));
    BOOST_CHECK(std::string("D") == Algo::Math::IntToRoman::ConvertSimple(500));
    BOOST_CHECK(std::string("M") == Algo::Math::IntToRoman::ConvertSimple(1000));
}

BOOST_AUTO_TEST_CASE(main_susbstract_numbers)
{
    BOOST_CHECK(std::string("IV") == Algo::Math::IntToRoman::Convert(4));
    BOOST_CHECK(std::string("IX") == Algo::Math::IntToRoman::Convert(9));
    BOOST_CHECK(std::string("XL") == Algo::Math::IntToRoman::Convert(40));
    BOOST_CHECK(std::string("XC") == Algo::Math::IntToRoman::Convert(90));
    BOOST_CHECK(std::string("CD") == Algo::Math::IntToRoman::Convert(400));
    BOOST_CHECK(std::string("CM") == Algo::Math::IntToRoman::Convert(900));

    BOOST_CHECK(std::string("IV") == Algo::Math::IntToRoman::ConvertSimple(4));
    BOOST_CHECK(std::string("IX") == Algo::Math::IntToRoman::ConvertSimple(9));
    BOOST_CHECK(std::string("XL") == Algo::Math::IntToRoman::ConvertSimple(40));
    BOOST_CHECK(std::string("XC") == Algo::Math::IntToRoman::ConvertSimple(90));
    BOOST_CHECK(std::string("CD") == Algo::Math::IntToRoman::ConvertSimple(400));
    BOOST_CHECK(std::string("CM") == Algo::Math::IntToRoman::ConvertSimple(900));
}

BOOST_AUTO_TEST_CASE(main_valid_numbers)
{
    BOOST_CHECK(std::string("II") == Algo::Math::IntToRoman::Convert(2));
    BOOST_CHECK(std::string("III") == Algo::Math::IntToRoman::Convert(3));
    BOOST_CHECK(std::string("VIII") == Algo::Math::IntToRoman::Convert(8));
    BOOST_CHECK(std::string("XIV") == Algo::Math::IntToRoman::Convert(14));
    BOOST_CHECK(std::string("XXXIX") == Algo::Math::IntToRoman::Convert(39));
    BOOST_CHECK(std::string("XLIV") == Algo::Math::IntToRoman::Convert(44));
    BOOST_CHECK(std::string("LVIII") == Algo::Math::IntToRoman::Convert(58));
    BOOST_CHECK(std::string("LXXXII") == Algo::Math::IntToRoman::Convert(82));
    BOOST_CHECK(std::string("MMMCMXCIV") ==
                Algo::Math::IntToRoman::Convert(3994));

    BOOST_CHECK(std::string("II") == Algo::Math::IntToRoman::ConvertSimple(2));
    BOOST_CHECK(std::string("III") == Algo::Math::IntToRoman::ConvertSimple(3));
    BOOST_CHECK(std::string("VIII") == Algo::Math::IntToRoman::ConvertSimple(8));
    BOOST_CHECK(std::string("XIV") == Algo::Math::IntToRoman::ConvertSimple(14));
    BOOST_CHECK(std::string("XXXIX") ==
                Algo::Math::IntToRoman::ConvertSimple(39));

    BOOST_CHECK(std::string("XLIV") ==
                Algo::Math::IntToRoman::ConvertSimple(44));

    BOOST_CHECK(std::string("LVIII") ==
                Algo::Math::IntToRoman::ConvertSimple(58));

    BOOST_CHECK(std::string("LXXXII") ==
                Algo::Math::IntToRoman::ConvertSimple(82));

    BOOST_CHECK(std::string("MMMCMXCIV") ==
                Algo::Math::IntToRoman::ConvertSimple(3994));
}

BOOST_AUTO_TEST_SUITE_END()
