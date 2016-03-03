#ifndef SELECTIONSORT_HPP_
#define SELECTIONSORT_HPP_

// Selection Sort Algorithm
// Simple, stable algorithm with in-place sorting
// http://en.wikipedia.org/wiki/Selection_sort
// Best case performance: O(n^2)
// Worst case performance: O(n^2)
// Worst Case Auxiliary Space Complexity: О(n) total, O(1) auxiliary
// @input:
// - container - object of container type
// @output:
// - T - sorted container
template<typename T>
T SelectionSort(const T& container)
{
    if (container.size() <= 1)
    {
        return container;
    }

    T array = container;
    for (size_t i = 0; i < array.size() -1; ++i)
    {
        size_t minElemPos = i;
        for (size_t j = i + 1; j < array.size(); ++j)
        {
            if (array[j] < array[minElemPos])
            {
                minElemPos = j;
            }
        }

        if (minElemPos != i)
        {
            std::swap(array[i], array[minElemPos]);
        }
    }

    return array;
}

#endif /* SELECTIONSORT_HPP_ */
