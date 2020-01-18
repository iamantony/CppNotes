#include <boost/test/unit_test.hpp>
#include "algorithms/math/evaluate_reverse_polish_notation.hpp"

BOOST_AUTO_TEST_SUITE(TestEvaluateReversePolishNotation)

BOOST_AUTO_TEST_CASE(no_tokens)
{
    const std::vector<std::string> tokens;
    const int expected = 0;
    BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
}

BOOST_AUTO_TEST_CASE(addition_of_two_values)
{
    const std::vector<std::string> tokens = {"5", "890", "+"};
    const int expected = 895;
    BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
}

BOOST_AUTO_TEST_CASE(subtraction_of_two_values)
{
    const std::vector<std::string> tokens = {"-1", "-7", "-"};
    const int expected = 6;
    BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
}

BOOST_AUTO_TEST_CASE(multiplication_of_two_values)
{
    const std::vector<std::string> tokens = {"-1", "10", "*"};
    const int expected = -10;
    BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
}

BOOST_AUTO_TEST_CASE(division_of_two_values)
{
    {
        const std::vector<std::string> tokens = {"1", "1", "/"};
        const int expected = 1;
        BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
    }

    {
        const std::vector<std::string> tokens = {"7", "3", "/"};
        const int expected = 2;
        BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
    }

    {
        const std::vector<std::string> tokens = {"1", "3", "/"};
        const int expected = 0;
        BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
    }

    {
        const std::vector<std::string> tokens = {"0", "5", "/"};
        const int expected = 0;
        BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
    }

    {
        const std::vector<std::string> tokens = {"12", "0", "/"};
        const int expected = 0;
        BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
    }
}

BOOST_AUTO_TEST_CASE(long_valid_expession)
{
    {
        const std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
        const int expected = 9;
        BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
    }

    {
        const std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
        const int expected = 6;
        BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
    }

    {
        const std::vector<std::string> tokens =
            {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        const int expected = 22;
        BOOST_CHECK(expected == Algo::Math::ReversePolishNotation::evaluate(tokens));
    }
}

BOOST_AUTO_TEST_SUITE_END()
