#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

#include <vector>
#include <iterator>

template<typename T>
class MergeSortAlg
{
public:
    // start is inclusive; end is exclusive
    static T Sort(const T& input)
    {
        if(input.size() < 2)
        {
            return input;
        }

        size_t middle = input.size()/2;
        typename T::const_iterator middleIter(input.cbegin());
        std::advance(middleIter, middle);

        T first(input.begin(), middleIter);
        T second(middleIter, input.end());

        first = Sort(first);
        second = Sort(second);
        return Merge(first, second);
    }

private:
    static T Merge(const T& first,
            const T& second)
    {
        if (first.empty() && second.empty())
        {
            return T();
        }
        else if (first.empty() && false == second.empty())
        {
            return second;
        }
        else if (false == first.empty() && second.empty())
        {
            return first;
        }

        T result;
        std::copy(first.begin(), first.end(), back_inserter(result));
        std::copy(second.begin(), second.end(), back_inserter(result));
        for (size_t k = 0, i = 0, j = 0; k < result.size(); ++k)
        {
            if (i < first.size() && (second.size() <= j ||
                                     first[i] <= second[j]))
            {
                result[k] = first[i];
                ++i;
            }
            else
            {
                result[k] = second[j];
                ++j;
            }
        }

        return result;
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

    return MergeSortAlg<T>::Sort(container);
}

#endif /* INSERTIONSORT_HPP_ */
