#ifndef INTERPOLATION_SEARCH_HPP
#define INTERPOLATION_SEARCH_HPP

// http://www.geeksforgeeks.org/interpolation-search/
// https://en.wikipedia.org/wiki/Interpolation_search

// Given a sorted array of n uniformly distributed values arr[], write a
// function to search for a particular element x in the array.

// Linear Search finds the element in O(n) time, Jump Search takes O(√ n) time
// and Binary Search take O(Log n) time.
// The Interpolation Search is an improvement over Binary Search for instances,
// where the values in a sorted array are uniformly distributed. Binary Search
// always goes to middle element to check. On the other hand interpolation
// search may go to different locations according the value of key being
// searched. For example if the value of key is closer to the last element,
// interpolation search is likely to start search toward the end side.

// Unlike the binary search which guarantees a halving of the interval's size
// with each stage, a misled interpolation may reduce/increase the mid index by
// only one, thus resulting in a worst-case efficiency of O(n).

// To find the position to be searched, it uses following formula.
// The idea of formula is to return higher value of pos
// when element to be searched is closer to arr[hi]. And
// smaller value when closer to arr[lo]:

// pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

// Where:
// arr[] ==> Array where elements need to be searched
// x     ==> Element to be searched
// lo    ==> Starting index in arr[]
// hi    ==> Ending index in arr[]

namespace InterpolationSearch {

class Solution {
public:
    template<typename C, typename V>
    bool Search(const C& container,
                const size_t& size,
                const V& value,
                size_t& resultIndex) {
        if (size <= 0) {
            return false;
        }

        size_t low = 0;
        size_t high = size - 1;
        while (container[high] != container[low] &&
                    value >= container[low] &&
                    value <= container[high]) {
            size_t mid = low +
                  (static_cast<size_t>(value - container[low]) * (high - low) /
                   static_cast<size_t>(container[high] - container[low]));

            if (container[mid] < value) {
                low = mid + 1;
            }
            else if (value < container[mid]) {
                high = mid - 1;
            }
            else {
                resultIndex = mid;
                return true;
            }
        }

        if (value == container[low]) {
            resultIndex = low;
            return true;
        }

        return false;
    }
};

}

#endif // INTERPOLATION_SEARCH_HPP

