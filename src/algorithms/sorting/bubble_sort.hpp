#ifndef BUBBLESORT_HPP_
#define BUBBLESORT_HPP_

#include <algorithm>

// Bubble Sort Algorithm
// Simple and slow algorithm
// http://en.wikipedia.org/wiki/Bubble_sort
// Best case performance: O(n^2)
// Worst case performance: O(n^2)
// Worst Case Auxiliary Space Complexity: O(1)
// @input:
// - container - object of container type
// @output:
// - T - sorted container
template<typename T>
T BubbleSort(const T& container)
{
    if (container.size() <= 1)
    {
        return container;
    }

    T array = container;
    for (size_t i = 0; i < array.size() - 1; ++i)
    {
        for(size_t j = 0; j < array.size() -i -1; ++j)
        {
            if (array[j + 1] < array[j])
            {
                std::swap(array[j + 1], array[j]);
            }
        }
    }

    return array;
}

#endif /* BUBBLESORT_HPP_ */
