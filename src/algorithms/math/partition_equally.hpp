#ifndef PARTITION_EQUALLY_HPP
#define PARTITION_EQUALLY_HPP

/*
https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
Given an integer array of N elements, the task is to divide this array into
K non-empty subsets such that the sum of elements in every subset is same.
All elements of this array should be part of exactly one partition.
*/

#include <vector>

namespace Algo::Math {
class PartitionEqually {
    // elements       - given input elements
    // partitionSum   - vector to store sum of each subset of the array
    // elementTaken   - boolean vecotr to check whether element
    //                  was taken into some partition or not
    // partitionIndex - current partition index
    // limitIndex     - lastIdx from where array element should
    //                  be taken
    static bool isKPartitionPossibleRec(
            const std::vector<uint32_t>& elements,
            std::vector<uint32_t>& partitionSum,
            std::vector<bool>& elementTaken,
            const uint32_t targetSum,
            const size_t partitionIndex,
            int limitIndex)
    {
        if (partitionSum[partitionIndex] == targetSum)
        {
            /*  current index (K - 2) represents (K - 1) subsets of equal
                sum last partition will already remain with sum 'subset'*/
            if (partitionIndex == partitionSum.size() - 2) { return true; }

            return isKPartitionPossibleRec(
                elements, partitionSum, elementTaken, targetSum,
                partitionIndex + 1, static_cast<int>(elements.size() - 1));
        }

        //  start from limitIdx and include elements into current partition
        for (auto i = limitIndex; i >= 0; i--)
        {
            auto ii = static_cast<size_t>(i);
            if (elementTaken[ii]) { continue; }

            auto tmpSum = partitionSum[partitionIndex] + elements[ii];
            if (tmpSum <= targetSum) {
                elementTaken[ii] = true;
                partitionSum[partitionIndex] += elements[ii];
                bool possible = isKPartitionPossibleRec(
                    elements, partitionSum, elementTaken, targetSum,
                    partitionIndex, i - 1);

                // after recursive call unmark the element and remove from
                // subsetition sum
                elementTaken[ii] = false;
                partitionSum[partitionIndex] -= elements[ii];

                if (possible) { return true; }
            }
        }

        return false;
    }

public:
    static bool CanPartition(
        const std::vector<uint32_t>& elements, const uint32_t numOfPartitions)
    {
         if (numOfPartitions == 1) { return true; }
         if (elements.size() < numOfPartitions) { return false; }

         uint32_t elementsSum = 0;
         for (const auto& e : elements) { elementsSum += e; }

         if (elementsSum % numOfPartitions != 0) { return false; }

         const uint32_t targetSum = elementsSum / numOfPartitions;
         std::vector<uint32_t> partitionSum(numOfPartitions, 0);
         std::vector<bool> elementTaken(elements.size(), false);

         // initialize first partitionSum sum as last element of
         // array and mark that as taken
         partitionSum[0] = *(elements.rbegin());
         elementTaken[elements.size() - 1] = true;

         //  call recursive method to check K-substitution condition
         return isKPartitionPossibleRec(
            elements, partitionSum, elementTaken, targetSum,
            0, static_cast<int>(elements.size() - 1));
    }
};
}

#endif // PARTITION_EQUALLY_HPP
