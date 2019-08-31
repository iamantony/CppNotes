#ifndef KNAPSACK_PROBLEM_HPP
#define KNAPSACK_PROBLEM_HPP

// Knapsack problem
// Given a set of items, each with a weight and a value, determine the number
// of each item to include in a collection so that the total weight is less
// than or equal to a given limit and the total value is as large as possible.

#include <map>
#include <vector>
#include <algorithm>

namespace Algo::Math {
class Knapsack {
public:
    // Items in map: value, weight
    static double Fill(const uint32_t& maxWeight,
                       const std::vector<std::pair<uint32_t, uint32_t>>& items) {
        // Calc for each item its' value per weight param
        std::multimap<double, std::pair<uint32_t, uint32_t>> vpwItems;
        for (auto item : items) {
            const auto value = static_cast<double>(item.first);
            const auto weight = static_cast<double>(item.second);
            const auto valuePerWeight = value / weight;
            vpwItems.insert( {valuePerWeight, item} );
        }

        double resultValue = 0;
        uint32_t currentWeight = 0;

        // Start iteration from item with highest value per weight param (
        // in sorted map it is last element)
        for (auto item = vpwItems.rbegin(); item != vpwItems.rend(); ++item) {
            if (currentWeight >= maxWeight) {
                break;
            }

            double vpwOfItem = item->first;
            uint32_t itemWeight = item->second.second;

            uint32_t availableWeight =
                std::min(itemWeight, maxWeight - currentWeight);

            resultValue += vpwOfItem * availableWeight;
            currentWeight += availableWeight;
        }

        return resultValue;
    }
};
}

#endif // KNAPSACK_PROBLEM_HPP
