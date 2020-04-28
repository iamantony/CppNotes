#include <boost/test/unit_test.hpp>
#include "types/ds/direct_addressing_table.hpp"

BOOST_AUTO_TEST_SUITE(DSConcurrentMap)

    BOOST_AUTO_TEST_CASE(create_and_destroy)
    {
        Types::DS::DirectAddressingTable<char> dat;
        BOOST_CHECK(true);
    }

    BOOST_AUTO_TEST_CASE(insert_access_erase)
    {
        Types::DS::DirectAddressingTable<char> dat;
        dat.insert(12, 'c');
        dat.insert(13, 'b');
        dat.insert(255, 'a');
        dat.insert(0, 'y');
        BOOST_CHECK('b' == dat.at(13));
        dat.insert(13, 'o');
        BOOST_CHECK('o' == dat.at(13));
        BOOST_CHECK(dat.contains(255));
        BOOST_CHECK(!dat.contains(254));
        dat.erase(255);
        BOOST_CHECK(!dat.contains(255));
    }

BOOST_AUTO_TEST_SUITE_END()

