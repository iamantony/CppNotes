#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/str_decoding.hpp"

BOOST_AUTO_TEST_SUITE(TestStrDecoding)

BOOST_AUTO_TEST_CASE(empty_string)
{
    const std::string input = {};
    const std::string expected = {};
    BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
}

BOOST_AUTO_TEST_CASE(simple_string_with_one_symbol)
{
    const std::string input = "a";
    const std::string expected = "a";
    BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
}

BOOST_AUTO_TEST_CASE(simple_string_with_several_symbols)
{
    const std::string input = "abc";
    const std::string expected = "abc";
    BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
}

BOOST_AUTO_TEST_CASE(simple_code_string_with_one_symbol)
{
    {
        const std::string input = "0[a]";
        const std::string expected = {};
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "1[a]";
        const std::string expected = "a";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "5[a]";
        const std::string expected = "aaaaa";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "12[a]";
        const std::string expected = "aaaaaaaaaaaa";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }
}

BOOST_AUTO_TEST_CASE(code_string_with_several_symbol)
{
    {
        const std::string input = "0[rty]";
        const std::string expected = {};
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "2[rty]";
        const std::string expected = "rtyrty";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "15[jj]";
        const std::string expected = "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjj";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }
}

BOOST_AUTO_TEST_CASE(multilevel_code_string)
{
    {
        const std::string input = "1[r4[ty]]";
        const std::string expected = "rtytytyty";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "2[rty]gi";
        const std::string expected = "rtyrtygi";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "3[j2[o1[i]]]";
        const std::string expected = "joioijoioijoioi";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }
}

BOOST_AUTO_TEST_CASE(tricky_code_string)
{
    {
        const std::string input = "3[a]2[bc]";
        const std::string expected = "aaabcbc";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "3[a2[c]]";
        const std::string expected = "accaccacc";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "2[abc]3[cd]ef";
        const std::string expected = "abcabccdcdcdef";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "3[a]2[b4[F]c]";
        const std::string expected = "aaabFFFFcbFFFFc";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }

    {
        const std::string input = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
        const std::string expected = "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";
        BOOST_CHECK(expected == Algo::DS::String::StrDecoding::decode(input));
    }
}

BOOST_AUTO_TEST_SUITE_END()
