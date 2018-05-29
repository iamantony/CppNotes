#include <map>
#include <limits>

#include <iostream>

/*
interval_map<K,V> is a data structure that efficiently associates intervals
of keys of type K with values of type V. Your task is to implement the assign
member function of this data structure, which is outlined below.

interval_map<K, V> is implemented on top of std::map. Each key-value-pair (k,v)
in the std::map means that the value v is associated with the interval from
k (including) to the next key (excluding) in the std::map.

Example: the std::map (0,'A'), (3,'B'), (5,'A') represents the mapping:
0 -> 'A'
1 -> 'A'
2 -> 'A'
3 -> 'B'
4 -> 'B'
5 -> 'A'
6 -> 'A'
7 -> 'A'
... all the way to numeric_limits<int>::max()

The representation in the std::map must be canonical, that is, consecutive map
entries must not have the same value: ..., (0,'A'), (3,'A'), ... is not allowed.
Initially, the whole range of K is associated with a given initial value,
passed to the constructor of the interval_map<K,V> data structure.

Key type K:
- besides being copyable and assignable, is less-than comparable via operator<
- is bounded below, with the lowest value being std::numeric_limits<K>::lowest()
- does not implement any other operations, in particular no equality comparison
or arithmetic operators

Value type V:
- besides being copyable and assignable, is equality-comparable via operator==
- does not implement any other operations

Correctness (compile time): You must adhere to the specification of the key and
value type given above.

Correctness (run time): Your program should produce a working interval_map with
the behavior described above. In particular, pay attention to the validity of
iterators. It is illegal to dereference end iterators. Consider using a
checking STL implementation such as the one shipped with Visual C++ or GCC.

Canonicity: The representation in m_map must be canonical.

Running time: Imagine your implementation is part of a library, so it should be
big-O optimal. In addition:
- Do not make big-O more operations on K and V than necessary,
because you do not know how fast operations on K/V are; remember that
constructions, destructions and assignments are operations as well.
- Do not make more than two operations of amortized O(log N),
in contrast to O(1), running time, where N is the number of elements in m_map.
Any operation that needs to find a position in the map "from scratch",
without being given a nearby position, is such an operation.
*/

template<typename K, typename V>
class interval_map {
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if ( !(keyBegin < keyEnd) ) {
            return;
        }

        // Step 1: find if there is elements with key <= keyBegin and
        // value == val.
        // 'low' iterator could be:
        // - iterator with key >= keyBegin
        // - first iterator - begin()
        // - end() iterator, all elements have key < keyBegin
        auto low = m_map.lower_bound(keyBegin); // logarithmic
//        if (low != m_map.end()) {
//            std::cout << "-- internal: low key after lower_bound: " <<
//                         low->first << ", " << low->second << std::endl;
//        }

        // Go to the previous map entries if they have the same value
        while(low != m_map.begin()) {
            auto previous = low;
            --previous;
            if ( !(previous->second == val) ) {
                break;
            }

            low = previous;
        }

        const K key = (low == m_map.end() || keyBegin < low->first) ?
                    keyBegin : low->first;

        // Step 2: find first iterator with key >= keyEnd and value > val
        auto high = m_map.lower_bound(keyEnd); // logarithmic
//        if (high != m_map.end()) {
//            std::cout << "-- internal: high key after lower_bound: " <<
//                         high->first << ", " << high->second << std::endl;
//        }

        auto findValueOfPrevNode = [&]() -> const V {
            auto prev = high;
            if (prev != m_map.begin()) {
                --prev;
            }

            return prev->second;
        };

        const V prevValue = findValueOfPrevNode();
        K nextKeyBegin = keyEnd;

        // Go to the next map elements if they have the same value
        while(high != m_map.end()) {
            if ( !(nextKeyBegin < high->first) && high->second == val ) {
                ++high;
                nextKeyBegin = (high == m_map.end()) ?
                            std::numeric_limits<K>::max() : high->first;
            }
            else {
                break;
            }
        }

        // Erase map entries from [low, high)
        auto nextAfterHigh = m_map.erase(low, high);
//        if (nextAfterHigh != m_map.end()) {
//            std::cout << "-- internal: nextAfterHigh: " <<
//                         nextAfterHigh->first << ", " <<
//                         nextAfterHigh->second << std::endl;
//        }

        // Insert new pair before iterator, which we get from the 'erase'
        // operation, in constant time.
        m_map.insert(nextAfterHigh, {key, val});

        const K nextKeyEnd = (high != m_map.end()) ?
                    high->first : std::numeric_limits<K>::max();
        assign(nextKeyBegin, nextKeyEnd, prevValue);
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }

    bool checkNodes() {
        if (m_map.size() < 2) {
            return true;
        }

        for (auto iter = m_map.begin(), nextIter = ++m_map.begin();
             nextIter != m_map.end();
             ++iter, ++nextIter)
        {
            if (iter->second == nextIter->second) {
//                std::cout << "Error: nodes " << iter->first << " and " <<
//                             nextIter->first << " have same value " <<
//                            iter->second << std::endl;
                return false;
            }
        }

        return true;
    }
};
