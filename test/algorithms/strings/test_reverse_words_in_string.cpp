#include <boost/test/unit_test.hpp>
#include "algorithms/strings/reverse_words_in_string.hpp"

BOOST_AUTO_TEST_SUITE(ReverseWordsInString)

BOOST_AUTO_TEST_CASE(empty_string)
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

BOOST_AUTO_TEST_CASE(one_word)
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

BOOST_AUTO_TEST_CASE(several_words)
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

BOOST_AUTO_TEST_SUITE_END()
