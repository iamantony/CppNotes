#ifndef DIRECT_ADDRESSING_TABLE_HPP
#define DIRECT_ADDRESSING_TABLE_HPP

/*
Direct addressing table is naive implementation of the hash table. It relies on strong assumption
on range of possible keys.

Key-value pairs are stored in simple table (array, vector) of fixed size. Size of the table == max
value of the key.

Advantages:
- simple design
- insertion, deletion and search operations are O(1) because key == position in the array (vector).

Disadvantages:
- we have to allocate memory for all keys (and values) even if no key-value pair would be inserted
during the lifetime of the direct addressing table object.
*/

#include <array>

namespace Types::DS {
    template <typename V, size_t MAX_KEY = 256>
    class DirectAddressingTable {
        std::array<V, MAX_KEY> m_table;
        std::array<bool, MAX_KEY> m_status_table;

    public:
        DirectAddressingTable() {
            m_status_table.fill(false);
        }

        // TC: O(1)
        V& at(const size_t key) {
            if (key >= MAX_KEY) {
                throw std::runtime_error("Trying to use key that is >= than MAX_KEY");
            }

            if (!m_status_table[key]) {
                throw std::runtime_error("Trying to access key that was not inserted to table");
            }

            return m_table[key];
        }

        // TC: O(1)
        void insert(const size_t key, V value) {
            if (key >= MAX_KEY) {
                throw std::runtime_error("Trying to use key that is >= than MAX_KEY");
            }

            m_table[key] = std::move(value);
            m_status_table[key] = true;
        }

        // TC: O(1)
        void erase(const size_t key) {
            if (key >= MAX_KEY) {
                throw std::runtime_error("Trying to use key that is >= than MAX_KEY");
            }

            if (m_status_table[key]) {
                m_table[key] = V{};
                m_status_table[key] = false;
            }
        }

        bool contains(const size_t key) const {
            if (key >= MAX_KEY) {
                throw std::runtime_error("Trying to use key that is >= than MAX_KEY");
            }

            return m_status_table[key];
        }
    };
}

#endif //DIRECT_ADDRESSING_TABLE_HPP
