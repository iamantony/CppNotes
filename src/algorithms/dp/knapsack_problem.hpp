#ifndef KNAPSACK_PROBLEM_HPP
#define KNAPSACK_PROBLEM_HPP

// Knapsack problem
// Given a set of items, each with a weight and a value, determine the number
// of each item to include in a collection so that the total weight is less
// than or equal to a given limit and the total value is as large as possible.

#include <map>
#include <vector>
#include <algorithm>

namespace Algo::DP {
    class Knapsack {
    public:
        // Greedy algorithm for fractional Knapsack problem, that returns result
        // value of items in knapsack
        // items: vector of pairs of { value, weight }
        static double FillGreedy(
                const uint32_t& maxWeight,
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

        // Dynamic Programming algorithm for a Knapsack problem without repetitions
        // Function return result weight of the items in the knapsack
        // items: vector of pairs of { value, weight }
        static uint32_t FillDP(const uint32_t& maxWeight,
                    const std::vector<std::pair<uint32_t, uint32_t>>& items) {
            if (maxWeight == 0 || items.empty()) { return 0; }

            const auto rowsNum = items.size() + 1;
            const auto colsNum = maxWeight + 1;
            std::vector<uint32_t> rowsVec(colsNum, 0);
            std::vector<std::vector<uint32_t>> valueTable(rowsNum, rowsVec);
            for (size_t i = 1; i < rowsNum; ++i) {
                for (uint32_t w = 1; w < colsNum; ++w) {
                    valueTable[i][w] = valueTable[i - 1][w];

                    const auto curItemIndex = i - 1;
                    const auto& itemValue = items[curItemIndex].first;
                    const auto& itemWeight = items[curItemIndex].second;
                    if (itemWeight > w) { continue; }

                    const auto value = valueTable[i - 1][w - itemWeight] + itemValue;
                    if (value > valueTable[i][w]) { valueTable[i][w] = value; }
                }
            }

            return valueTable[rowsNum - 1][colsNum - 1];
        }
    };
}

#endif // KNAPSACK_PROBLEM_HPP
