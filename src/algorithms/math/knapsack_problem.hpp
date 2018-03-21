#ifndef KNAPSACK_PROBLEM_HPP
#define KNAPSACK_PROBLEM_HPP

// Knapsack problem
// Given a set of items, each with a weight and a value, determine the number
// of each item to include in a collection so that the total weight is less
// than or equal to a given limit and the total value is as large as possible.

#include <map>
#include <unordered_map>
#include <algorithm>

namespace Knapsack {

class Solution {
public:
    // Items in map: value, weight
    double knapsakProblem(const int& maxWeight,
                          const std::unordered_map<int, int>& items) {
        // Calc for each item its' value per weight param
        std::map<double, std::pair<int, int>> vpwItems;
        for (auto item : items) {
            double valuePerWeight = static_cast<double>(item.first) /
                    static_cast<double>(item.second);
            vpwItems.insert( {valuePerWeight, {item.first, item.second}} );
        }

        double resultValue = 0;
        int currentWeight = 0;

        // Start iteration from item with highest value per weight param (
        // in sorted map it is last element)
        for (auto item = vpwItems.rbegin(); item != vpwItems.rend(); ++item) {
            if (currentWeight >= maxWeight) {
                break;
            }

            double vpwOfItem = item->first;
            int itemWeight = item->second.second;

            int availableWeight = std::min(itemWeight,
                                           maxWeight - currentWeight);

            resultValue += vpwOfItem * availableWeight;
            currentWeight += availableWeight;
        }

        return resultValue;
    }
};

}

#endif // KNAPSACK_PROBLEM_HPP

