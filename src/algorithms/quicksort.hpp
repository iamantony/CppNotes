#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <limits>

template<typename T>
class QuickSortAlg
{
public:
    static void Sort(T& input, const size_t& start, const size_t& end)
    {
        if((end - start) < 1)
        {
            return;
        }

        size_t pivotIndex = (start + end) / 2;
        auto pivotValue = input[pivotIndex];
        size_t i = start, j = end;
        do
        {
            while(input[i] < pivotValue)
            {
                ++i;
            }

            while(pivotValue < input[j])
            {
                --j;
            }

            if (i <= j)
            {
                std::swap(input[i], input[j]);
                if (i < std::numeric_limits<size_t>::max())
                {
                    ++i;
                }

                if (std::numeric_limits<size_t>::min() < j)
                {
                    --j;
                }
            }
        }
        while(i <= j);

        if (start < j)
        {
            Sort(input, start, j);
        }

        if ( i < end )
        {
            Sort(input, i, end);
        }
    }
};

// Quick Sort Algorithm
// Efficient, general-purpose, comparison-based sorting algorithm.
// https://en.wikipedia.org/wiki/Quicksort
// Best case performance: O(n log n) typical, O(n) natural variant
// Worst case performance: O(n^2)
// Worst Case Auxiliary Space Complexity: О(n)
// @input:
// - container - object of container type
// @output:
// - T - sorted container
template<typename T>
T QuickSort(const T& container)
{
    if (container.size() < 2)
    {
        return container;
    }

    T result = container;
    QuickSortAlg<T>::Sort(result, 0, result.size() - 1);
    return result;
}

#endif /* QUICKSORT_HPP_ */
