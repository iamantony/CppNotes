#ifndef TEST_CONTAINER_WITH_MOST_WATER_HPP
#define TEST_CONTAINER_WITH_MOST_WATER_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/array/container_with_most_water.hpp"

BOOST_AUTO_TEST_CASE(test_cwmw_invalid_container)
{
    BOOST_CHECK(0 == Algo::DS::Array::ContainerWithMostWater::Search({}));
    BOOST_CHECK(0 == Algo::DS::Array::ContainerWithMostWater::Search({1}));
}

BOOST_AUTO_TEST_CASE(test_cwmw_empty_container)
{
    BOOST_CHECK(0 == Algo::DS::Array::ContainerWithMostWater::Search({0, 1}));
    BOOST_CHECK(0 == Algo::DS::Array::ContainerWithMostWater::Search({0, 1, 0}));
}

BOOST_AUTO_TEST_CASE(test_cwmw_valid_container)
{
    BOOST_CHECK(1 == Algo::DS::Array::ContainerWithMostWater::Search({0, 1, 2}));
    BOOST_CHECK(1 == Algo::DS::Array::ContainerWithMostWater::Search({2, 1, 0}));
    BOOST_CHECK(2 == Algo::DS::Array::ContainerWithMostWater::Search({1, 1, 2}));
    BOOST_CHECK(2 == Algo::DS::Array::ContainerWithMostWater::Search({2, 1, 1}));
    BOOST_CHECK(49 ==
            Algo::DS::Array::ContainerWithMostWater::Search({1,8,6,2,5,4,8,3,7}));
}

#endif // TEST_CONTAINER_WITH_MOST_WATER_HPP
