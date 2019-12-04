#ifndef TYPES_DS_HEAP_HPP
#define TYPES_DS_HEAP_HPP

#include <vector>
#include <functional>
#include <exception>

using std::placeholders::_1;
using std::placeholders::_2;

namespace Types::DS {

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
        size_t realSize() const;
        void resize(const size_t& size);
        T at(const size_t& index) const;
        T parent(const size_t& index) const;
        T left(const size_t& index) const;
        T right(const size_t& index) const;
        void add(T value);
        void setValue(const size_t& index, T value);
        void swap(const size_t& first, const size_t& second);
        size_t find(const T& value);
        void pop();
        void heapify(const size_t &index);

        std::vector<T> exportData() const;

    private:
        bool isValidIndex(const size_t& index) const;
        size_t parentIndex(const size_t& index) const;
        size_t leftIndex(const size_t& index) const;
        size_t rightIndex(const size_t& index) const;
        void makeHeap();

        size_t m_heapSize;
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

        m_heapSize = m_data.size();
        makeHeap();
    }

    template <typename T>
    bool Heap<T>::isEmpty() const {
        return m_heapSize == 0;
    }

    template <typename T>
    size_t Heap<T>::size() const {
        return m_heapSize;
    }

    template <typename T>
    size_t Heap<T>::realSize() const {
        return m_data.size();
    }

    template <typename T>
    void Heap<T>::resize(const size_t& size) {
        m_heapSize = std::min(realSize(), size);
    }

    template <typename T>
    T Heap<T>::at(const size_t& index) const {
        if (!isValidIndex(index)) {
            throw std::out_of_range("Invalid index");
        }

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
    bool Heap<T>::isValidIndex(const size_t& index) const {
        return index < m_heapSize;
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
    void Heap<T>::add(T value) {
        if (size() < realSize()) {
            m_data[size()] = std::move(value);
        }
        else {
            m_data.push_back(std::move(value));
        }

        ++m_heapSize;
        makeHeap();
    }

    template <typename T>
    void Heap<T>::setValue(const size_t& index, T value) {
        if (!isValidIndex(index)) {
            throw std::out_of_range("Can not set value - invalid index");
        }

        m_data[index] = std::move(value);
        makeHeap();
    }

    template <typename T>
    void Heap<T>::swap(const size_t& first, const size_t& second) {
        if (!isValidIndex(first) || !isValidIndex(second)) {
            throw std::out_of_range("Can not swap items - invalid index");
        }

        std::swap(m_data[first], m_data[second]);
    }

    template <typename T>
    size_t Heap<T>::find(const T& value) {
        for (size_t i = 0; i < m_heapSize; ++i) {
            if (m_data[i] == value) { return i; }
        }

        return size();
    }

    template <typename T>
    void Heap<T>::pop() {
        if (size() == 0) { return; }

        swap(0, size() - 1);
        --m_heapSize;
        heapify(0);
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
            swap(searchedElementIndex, index);
            heapify(searchedElementIndex);
        }
    }

    template <typename T>
    std::vector<T> Heap<T>::exportData() const {
        return m_data;
    }
}

#endif // TYPES_DS_HEAP_HPP
