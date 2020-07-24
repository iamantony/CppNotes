#include <boost/test/unit_test.hpp>
#include "algorithms/greedy/complete_road_cycle_with_gas_stations.hpp"

BOOST_AUTO_TEST_SUITE(TestCompleteRoadCycleWithGasStations)

    BOOST_AUTO_TEST_CASE(test_get_start_gas_station)
    {
        {
            const std::vector<int> gas;
            const std::vector<int> cost;
            const int expected = -1;
            BOOST_CHECK(
                expected == Algo::Greedy::CompleteRoadCycle::get_start_gas_station(gas, cost));
        }

        {
            const std::vector<int> gas = {1};
            const std::vector<int> cost = {5};
            const int expected = -1;
            BOOST_CHECK(
                expected == Algo::Greedy::CompleteRoadCycle::get_start_gas_station(gas, cost));
        }

        {
            const std::vector<int> gas = {2};
            const std::vector<int> cost = {2};
            const int expected = 0;
            BOOST_CHECK(
                expected == Algo::Greedy::CompleteRoadCycle::get_start_gas_station(gas, cost));
        }

        {
            const std::vector<int> gas = {2, 3};
            const std::vector<int> cost = {2, 5};
            const int expected = -1;
            BOOST_CHECK(
                expected == Algo::Greedy::CompleteRoadCycle::get_start_gas_station(gas, cost));
        }

        {
            const std::vector<int> gas = {1,2,3,4,5};
            const std::vector<int> cost = {3,4,5,1,2};
            const int expected = 3;
            BOOST_CHECK(
                expected == Algo::Greedy::CompleteRoadCycle::get_start_gas_station(gas, cost));
        }
    }

BOOST_AUTO_TEST_SUITE_END()

