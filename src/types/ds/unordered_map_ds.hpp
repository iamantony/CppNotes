#ifndef CPPNOTESMAIN_UNORDERED_MAP_DS_HPP
#define CPPNOTESMAIN_UNORDERED_MAP_DS_HPP

/*
https://leetcode.com/problems/design-hashmap/
Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:
- put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the
HashMap, update the value.
- get(key): Returns the value to which the specified key is mapped, or -1 if this map contains
no mapping for the key.
- remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
*/

#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>
#include "hash_functions.hpp"
#include "../../algorithms/math/primes.hpp"

namespace Types::DS {
    template <typename V>
    class UnorderedMap {
        class UnorderedMapImpl {
            enum class EntryState {
                empty = 0,
                occupied,
                deleted
            };

            struct Entry {
                int32_t key;
                V value;
                EntryState state = EntryState::empty;
            };

            std::vector<Entry> m_table;
            std::unique_ptr<HashModulo> m_h1;
            std::unique_ptr<HashModulo> m_h2;
            size_t m_elements_num = 0;

            size_t find(int32_t key) const;
            size_t hash(int32_t key, size_t attempt) const;

        public:
            explicit UnorderedMapImpl(size_t table_size);
            UnorderedMapImpl(size_t table_size, UnorderedMapImpl& other);

            bool contains(int32_t key) const;
            bool is_empty() const;
            bool is_full() const;
            size_t elements_num() const;
            size_t table_size() const;
            void insert(int32_t key, V&& value);
            V get(int32_t key) const;
            void remove(int32_t key);
        };

        std::unique_ptr<UnorderedMapImpl> m_impl;
        void rehashing();

    public:
        UnorderedMap();

        bool contains(int32_t key) const;
        bool is_empty() const;
        size_t size() const;
        void insert(int32_t key, V value);
        V get(int32_t key) const;
        void remove(int32_t key);
    };

    template <typename V>
    UnorderedMap<V>::UnorderedMapImpl::UnorderedMapImpl(const size_t table_size) {
        if (table_size == 0) {
            throw std::runtime_error("Invalid table size for unordered map");
        }

        m_table.resize(table_size);
        m_h1 = std::make_unique<HashModulo>(m_table.size());
        m_h2 = std::make_unique<HashModulo>(m_table.size() - 1);
    }

    template <typename V>
    UnorderedMap<V>::UnorderedMapImpl::UnorderedMapImpl(
        const size_t table_size,
        UnorderedMap<V>::UnorderedMapImpl& other)
            : UnorderedMapImpl(table_size)
    {
        if (m_table.size() < other.m_table.size()) {
            throw std::runtime_error("Can't move elements from bigger map");
        }

        for (auto& entry : other.m_table) {
            if (entry.state != EntryState::occupied) { continue; }

            insert(entry.key, std::move(entry.value));
        }
    }

    template <typename V>
    bool UnorderedMap<V>::UnorderedMapImpl::contains(const int32_t key) const {
        return find(key) < m_table.size();
    }

    template <typename V>
    bool UnorderedMap<V>::UnorderedMapImpl::is_empty() const {
        return elements_num() == 0;
    }

    template <typename V>
    bool UnorderedMap<V>::UnorderedMapImpl::is_full() const {
        return m_elements_num == m_table.size();
    }

    template <typename V>
    size_t UnorderedMap<V>::UnorderedMapImpl::elements_num() const {
        return m_elements_num;
    }

    template <typename V>
    size_t UnorderedMap<V>::UnorderedMapImpl::table_size() const {
        return m_table.size();
    }

    template <typename V>
    size_t UnorderedMap<V>::UnorderedMapImpl::find(const int32_t key) const {
        size_t index = m_table.size();
        if (is_empty()) { return index; }
        for (size_t attempt = 0; attempt < m_table.size(); ++attempt) {
            const auto id = hash(key, attempt);
            if (m_table[id].state == EntryState::empty) { break; }
            if (m_table[id].state == EntryState::deleted) { continue; }
            if (m_table[id].key == key) {
                index = id;
                break;
            }
        }

        return index;
    }

    template <typename V>
    size_t UnorderedMap<V>::UnorderedMapImpl::hash(const int32_t key, const size_t attempt) const {
        return ((*m_h1)(key) + attempt * (1 + (*m_h2)(key))) % m_table.size();
    }

    template <typename V>
    void UnorderedMap<V>::UnorderedMapImpl::insert(const int32_t key, V&& value) {
        const auto index = find(key);
        if (index < m_table.size()) {
            m_table[index].value = std::move(value);
            return;
        }

        if (is_full()) {
            throw std::runtime_error("Can't insert new element - table is full");
        }

        for (size_t attempt = 0; attempt < m_table.size(); ++attempt) {
            const auto id = hash(key, attempt);
            if (m_table[id].state == EntryState::empty ||
                m_table[id].state == EntryState::deleted)
            {
                m_table[id].key = key;
                m_table[id].value = std::move(value);
                m_table[id].state = EntryState::occupied;
                ++m_elements_num;
                return;
            }
        }

        const auto msg = std::string("Failed to insert key: ") + std::to_string(key);
        throw std::runtime_error(msg);
    }

    template <typename V>
    V UnorderedMap<V>::UnorderedMapImpl::get(const int32_t key) const {
        const auto index = find(key);
        if (index >= m_table.size()) {
            const auto msg = std::string("Key ") + std::to_string(key) + " not found";
            throw std::runtime_error(msg);
        }

        return m_table[index].value;
    }

    template <typename V>
    void UnorderedMap<V>::UnorderedMapImpl::remove(const int32_t key) {
        const auto index = find(key);
        if (index >= m_table.size()) { return; }

        m_table[index].key = {};
        m_table[index].value = {};
        m_table[index].state = EntryState::deleted;
        --m_elements_num;
    }

    template <typename V>
    UnorderedMap<V>::UnorderedMap() {
        m_impl = std::make_unique<UnorderedMapImpl>(7);
    }

    template <typename V>
    bool UnorderedMap<V>::contains(const int32_t key) const {
        return m_impl->contains(key);
    }

    template <typename V>
    bool UnorderedMap<V>::is_empty() const {
        return m_impl->is_empty();
    }

    template <typename V>
    size_t UnorderedMap<V>::size() const {
        return m_impl->elements_num();
    }

    template <typename V>
    void UnorderedMap<V>::insert(const int32_t key, V value) {
        if (m_impl->is_full()) {
            rehashing();
        }

        m_impl->insert(key, std::move(value));
    }

    template <typename V>
    void UnorderedMap<V>::rehashing() {
        const auto new_table_size = Algo::Math::GetNextPrime(m_impl->table_size() * 2);
        auto new_impl = std::make_unique<UnorderedMapImpl>(new_table_size, *m_impl);
        m_impl = std::move(new_impl);
    }

    template <>
    int32_t UnorderedMap<int32_t>::get(const int32_t key) const {
        try {
            return m_impl->get(key);
        }
        catch (...) {
            return -1;
        }
    }

    template <typename V>
    V UnorderedMap<V>::get(const int32_t key) const {
        return m_impl->get(key);
    }

    template <typename V>
    void UnorderedMap<V>::remove(const int32_t key) {
        m_impl->remove(key);
    }
}

#endif //CPPNOTESMAIN_UNORDERED_MAP_DS_HPP
