#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/count_and_say.hpp"

BOOST_AUTO_TEST_SUITE(TestCountAndSay)

    BOOST_AUTO_TEST_CASE(valid_str)
    {
        Algo::DS::String::CountAndSay solution;
        BOOST_CHECK(std::string() == solution.countAndSay(0));
        BOOST_CHECK("1" == solution.countAndSay(1));
        BOOST_CHECK("11" == solution.countAndSay(2));
        BOOST_CHECK("21" == solution.countAndSay(3));
        BOOST_CHECK("1211" == solution.countAndSay(4));
        BOOST_CHECK("111221" == solution.countAndSay(5));
    }

BOOST_AUTO_TEST_SUITE_END()
