#ifndef CPPNOTESMAIN_UNORDERED_SET_DS_HPP
#define CPPNOTESMAIN_UNORDERED_SET_DS_HPP

/*
https://leetcode.com/problems/design-hashset/
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:
- add(value): Insert a value into the HashSet.
- contains(value) : Return whether the value exists in the HashSet or not.
- remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
*/

#include <algorithm>
#include <list>
#include <vector>
#include <memory>
#include "hash_functions.hpp"

namespace Types::DS {
    class UnorderedSet {
        const size_t m_initial_size = 4;
        const double m_max_load_factor = 0.75;
        std::vector<std::list<int32_t>> m_buckets;
        std::unique_ptr<HashMultiplyAddShift> m_hash_func;
        size_t m_elements_num = 0;

        void rehashing();

    public:
        UnorderedSet();

        bool contains(int32_t key) const;
        size_t size() const { return m_elements_num; }
        void insert(int32_t key);
        void remove(int32_t key);
    };

    UnorderedSet::UnorderedSet() {
        m_hash_func = std::make_unique<HashMultiplyAddShift>(m_initial_size);
        m_buckets.resize(m_initial_size);
    }

    bool UnorderedSet::contains(const int32_t key) const {
        const auto bucket_num = (*m_hash_func)(key);
        const auto iter = std::find(
            m_buckets[bucket_num].begin(), m_buckets[bucket_num].end(), key);

        return iter != m_buckets[bucket_num].end();
    }

    void UnorderedSet::insert(const int32_t key) {
        const auto bucket_num = (*m_hash_func)(key);
        const auto iter = std::find(
            m_buckets[bucket_num].begin(), m_buckets[bucket_num].end(), key);

        if (iter != m_buckets[bucket_num].end()) { return; }

        m_buckets[bucket_num].push_front(key);
        ++m_elements_num;

        rehashing();
    }

    void UnorderedSet::rehashing() {
        const auto load_factor =
            static_cast<double>(m_elements_num) / static_cast<double>(m_buckets.size());

        if (load_factor < m_max_load_factor) { return; }

        std::vector<std::list<int32_t>> new_buckets(m_buckets.size() * 2);
        std::unique_ptr<HashMultiplyAddShift> new_hash_func =
            std::make_unique<HashMultiplyAddShift>(new_buckets.size());
        for (const auto& list : m_buckets) {
            for (const auto& key : list) {
                const auto bucket_num = (*new_hash_func)(key);
                new_buckets[bucket_num].push_front(key);
            }
        }

        m_buckets = std::move(new_buckets);
        m_hash_func = std::move(new_hash_func);
    }

    void UnorderedSet::remove(const int32_t key) {
        const auto bucket_num = (*m_hash_func)(key);
        const auto iter = std::find(
            m_buckets[bucket_num].begin(), m_buckets[bucket_num].end(), key);

        if (iter == m_buckets[bucket_num].end()) { return; }

        m_buckets[bucket_num].erase(iter);
        --m_elements_num;
    }
}

#endif //CPPNOTESMAIN_UNORDERED_SET_DS_HPP
