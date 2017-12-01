#ifndef TEST_FIND_SINGLE_ITEM_HPP
#define TEST_FIND_SINGLE_ITEM_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/search/find_single_item.hpp"

BOOST_AUTO_TEST_CASE(test_fsi_vector_empty)
{
    FindSingleItem::Solution solution;
    BOOST_CHECK(-1 == solution.singleNumberHash(std::vector<int>()));
    BOOST_CHECK(0 == solution.singleNumberMath(std::vector<int>()));
    BOOST_CHECK(0 == solution.singleNumberBitManipulation(std::vector<int>()));
}

BOOST_AUTO_TEST_CASE(test_fsi_one_elem)
{
    FindSingleItem::Solution solution;
    BOOST_CHECK(1 == solution.singleNumberHash({1}));
    BOOST_CHECK(1 == solution.singleNumberMath({1}));
    BOOST_CHECK(1 == solution.singleNumberBitManipulation({1}));
}

BOOST_AUTO_TEST_CASE(test_fsi_two_elements)
{
    FindSingleItem::Solution solution;
    BOOST_CHECK(-1 == solution.singleNumberHash({1, 1}));
    BOOST_CHECK(0 == solution.singleNumberMath({1, 1}));
    BOOST_CHECK(0 == solution.singleNumberBitManipulation({1, 1}));
}

BOOST_AUTO_TEST_CASE(test_fsi_several_elements)
{
    FindSingleItem::Solution solution;
    BOOST_CHECK(3 == solution.singleNumberHash({1, 2, 2, 3, 1, 4, 4}));
    BOOST_CHECK(3 == solution.singleNumberMath({1, 2, 2, 3, 1, 4, 4}));
    BOOST_CHECK(3 == solution.singleNumberBitManipulation({1, 2, 2, 3, 1, 4, 4}));
}

#endif // TEST_FIND_SINGLE_ITEM_HPP
