#include <boost/test/unit_test.hpp>
#include <vector>
#include <limits>
#include "algorithms/sorting/inversions_counter.hpp"

BOOST_AUTO_TEST_SUITE(TestInversionsCounter)

BOOST_AUTO_TEST_CASE(empty_container)
{
    BOOST_CHECK(0 == InversionsCounter(std::vector<int>()));
}

BOOST_AUTO_TEST_CASE(one_value)
{
    std::vector<int> container;
    container.push_back(42);

    BOOST_CHECK(0 == InversionsCounter(container));
}

BOOST_AUTO_TEST_CASE(sorted_container)
{
    std::vector<int> container;
    container.push_back(0);
    container.push_back(42);
    container.push_back(43);
    container.push_back(100);

    BOOST_CHECK(0 == InversionsCounter(container));
}

BOOST_AUTO_TEST_CASE(default_example)
{
    std::vector<int> container;
    container.push_back(1);
    container.push_back(3);
    container.push_back(5);
    container.push_back(2);
    container.push_back(4);
    container.push_back(6);

    BOOST_CHECK(3 == InversionsCounter(container));
}

BOOST_AUTO_TEST_SUITE_END()
