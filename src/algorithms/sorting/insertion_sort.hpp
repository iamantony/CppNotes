#ifndef INSERTIONSORT_HPP_
#define INSERTIONSORT_HPP_

// Insertion Sort Algorithm
// Simple, stable algorithm with in-place sorting
// http://en.wikipedia.org/wiki/Insertion_sort
// Best case performance: O(n) - when array is already sorted
// Worst case performance: O(n^2) - when array sorted in reverse order
// Worst Case Auxiliary Space Complexity: О(n)

namespace IS {

template<typename T>
void InsertionSort(T& container)
{
    if (container.size() < 2) {
        return;
    }

    for (size_t i = 0; i < container.size(); ++i)
    {
        size_t j = i;
        while (0 < j && container[j] < container[j - 1])
        {
            std::swap(container[j], container[j - 1]);
            --j;
        }
    }
}

}

#endif /* INSERTIONSORT_HPP_ */
