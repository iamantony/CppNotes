#ifndef CPPNOTESMAIN_FENWICK_TREE_HPP
#define CPPNOTESMAIN_FENWICK_TREE_HPP

/*
Based on: https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/datastructures/fenwicktree/FenwickTreeRangeQueryPointUpdate.java
Fenwick Tree is a data structure that helps to quickly - O(log n) -  calc range sum for array of
numbers.

Usually FT uses 1-based array as internal DS.

The main idea is that (almost) each cell would hold not only its value. Instead cell would hold
sum of cells that this cell is responsible for.

Let's show cells responsibility for tree of size 16

 Cell index   | Responsibility
 16 (0b10000)           |
 15 (0b01111)   |       |
 14 (0b01110)     |     |
 13 (0b01101)   | |     |
 12 (0b01100)       |   |
 11 (0b01011)   |   |   |
 10 (0b01010)     | |   |
 9  (0b01001)   | | |   |
 8  (0b01000)         | |
 7  (0b00111)   |     | |
 6  (0b00110)     |   | |
 5  (0b00101)   | |   | |
 4  (0b00100)       | | |
 3  (0b00011)   |   | | |
 2  (0b00010)     | | | |
 1  (0b00001)   | | | | |

Cells responsibility depends on a position of least significant bit (LSB) in its index. For example:
- indexes with LSB(i) == 1 are responsible only for their own - it is indexes 1 (0b01), 3 (0b11), etc.
- indexes with LSB(i) == 2 are responsible for themselves + previous index - it is indexes 2, 6, etc.
- indexes with LSB(i) == 3 are responsible for themselves + previous 3 indexes - it is indexes 4, 12, etc.

 Cell index   | Responsibility | Initial value | FT value
 10 (0b01010)     |              4              12 (=8+4)
 9  (0b01001)   | |              8              8
 8  (0b01000)         |          1              27 (=5+4+3+1+0+6+7+1 == 13+6+7+1)
 7  (0b00111)   |     |          7              7
 6  (0b00110)     |   |          6              6 (=6+0)
 5  (0b00101)   | |   |          0              0
 4  (0b00100)       | |          1              13 (=4+5+3+1 == 9+3+1)
 3  (0b00011)   |   | |          3              3
 2  (0b00010)     | | |          4              9 (=4+5)
 1  (0b00001)   | | | |          5              5

*/

#include <vector>
#include <stdexcept>

namespace Types::DS {
    template <typename T>
    class FenwickTree {
        std::vector<T> m_tree;

        // Returns the value of the least significant bit (LSB)
        // lsb(108) = lsb(0b1101100) =     0b100 = 4
        // lsb(104) = lsb(0b1101000) =    0b1000 = 8
        // lsb(96)  = lsb(0b1100000) =  0b100000 = 32
        // lsb(64)  = lsb(0b1000000) = 0b1000000 = 64
        size_t LSB(const size_t index) {
            const auto int_index = static_cast<int>(index);

            // Isolates the lowest one bit value
            const auto int_lsb = int_index & -int_index;
            return static_cast<size_t>(int_lsb);
        }

        T prefix_sum_impl(size_t i) {
            if (i >= m_tree.size()) {
                throw std::runtime_error("Invalid index in arguments");
            }

            T sum = {};
            while (i != 0 && i < m_tree.size()) {
                sum += m_tree[i];
                i -= LSB(i);
            }

            return sum;
        }

    public:
        explicit FenwickTree(const size_t size) {
            if (size <= 0) {
                throw std::runtime_error("Size of Fenwick tree must be at least 1");
            }

            // Tree is 1-based. Index 0 of m_tree will not be used
            m_tree = std::vector<T>(size + 1, {});
        }

        explicit FenwickTree(const std::vector<T>& data) {
            if (data.empty()) {
                throw std::runtime_error("Can't create Fenwick tree from empty array");
            }

            // Tree is 1-based. Index 0 of m_tree will not be used
            m_tree.push_back({});
            m_tree.insert(m_tree.end(), data.begin(), data.end());

            for (size_t i = 1; i < m_tree.size(); ++i) {
                const auto parent = i + LSB(i);
                if (parent < m_tree.size()) {
                    m_tree[parent] += m_tree[i];
                }
            }
        }

        // Computes the prefix sum from [1, i], O(log n)
        T prefix_sum(size_t i) {
            ++i; // because we use 1-based tree
            return prefix_sum_impl(i);
        }

        // Returns the sum of the interval [left, right], O(log n)
        T sum(size_t left, size_t right) {
            // Increase input indexes because we use 1-based tree
            ++left;
            ++right;

            if (right < left || left > m_tree.size()) {
                throw std::runtime_error("Invalid indexes in arguments");
            }

            return prefix_sum_impl(right) - prefix_sum_impl(left - 1);
        }

        // Get the value at index i
        T get(const size_t i) {
            return sum(i, i);
        }

        // Add 'v' to index 'i', O(log n)
        void add(size_t i, T v) {
            ++i; // because we use 1-based tree
            if (i >= m_tree.size()) {
                throw std::runtime_error("Invalid index in arguments");
            }

            while (i < m_tree.size()) {
                m_tree[i] += v;
                i += LSB(i);
            }
        }

        // Set index i to be equal to v, O(log n)
        void set(const size_t i, T v) {
            add(i, v - sum(i, i));
        }
    };
}

#endif //CPPNOTESMAIN_FENWICK_TREE_HPP
