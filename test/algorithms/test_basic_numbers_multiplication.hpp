#ifndef TEST_BASIC_NUMBERS_MULTIPLICATION_HPP_
#define TEST_BASIC_NUMBERS_MULTIPLICATION_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <string>

#include "algorithms/basic_numbers_multiplication.hpp"

BOOST_AUTO_TEST_CASE(test_empty_numbers)
{
    BOOST_CHECK(0 == BasicNumbersMultiplication(std::string(), std::string()));
    BOOST_CHECK(0 == BasicNumbersMultiplication(std::string("123"),
            std::string()));

    BOOST_CHECK(0 == BasicNumbersMultiplication(std::string(),
            std::string("456")));
}

BOOST_AUTO_TEST_CASE(test_null_numbers)
{
    BOOST_CHECK(0 == BasicNumbersMultiplication(std::string("0"),
            std::string("0")));

    BOOST_CHECK(0 == BasicNumbersMultiplication(std::string("123"),
                std::string("0")));

    BOOST_CHECK(0 == BasicNumbersMultiplication(std::string("0"),
                std::string("123")));
}

BOOST_AUTO_TEST_CASE(test_small_numbers)
{
    BOOST_CHECK(1 == BasicNumbersMultiplication(std::string("1"),
            std::string("1")));

    BOOST_CHECK(20 == BasicNumbersMultiplication(std::string("10"),
                std::string("2")));

    BOOST_CHECK(770 == BasicNumbersMultiplication(std::string("14"),
                std::string("55")));
}

BOOST_AUTO_TEST_CASE(test_big_numbers)
{
    BOOST_CHECK(3085153753124 == BasicNumbersMultiplication(std::string("895372"),
            std::string("3445667")));

    BOOST_CHECK(121932631112635269 ==
            BasicNumbersMultiplication(std::string("987654321"),
                    std::string("123456789")));
}

#endif /* TEST_BASIC_NUMBERS_MULTIPLICATION_HPP_ */
