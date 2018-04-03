#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

// Merge Sort Algorithm
// Efficient, general-purpose, comparison-based sorting algorithm.
// https://en.wikipedia.org/wiki/Merge_sort
// Best case performance: O(n log n) typical, O(n) natural variant
// Worst case performance: O(n log n)
// Worst Case Auxiliary Space Complexity: О(n)

#include <iterator>

namespace MS {

template<typename T>
class Solution
{
public:
    static T MergeSort(const T& container)
    {
        return SortImpl(container);
    }

private:
    static T SortImpl(const T& input)
    {
        if(input.size() < 2)
        {
            return input;
        }

        // Find middle element
        size_t middle = input.size()/2;
        typename T::const_iterator middleIter(input.cbegin());
        std::advance(middleIter, middle);

        // Create two containers that contains halfs of the original container
        T first(input.begin(), middleIter);
        T second(middleIter, input.end());

        first = SortImpl(first);
        second = SortImpl(second);
        return Merge(first, second);
    }

    static T Merge(const T& first, const T& second)
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

        // Just setup size of result container as sum of sizes of merging
        // containers
        std::copy(first.begin(), first.end(), back_inserter(result));
        std::copy(second.begin(), second.end(), back_inserter(result));

        // Merge two containers
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

}

#endif /* MERGESORT_HPP_ */
