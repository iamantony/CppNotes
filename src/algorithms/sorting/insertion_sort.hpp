#ifndef INSERTIONSORT_HPP_
#define INSERTIONSORT_HPP_

// Insertion Sort Algorithm
// Simple, stable algorithm with in-place sorting
// http://en.wikipedia.org/wiki/Insertion_sort
// Best case performance: O(n) - when array is already sorted
// Worst case performance: O(n^2) - when array sorted in reverse order
// Worst Case Auxiliary Space Complexity: О(n)

/*
 * Difference between Insertion sort and Gnome sort:
 * IS and GS are equal when they move elements down to the beginning of the
 * array. Both of them compare neighbor elements and swap them if they are
 * not in right order.
 * But when we IS finish its' 'move-down-element' procedure, it continues
 * at point (index) where it started this procedure. That is why we use
 * two iterators - i and j.
 * GS after 'move-down-element' procedure starts moving up from index where
 * procedure had finished. So that is why we use only one iterator.
 */

namespace IS {

template<typename T>
void InsertionSort(T& container) {
    if (container.size() < 2) {
        return;
    }

    for (size_t i = 0; i < container.size(); ++i) {
        size_t j = i;
        while (j > 0 && container[j] < container[j - 1]) {
            std::swap(container[j], container[j - 1]);
            --j;
        }
    }
}

}

#endif /* INSERTIONSORT_HPP_ */
