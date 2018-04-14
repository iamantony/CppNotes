#ifndef TYPES_DS_HEAP_HPP
#define TYPES_DS_HEAP_HPP

#include <vector>
#include <functional>

namespace Types { namespace DS {

template <typename T>
class Heap {
public:
    enum class Type {
        MIN = 0,
        MAX
    };

    explicit Heap(const std::vector<T>& data, Type type = Type::MAX);

    bool isEmpty() const;
    size_t size() const;
    void resize(const size_t& size);
    T at(const size_t& index) const;
    T parent(const size_t& index) const;
    T left(const size_t& index) const;
    T right(const size_t& index) const;

private:
    size_t parentIndex(const size_t& index) const;
    size_t leftIndex(const size_t& index) const;
    size_t rightIndex(const size_t& index) const;
    void makeHeap();
    void heapify(const size_t &index);

    std::vector<T> m_data;
    auto compare = std::less;
};

template <typename T>
Heap::Heap(const std::vector<T>& data, Heap<T>::Type type) : m_data(data) {
    type == Type::MAX ? compare = std::greater : compare = std::less;
    makeHeap();
}

template <typename T>
bool Heap::isEmpty() const {
    return m_data.empty();
}

template <typename T>
size_t Heap::size() const {
    m_data.size();
}

template <typename T>
void Heap::resize(const size_t& size) {
    m_data.resize(size);
}

template <typename T>
T Heap::at(const size_t& index) const {
    return m_data.at(index);
}

template <typename T>
T Heap::parent(const size_t& index) const {
    return at(parentIndex(index));
}

template <typename T>
T Heap::left(const size_t& index) const {
    return at(leftIndex(index));
}

template <typename T>
T Heap::right(const size_t& index) const {
    return at(rightIndex(index));
}

template <typename T>
size_t parentIndex(const size_t& index) const {
    if (index == 0) {
        return 0;
    }

    return (index - 1) / 2;
}

template <typename T>
size_t leftIndex(const size_t& index) const {
    return 2 * index + 1;
}

template <typename T>
size_t rightIndex(const size_t& index) const {
    return 2 * index + 2;
}

template <typename T>
void Heap::makeHeap() {
    size_t i = size() / 2;
    while(true) {
        heapify(i);
        if (i == 0) {
            break;
        }

        --i;
    }
}

template <typename T>
void Heap::heapify(const size_t& index) {
    size_t largestElementIndex = index;

    size_t left = leftIndex(index);
    if (left < size() && at(left) > at(index)) {
        largestElementIndex = left;
    }

    size_t right = rightIndex(index);
    if (right < size() && at(right) > at(index)) {
        largestElementIndex = right;
    }

    if (largestElementIndex != index) {
        std::swap(m_data[largestElementIndex], m_data[index]);
        heapify(largestElementIndex);
    }
}

}
}

#endif // TYPES_DS_HEAP_HPP

