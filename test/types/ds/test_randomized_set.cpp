#include <boost/test/unit_test.hpp>
#include "types/ds/randomized_set.hpp"

BOOST_AUTO_TEST_SUITE(TestRandomizedSet)

    BOOST_AUTO_TEST_CASE(creation)
    {
        Types::DS::RandomizedSet set;
        BOOST_CHECK(set.size() == 0);
    }

BOOST_AUTO_TEST_SUITE_END()
