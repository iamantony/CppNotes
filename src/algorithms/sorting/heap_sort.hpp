#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>

#include "types/ds/heap.hpp"

namespace Algorithms { namespace Sorting { namespace HS {

template <typename T>
class Solution {
public:
    static void HeapSort(std::vector<T>& data) {
        if (data.size() < 2) {
            return;
        }

        // Create max-heap from input data
        Types::DS::Heap<T> heap(data);
        for (size_t i = data.size() - 1; i > 0; --i) {
            // Max element is first, swap it with last element (max element
            // now in its final position) and decrease size of a heap by 1.
            heap.swap(0, i);
            heap.resize(heap.size() - 1);

            // Make sure that heap stays valid - perform heapify() on first
            // element
            heap.heapify(0);
        }

        data = heap.exportData();
    }
};

} } }

#endif // HEAP_SORT_HPP

