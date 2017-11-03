#ifndef GNOMESORT_HPP_
#define GNOMESORT_HPP_

// Gnome Sort Algorithm
// Simple and slow algorithm
// http://en.wikipedia.org/wiki/Gnome_sort
// Best case performance: O(n^2)
// Worst case performance: O(n)
// Worst Case Auxiliary Space Complexity: O(1)
// @input:
// - container - object of container type
// @output:
// - T - sorted container
template<typename T>
T GnomeSort(const T& container)
{
    if (container.size() <= 1)
    {
        return container;
    }

    T array = container;
    size_t pos = 1;
    while (pos < array.size())
    {
        if (array[pos - 1] <= array[pos])
        {
            ++pos;
        }
        else
        {
            std::swap(array[pos - 1], array[pos]);
            if (pos > 1)
            {
                --pos;
            }
        }
    }

    return array;
}

#endif /* GNOMESORT_HPP_ */
