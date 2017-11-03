#ifndef BINARYSEARCH_HPP_
#define BINARYSEARCH_HPP_

#include <limits>

template<typename C, typename V>
bool BinarySearch(const C& container,
        const size_t& start,
        const size_t& end,
        const V& value,
        size_t& resultIndex)
{
    if (end < start)
    {
        return false;
    }

    size_t middle = (start + end) / 2;
    if (container[middle] < value)
    {
        if (middle == std::numeric_limits<size_t>::max())
        {
            return false;
        }

        return BinarySearch(container, middle + 1, end, value, resultIndex);
    }
    else if (value < container[middle])
    {
        if (middle == std::numeric_limits<size_t>::min())
        {
            return false;
        }

        return BinarySearch(container, start, middle - 1, value, resultIndex);
    }

    resultIndex = middle;
    return true;
}

#endif /* BINARYSEARCH_HPP_ */
