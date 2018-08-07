#ifndef SWAP_MIN_AND_MAX_HPP
#define SWAP_MIN_AND_MAX_HPP

/*
Given array of N numbers. Swap min and max elements
*/

#include <vector>

namespace Algo::DS::Array {

class SwapMinMax {
public:
    static void Swap(std::vector<int>& v) {
        if (v.size() < 2) {
            return;
        }

        size_t minPos = 0, maxPos = 0;
        for (size_t i = 0; i < v.size(); ++i) {
            minPos = v[i] < v[minPos] ? i : minPos;
            maxPos = v[maxPos] < v[i] ? i : maxPos;
        }

        std::swap(v[minPos], v[maxPos]);
    }
};

}

#endif // SWAP_MIN_AND_MAX_HPP
