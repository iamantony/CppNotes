#ifndef TYPES_DS_HEAP_HPP
#define TYPES_DS_HEAP_HPP

#include <vector>
#include <functional>

using std::placeholders::_1;
using std::placeholders::_2;

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

    std::vector<T> exportData() const;

private:
    size_t parentIndex(const size_t& index) const;
    size_t leftIndex(const size_t& index) const;
    size_t rightIndex(const size_t& index) const;
    void makeHeap();
    void heapify(const size_t &index);

    std::vector<T> m_data;

    std::function<bool(const T&, const T&)> comparator;
};

template <typename T>
Heap<T>::Heap(const std::vector<T>& data, Heap<T>::Type type) : m_data(data) {
    if (type == Type::MAX) {
        comparator = std::bind(std::greater<T>(), _1, _2);
    }
    else {
        comparator = std::bind(std::less<T>(), _1, _2);
    }

    makeHeap();
}

template <typename T>
bool Heap<T>::isEmpty() const {
    return m_data.empty();
}

template <typename T>
size_t Heap<T>::size() const {
    return m_data.size();
}

template <typename T>
void Heap<T>::resize(const size_t& size) {
    m_data.resize(size);
}

template <typename T>
T Heap<T>::at(const size_t& index) const {
    return m_data.at(index);
}

template <typename T>
T Heap<T>::parent(const size_t& index) const {
    return at(parentIndex(index));
}

template <typename T>
T Heap<T>::left(const size_t& index) const {
    return at(leftIndex(index));
}

template <typename T>
T Heap<T>::right(const size_t& index) const {
    return at(rightIndex(index));
}

template <typename T>
size_t Heap<T>::parentIndex(const size_t& index) const {
    if (index == 0) {
        return 0;
    }

    return (index - 1) / 2;
}

template <typename T>
size_t Heap<T>::leftIndex(const size_t& index) const {
    return 2 * index + 1;
}

template <typename T>
size_t Heap<T>::rightIndex(const size_t& index) const {
    return 2 * index + 2;
}

template <typename T>
void Heap<T>::makeHeap() {
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
void Heap<T>::heapify(const size_t& index) {
    size_t searchedElementIndex = index;

    size_t left = leftIndex(index);
    if (left < size() && comparator( at(left), at(searchedElementIndex) )) {
        searchedElementIndex = left;
    }

    size_t right = rightIndex(index);
    if (right < size() && comparator( at(right), at(searchedElementIndex) )) {
        searchedElementIndex = right;
    }

    if (searchedElementIndex != index) {
        std::swap(m_data[searchedElementIndex], m_data[index]);
        heapify(searchedElementIndex);
    }
}

template <typename T>
std::vector<T> Heap<T>::exportData() const {
    return m_data;
}

}
}

#endif // TYPES_DS_HEAP_HPP

