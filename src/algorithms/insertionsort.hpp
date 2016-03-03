#ifndef INSERTIONSORT_HPP_
#define INSERTIONSORT_HPP_

// Insertion Sort Algorithm
// Simple, stable algorithm with in-place sorting
// http://en.wikipedia.org/wiki/Insertion_sort
// Best case performance: O(n) - when array is already sorted
// Worst case performance: O(n^2) - when array sorted in reverse order
// Worst Case Auxiliary Space Complexity: О(n)
// @input:
// - container - object of container type
// @output:
// - T - sorted container
template<typename T>
T InsertionSort(const T& container)
{
    if (container.size() <= 1)
    {
        return container;
    }

    T array = container;
    for (size_t i = 0; i < array.size(); ++i)
    {
        size_t j = i;
        while (0 < j && array[j] < array[j - 1])
        {
            std::swap(array[j], array[j - 1]);
            --j;
        }
    }

    return array;
}

#endif /* INSERTIONSORT_HPP_ */
