#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

// Merge Sort Algorithm
// Efficient, general-purpose, comparison-based sorting algorithm.
// https://en.wikipedia.org/wiki/Merge_sort
// https://www.geeksforgeeks.org/merge-sort/
// Best case performance: O(n log n) typical, O(n) natural variant
// Worst case performance: O(n log n)
// Worst Case Auxiliary Space Complexity: О(n)

#include <iterator>

namespace MS {

template<typename T>
class Solution {
public:
    static void MergeSort(T& container) {
        if (container.size() < 2) {
            return;
        }

        MergeSortImpl(container, 0, container.size() - 1);
    }

private:
    static void MergeSortImpl(T& container,
                              const size_t& start, const size_t& end)
    {
        if(start >= end) {
            return;
        }

        size_t middle = start + (end - start) / 2;
        MergeSortImpl(container, start, middle);
        MergeSortImpl(container, middle + 1, end);

        return Merge(container, start, middle, end);
    }

    static void Merge(T& container, const size_t& start,
                      const size_t& middle, const size_t& end)
    {
        if (start > middle || middle > end) {
            return;
        }

        // Create two containers that would contain values from [start, middle]
        // and [middle + 1, end]
        T leftContainer, rightContainer;
        {
            auto createIterator = [](const T& array, const size_t& position) {
                auto iter = array.begin();
                std::advance(iter, position);
                return iter;
            };

            auto startIter = createIterator(container, start);
            auto middleIter = createIterator(container, middle + 1);
            auto endIter = createIterator(container, end + 1);

            std::copy(startIter, middleIter, back_inserter(leftContainer));
            std::copy(middleIter, endIter, back_inserter(rightContainer));
        }

        // Merge two containers
        for (size_t c = start, lc = 0, rc = 0; c <= end; ++c) {
            if (lc < leftContainer.size() &&
                        (rightContainer.size() <= rc ||
                         leftContainer[lc] <= rightContainer[rc]))
            {
                container[c] = leftContainer[lc];
                ++lc;
            }
            else {
                container[c] = rightContainer[rc];
                ++rc;
            }
        }
    }
};

}

#endif /* MERGESORT_HPP_ */
