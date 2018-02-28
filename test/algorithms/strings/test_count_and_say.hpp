#ifndef TEST_COUNT_AND_SAY_HPP
#define TEST_COUNT_AND_SAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/count_and_say.hpp"

BOOST_AUTO_TEST_CASE(test_cas_valid_str)
{
    CountAndSay::Solution solution;
    BOOST_CHECK(std::string() == solution.countAndSay(0));
    BOOST_CHECK("1" == solution.countAndSay(1));
    BOOST_CHECK("11" == solution.countAndSay(2));
    BOOST_CHECK("21" == solution.countAndSay(3));
    BOOST_CHECK("1211" == solution.countAndSay(4));
    BOOST_CHECK("111221" == solution.countAndSay(5));

}

#endif // TEST_COUNT_AND_SAY_HPP
