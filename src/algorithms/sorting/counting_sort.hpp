#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

// Counting sort is a sorting technique based on keys between a specific range.
// It works by counting the number of objects having distinct key values
// (kind of hashing). Then doing some arithmetic to calculate the position
// of each object in the output sequence.
// Time complexity: O(n)
// Space complexity: O(n + M) where M is the max value of elements type

#include <vector>
#include <algorithm>
#include <limits>

namespace CS {

class Solution {
public:
    static std::vector<unsigned char> CountingSort(
                            const std::vector<unsigned char>& v) {
        if (v.size() < 2) {
            return v;
        }

        // Create array where we will count how many times we encounter some
        // value. Size of the array - number of all possible values that we
        // could find in array.s
        std::vector<size_t> countVector(
                    std::numeric_limits<unsigned char>::max() + 1, 0);

        // Count how many times each value appears in array
        for (auto value : v) {
            ++countVector[value];
        }

        // Modify the count array such that each element at each index
        // stores the sum of previous counts.
        for (size_t i = 1; i < countVector.size(); ++i) {
            countVector[i] += countVector[i - 1];
        }

        // Create result sorted array
        std::vector<unsigned char> result(v.size(), 0);
        for (size_t i = 0; i < v.size(); ++i) {
            // Find out position for value at v[i]. It will be the max current
            // position for such value
            size_t position = countVector[v[i]] - 1;

            // Put value in its position
            result[position] = v[i];

            // Decrease position for the next element of v with the same value
            --countVector[v[i]];
        }

        return result;
    }
};

}

#endif // COUNTING_SORT_HPP

