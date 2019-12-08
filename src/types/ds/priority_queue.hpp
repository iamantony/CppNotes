#ifndef TYPES_DS_PRIORITY_QUEUE_HPP
#define TYPES_DS_PRIORITY_QUEUE_HPP

#include "heap.hpp"

namespace Types::DS {

    template <typename T>
    class PriorityQueue {

        struct Element {
            size_t priority;
            T value;

            friend bool operator<(const Element& left, const Element& right) {
                return left.priority < right.priority;
            }

            friend bool operator>(const Element& left, const Element& right) {
                return left.priority > right.priority;
            }
        };

        Heap<Element> m_heap;

    public:
        enum class Type {
            MIN = 0,
            MAX
        };

        explicit PriorityQueue(Types::DS::PriorityQueue<T>::Type type = Type::MAX);

        bool isEmpty() const;
        bool size() const;
        void insert(T value, size_t priority);
        T top();
        void pop();
        void setPriority(const T& value, size_t priority);
    };
}

template <typename T>
Types::DS::PriorityQueue<T>::PriorityQueue(const Type type) {
    switch(type) {
        case Type::MIN:
            m_heap.setType(Heap<Element>::Type::MIN);
            break;
        case Type::MAX:
        default:
            m_heap.setType(Heap<Element>::Type::MAX);
            break;
    }
}

template <typename T>
bool Types::DS::PriorityQueue<T>::isEmpty() const {
    return m_heap.isEmpty();
}

template <typename T>
bool Types::DS::PriorityQueue<T>::size() const {
    return m_heap.size();
}

template <typename T>
void Types::DS::PriorityQueue<T>::insert(const T value, const size_t priority) {
    m_heap.add({priority, value});
}

template <typename T>
T Types::DS::PriorityQueue<T>::top() {
    return m_heap.at(0).value;
}

template <typename T>
void Types::DS::PriorityQueue<T>::pop() {
    m_heap.pop();
}

template <typename T>
void Types::DS::PriorityQueue<T>::setPriority(const T& value, const size_t new_priority) {
    const auto& data = m_heap.exportData();
    const auto heap_size = m_heap.size();
    std::vector<size_t> found_indexes;
    for (size_t i  = 0; i < heap_size; ++i) {
        if (data[i].value == value) {
            found_indexes.push_back(i);
        }
    }

    for (const auto& index : found_indexes) {
        m_heap.setValue(index, {new_priority, value});
    }
}

#endif // TYPES_DS_PRIORITY_QUEUE_HPP
