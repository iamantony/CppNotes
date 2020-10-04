#ifndef CPPNOTESMAIN_LRU_CACHE_HPP
#define CPPNOTESMAIN_LRU_CACHE_HPP

/*
https://leetcode.com/problems/lru-cache/
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the
key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict
the least recently used key.

Follow up:
Could you do get and put in O(1) time complexity?

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/

#include <unordered_map>
#include <list>

namespace Types::DS {
    template <typename K, typename V>
    class LRUCache {
        struct Data {
            K key;
            V value;
            typename std::list<K>::iterator iter;
        };

        size_t m_capacity = 0;
        std::unordered_map<K, Data> m_map;
        std::list<K> m_list;

        void update_key(typename std::unordered_map<K, Data>::iterator iter) {
            if (iter == m_map.end()) { return; }

            auto list_iter = iter->second.iter;
            m_list.erase(list_iter);
            m_list.push_back(iter->second.key);
            iter->second.iter = std::prev(m_list.end());
        }

    public:
        LRUCache(size_t capacity) {
            m_capacity = capacity;
        }

        V get(const K key) {
            auto iter = m_map.find(key);
            if (iter == m_map.end()) {
                throw std::runtime_error("Key is not in LRU cache");
            }

            update_key(iter);
            return iter->second.value;
        }

        bool contains(const K key) const {
            return m_map.count(key) > 0;
        }

        void put(const K key, V value) {
            auto iter = m_map.find(key);
            if (iter != m_map.end()) {
                iter->second.value = value;
                update_key(iter);
                return;
            }

            if (m_map.size() == m_capacity) {
                auto key_to_remove = m_list.front();
                m_list.pop_front();
                m_map.erase(key_to_remove);
            }

            m_list.push_back(key);
            m_map.emplace(key, {key, std::move(value), std::prev(m_list.end())});
        }
    };
}

#endif //CPPNOTESMAIN_LRU_CACHE_HPP
