#ifndef TEST_STR_COMPRESSION_HPP_
#define TEST_STR_COMPRESSION_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "algorithms/strings/str_compression.hpp"

BOOST_AUTO_TEST_CASE(test_strcomp_empty_str)
{
    BOOST_CHECK(std::string() == CompressString(std::string()));
}

BOOST_AUTO_TEST_CASE(test_strcomp_no_compression)
{
    std::string str = "aa";
    BOOST_CHECK(str == CompressString(str));
}

BOOST_AUTO_TEST_CASE(test_strcomp_compression)
{
    std::string str = "aaabbyr55iiiiio";
    std::string expected = "a3b2y1r152i5o1";
    BOOST_CHECK(expected == CompressString(str));
}
#endif /* TEST_STR_COMPRESSION_HPP_ */
