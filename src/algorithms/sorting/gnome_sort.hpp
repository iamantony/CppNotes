#ifndef GNOMESORT_HPP_
#define GNOMESORT_HPP_

// Gnome Sort Algorithm
// Simple and slow algorithm
// http://en.wikipedia.org/wiki/Gnome_sort
// Best case performance: O(n^2)
// Worst case performance: O(n)
// Worst Case Auxiliary Space Complexity: O(1)

namespace Algo::Sorting {
template<typename T>
class GnomeSort {
public:
    static void Sort(T& container) {
        if (container.size() < 2) {
            return;
        }

        size_t pos = 1;
        while (pos < container.size()) {
            if (container[pos - 1] <= container[pos]) {
                ++pos;
            }
            else {
                std::swap(container[pos - 1], container[pos]);
                if (pos > 1) {
                    --pos;
                }
            }
        }
    }
};
}

#endif /* GNOMESORT_HPP_ */
