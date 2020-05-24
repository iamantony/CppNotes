#ifndef CPPNOTESMAIN_RANDOMIZED_SET_HPP
#define CPPNOTESMAIN_RANDOMIZED_SET_HPP

/*
https://leetcode.com/problems/insert-delete-getrandom-o1/
Design a data structure that supports all following operations in average O(1) time.

- insert(val): Inserts an item val to the set if not already present.
- remove(val): Removes an item val from the set if present.
- getRandom: Returns a random element from current set of elements. Each element must have the
same probability of being returned.

Example:
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/

#include <unordered_map>
#include <vector>
#include <random>
#include <limits>

namespace Types::DS {
    class RandomizedSet {
        std::unordered_map<int, size_t> m_values_pos_map;
        std::vector<int> m_values;
        std::mt19937 m_mt;
        std::uniform_int_distribution<size_t> m_dist;

    public:
        RandomizedSet() : m_mt(456), m_dist(0, std::numeric_limits<size_t>::max()) {}

        bool insert(const int value) {
            if (m_values_pos_map.find(value) != m_values_pos_map.end()) { return false; }

            m_values.push_back(value);
            m_values_pos_map[value] = m_values.size() - 1;
            return true;
        }

        bool remove(const int value) {
            if (m_values_pos_map.find(value) == m_values_pos_map.end()) { return false; }

            const auto pos = m_values_pos_map[value];
            std::swap(m_values[pos], m_values[m_values.size() - 1]);
            m_values_pos_map[m_values[pos]] = pos;

            m_values.pop_back();
            m_values_pos_map.erase(value);
        }

        int get_random_key() {
            const auto pos = m_dist(m_mt) % m_values.size();
            return m_values[pos];
        }

        size_t size() const { return m_values.size(); }
    };
}

#endif //CPPNOTESMAIN_RANDOMIZED_SET_HPP
