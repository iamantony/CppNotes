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
    if (end < start) {
        return false;
    }
    else if (end == start) {
        if (container[start] == value) {
            resultIndex = start;
            return true;
        }

        return false;
    }

    size_t middle = (start + end) / 2;
    if (container[middle] < value) {
        size_t newStart = std::min(end, middle + 1);
        return BinarySearch(container, newStart, end, value, resultIndex);
    }
    else if (value < container[middle]) {
        size_t newEnd = middle == 0 ? middle : middle - 1;
        return BinarySearch(container, start, newEnd, value, resultIndex);
    }

    resultIndex = middle;
    return true;
}

#endif /* BINARYSEARCH_HPP_ */
