#ifndef TEST_CAR_FUELING_HPP
#define TEST_CAR_FUELING_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/car_fueling.hpp"

BOOST_AUTO_TEST_CASE(test_car_fueling_test)
{
    {
        const uint32_t city_dist = 0;
        const uint32_t tank_dist = 100;
        std::vector<uint32_t> stops = { 50 };
        const int expected_refills = 0;
        const auto refills =
                Algo::Math::CarFueling::MinRefills(city_dist, tank_dist, stops);
        BOOST_CHECK(refills == expected_refills);
    }

    {
        const uint32_t city_dist = 10;
        const uint32_t tank_dist = 0;
        std::vector<uint32_t> stops = { 50 };
        const int expected_refills = -1;
        const auto refills =
                Algo::Math::CarFueling::MinRefills(city_dist, tank_dist, stops);
        BOOST_CHECK(refills == expected_refills);
    }

    {
        const uint32_t city_dist = 10;
        const uint32_t tank_dist = 20;
        std::vector<uint32_t> stops = { };
        const int expected_refills = 0;
        const auto refills =
                Algo::Math::CarFueling::MinRefills(city_dist, tank_dist, stops);
        BOOST_CHECK(refills == expected_refills);
    }

    {
        const uint32_t city_dist = 950;
        const uint32_t tank_dist = 400;
        std::vector<uint32_t> stops = { 200, 375, 550, 750 };
        const int expected_refills = 2;
        const auto refills =
                Algo::Math::CarFueling::MinRefills(city_dist, tank_dist, stops);
        BOOST_CHECK(refills == expected_refills);
    }

    {
        const uint32_t city_dist = 10;
        const uint32_t tank_dist = 3;
        std::vector<uint32_t> stops = { 1, 2, 5, 9 };
        const int expected_refills = -1;
        const auto refills =
                Algo::Math::CarFueling::MinRefills(city_dist, tank_dist, stops);
        BOOST_CHECK(refills == expected_refills);
    }

    {
        const uint32_t city_dist = 10;
        const uint32_t tank_dist = 3;
        std::vector<uint32_t> stops = { 4, 5, 9 };
        const int expected_refills = -1;
        const auto refills =
                Algo::Math::CarFueling::MinRefills(city_dist, tank_dist, stops);
        BOOST_CHECK(refills == expected_refills);
    }

    {
        const uint32_t city_dist = 15;
        const uint32_t tank_dist = 3;
        std::vector<uint32_t> stops = { 2, 5, 8 };
        const int expected_refills = -1;
        const auto refills =
                Algo::Math::CarFueling::MinRefills(city_dist, tank_dist, stops);
        BOOST_CHECK(refills == expected_refills);
    }
}

#endif // TEST_CAR_FUELING_HPP
