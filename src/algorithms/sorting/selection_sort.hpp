#ifndef SELECTIONSORT_HPP_
#define SELECTIONSORT_HPP_

// Selection Sort Algorithm
// Simple, stable algorithm with in-place sorting
// http://en.wikipedia.org/wiki/Selection_sort
// Best case performance: O(n^2)
// Worst case performance: O(n^2)
// Worst Case Auxiliary Space Complexity: О(n) total, O(1) auxiliary

namespace SSort {

class Solution {
public:
    template<typename T>
    void SelectionSort(T& container) {
        for (size_t i = 0; i < container.size(); ++i)
        {
            size_t minElemPos = i;
            for (size_t j = i + 1; j < container.size(); ++j) {
                if (container[j] < container[minElemPos]) {
                    minElemPos = j;
                }
            }

            if (minElemPos != i) {
                std::swap(container[i], container[minElemPos]);
            }
        }
    }
};

}

#endif /* SELECTIONSORT_HPP_ */
