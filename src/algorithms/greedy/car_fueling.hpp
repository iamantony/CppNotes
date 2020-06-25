#ifndef CAR_FUELING_HPP
#define CAR_FUELING_HPP

/*
You are going to travel to another city that is located d miles away from your
home city. Your can can travel at most m miles on a full tank and you start
with a full tank. Along your way, there are gas stations at distances
stop1 , stop2 , . . . , stopN from your home city. What is the minimum number
of refills needed?
*/

#include <vector>

namespace Algo::Greedy {
    class CarFueling
    {
    public:
        static int MinRefills(
                const uint32_t& city_distance,
                const uint32_t& tank_distance,
                std::vector<uint32_t> stops_distances)
        {
            if (tank_distance == 0) { return -1; }
            if (city_distance <= tank_distance) { return 0; }
            if (stops_distances.empty()) { return -1; }

            stops_distances.push_back(city_distance);

            int refills_num = 0;
            uint32_t left_dist = tank_distance;
            int last_refill_on = -1;
            for (size_t i = 0; i < stops_distances.size(); ) {
                const auto station_dist = (i == 0) ?
                    stops_distances[i] :
                    stops_distances[i] - stops_distances[i - 1];

                if (left_dist >= station_dist) {
                    left_dist -= station_dist;
                    ++i;
                }
                else {
                    if (last_refill_on == static_cast<int>(i) - 1) { return -1; }
                    ++refills_num;
                    last_refill_on = static_cast<int>(i) - 1;
                    left_dist = tank_distance;
                }
            }

            return refills_num;
        }
    };
}

#endif // CAR_FUELING_HPP
