#include <boost/test/unit_test.hpp>
#include "algorithms/hashmap/word_pattern.hpp"

BOOST_AUTO_TEST_SUITE(TestWordPattern)

    BOOST_AUTO_TEST_CASE(invalid_input)
    {
        BOOST_CHECK(Algo::HashMap::WordPattern::check({}, {}));
        BOOST_CHECK(!Algo::HashMap::WordPattern::check("a", {}));
        BOOST_CHECK(!Algo::HashMap::WordPattern::check({}, "a"));
    }

    BOOST_AUTO_TEST_CASE(valid_input)
    {
        BOOST_CHECK(Algo::HashMap::WordPattern::check("c", "a"));
        BOOST_CHECK(Algo::HashMap::WordPattern::check("abba", "dog cat cat dog"));
        BOOST_CHECK(!Algo::HashMap::WordPattern::check("abba", "dog cat cat fish"));
        BOOST_CHECK(!Algo::HashMap::WordPattern::check("aaaa", "dog cat cat dog"));
        BOOST_CHECK(!Algo::HashMap::WordPattern::check("abb", "dog cat cat dog"));
        BOOST_CHECK(!Algo::HashMap::WordPattern::check("abba", "dog dog dog dog"));
    }

BOOST_AUTO_TEST_SUITE_END()
