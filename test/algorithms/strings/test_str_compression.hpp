#ifndef TEST_STR_COMPRESSION_HPP_
#define TEST_STR_COMPRESSION_HPP_

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/str_compression.hpp"

BOOST_AUTO_TEST_CASE(test_strcomp_empty_str)
{
    std::vector<char> chars = { }, expected = { };
    BOOST_CHECK(expected.size() ==
                Algo::Strings::StringCompression::Compress(chars));
    BOOST_CHECK(expected == chars);
}

BOOST_AUTO_TEST_CASE(test_strcomp_no_compression)
{
    {
        std::vector<char> chars = {'a'}, expected = {'a'};
        BOOST_CHECK(expected.size() ==
                    Algo::Strings::StringCompression::Compress(chars));
        BOOST_CHECK(expected == chars);
    }

    {
        std::vector<char> chars = {'a', 'b'}, expected = {'a', 'b'};
        BOOST_CHECK(expected.size() ==
                    Algo::Strings::StringCompression::Compress(chars));
        BOOST_CHECK(expected == chars);
    }

    {
        std::vector<char> chars = {'a', 'b', 'a', 'b'},
                expected = {'a', 'b', 'a', 'b'};

        BOOST_CHECK(expected.size() ==
                    Algo::Strings::StringCompression::Compress(chars));
        BOOST_CHECK(expected == chars);
    }
}

BOOST_AUTO_TEST_CASE(test_strcomp_compression)
{
    {
        std::vector<char> chars = {'a', 'a'}, expected = {'a', '2'};
        BOOST_CHECK(expected.size() ==
                    Algo::Strings::StringCompression::Compress(chars));
        BOOST_CHECK(expected == chars);
    }

    {
        std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'},
                expected = {'a', '2', 'b', '2', 'c', '3'};

        BOOST_CHECK(expected.size() ==
                    Algo::Strings::StringCompression::Compress(chars));
        BOOST_CHECK(expected == chars);
    }

    {
        std::vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'b', 'b'},
                expected = {'a', '2', 'b', '5'};

        BOOST_CHECK(expected.size() ==
                    Algo::Strings::StringCompression::Compress(chars));
        BOOST_CHECK(expected == chars);
    }
}
#endif /* TEST_STR_COMPRESSION_HPP_ */
