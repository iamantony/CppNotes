#ifndef TEST_INVERSIONS_COUNTER_HPP_
#define TEST_INVERSIONS_COUNTER_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>
#include <vector>
#include <limits>

#include "algorithms/inversions_counter.hpp"

BOOST_AUTO_TEST_CASE(test_ic_empty_container)
{
    BOOST_CHECK(0 == InversionsCounter(vector<int>()));
}

BOOST_AUTO_TEST_CASE(test_ic_one_value)
{
    vector<int> container;
    container.push_back(42);

    BOOST_CHECK(0 == InversionsCounter(container));
}

BOOST_AUTO_TEST_CASE(test_ic_sorted_container)
{
    vector<int> container;
    container.push_back(0);
    container.push_back(42);
    container.push_back(43);
    container.push_back(100);

    BOOST_CHECK(0 == InversionsCounter(container));
}

BOOST_AUTO_TEST_CASE(test_ic_default_example)
{
    vector<int> container;
    container.push_back(1);
    container.push_back(3);
    container.push_back(5);
    container.push_back(2);
    container.push_back(4);
    container.push_back(6);

    BOOST_CHECK(3 == InversionsCounter(container));
}

#endif /* TEST_INVERSIONS_COUNTER_HPP_ */
