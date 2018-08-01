#ifndef TEST_REVERSE_WORDS_IN_STRING_HPP
#define TEST_REVERSE_WORDS_IN_STRING_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/reverse_words_in_string.hpp"

BOOST_AUTO_TEST_CASE(test_rwis_empty_string)
{
    {
        std::string str = "";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("" == str);
    }

    {
        std::string str = " ";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("" == str);
    }

    {
        std::string str = "     ";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("" == str);
    }

    {
        std::string str = "";
        Algo::Strigns::ReverseWords::ReverseLettersInWords(str);
        BOOST_CHECK("" == str);
    }
}

BOOST_AUTO_TEST_CASE(test_rwis_one_word)
{
    {
        std::string str = "a";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("a" == str);
    }

    {
        std::string str = "a    ", expected = "a";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("a" == str);
    }

    {
        std::string str = "    a", expected = "a";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("a" == str);
    }

    {
        std::string str = "    a   ", expected = "a";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("a" == str);
    }

    {
        std::string str = " ab   ", expected = "ab";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("ab" == str);
    }

    {
        std::string str = "a";
        Algo::Strigns::ReverseWords::ReverseLettersInWords(str);
        BOOST_CHECK("a" == str);
    }

    {
        std::string str = "ab";
        Algo::Strigns::ReverseWords::ReverseLettersInWords(str);
        BOOST_CHECK("ba" == str);
    }
}

BOOST_AUTO_TEST_CASE(test_rwis_several_words)
{
    {
        std::string str = "ab cd";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("cd ab" == str);
    }

    {
        std::string str = "  the  sky is   blue   ";
        Algo::Strigns::ReverseWords::ReverseWordsOrder(str);
        BOOST_CHECK("blue is sky the" == str);
    }

    {
        std::string str = "ab cd";
        Algo::Strigns::ReverseWords::ReverseLettersInWords(str);
        BOOST_CHECK("ba dc" == str);
    }

    {
        std::string str = "the sky is blue";
        Algo::Strigns::ReverseWords::ReverseLettersInWords(str);
        BOOST_CHECK("eht yks si eulb" == str);
    }

    {
        std::string str = "Let's take LeetCode contest";
        Algo::Strigns::ReverseWords::ReverseLettersInWords(str);
        BOOST_CHECK("s'teL ekat edoCteeL tsetnoc" == str);
    }
}

#endif // TEST_REVERSE_WORDS_IN_STRING_HPP
