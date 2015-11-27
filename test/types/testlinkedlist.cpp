#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "src/types/linkedlist.hpp"

BOOST_AUTO_TEST_CASE(test_create_linkedlist)
{
    LinkedList<int> list;
    BOOST_TEST(true);
}
