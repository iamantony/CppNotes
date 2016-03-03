#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

template<typename T>
class MergeSortAlg
{
public:
    // start is inclusive; end is exclusive
    static void SplitMerge(const T& input,
            const size_t& start,
            const size_t& end,
            T& output)
    {
        if(end - start < 2)
        {
            return;
        }

        // recursively split runs into two halves until run size == 1,
        // then merge them and return back up the call chain
        size_t middle = (end + start) / 2;
        SplitMerge(input, start, middle, output);  // split / merge left  half
        SplitMerge(input, middle, end, output);  // split / merge right half
        Merge(input, start, middle, end, output);  // merge the two half runs
    }

private:
    //  Left half is A[iBegin :iMiddle-1].
    // Right half is A[iMiddle:iEnd-1   ].
    static void Merge(const T& input,
            const size_t& start,
            const size_t& middle,
            const size_t& end,
            T& output)
    {
        // While there are elements in the left or right runs...
        for (size_t k = start, i = start, j = middle; k < end; ++k)
        {
            // If left run head exists and is <= existing right run head.
            if (i < middle && (j >= end || input[i] <= input[j]))
            {
                output[k] = input[i];
                ++i;
            }
            else
            {
                output[k] = input[j];
                ++j;
            }
        }
    }
};

// Merge Sort Algorithm
// Efficient, general-purpose, comparison-based sorting algorithm.
// https://en.wikipedia.org/wiki/Merge_sort
// Best case performance: O(n log n) typical, O(n) natural variant
// Worst case performance: O(n log n)
// Worst Case Auxiliary Space Complexity: О(n)
// @input:
// - container - object of container type
// @output:
// - T - sorted container
template<typename T>
T MergeSort(const T& container)
{
    if (container.size() <= 1)
    {
        return container;
    }

    T array = container;

    MergeSortAlg<T>::SplitMerge(container, 0, container.size(), array);
    return array;
}

#endif /* INSERTIONSORT_HPP_ */
