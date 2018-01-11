#ifndef VECTOR_DS_HPP
#define VECTOR_DS_HPP

// Specification of Vector:
// - use only raw pointers
// - by default allocate 16 items
// - increase capacity by factor 2

namespace vds {

template <typename T>
class Vector {
public:
    Vector() {}
    Vector(const size_t& size);
    Vector(const size_t& size, const T& defaultValue);
    ~Vector();

    // TODO: copy constructor, copy operators....

    size_t size() const;
    size_t capacity() const;
    void resize(const size_t& size);
    bool isEmpty() const;
    T& at(const size_t& index);
    const T& at(const size_t& index);
    void push(T& item);
    void insert(const size_t& index, T& item);
    void prepend(T& item);
    T& pop();
    void deleteItem(const size_t& index);
    void remove(const T& item);
    bool find(const T& item, size_t& index);

private:
    T* m_array;
    size_t m_size;
    size_t m_capacity;
    const size_t DEFAULT_SIZE = 16;
};

template <typename T>
Vector::Vector() : Vector(DEFAULT_SIZE) {
    m_size = 0;
}

template <typename T>
Vector::Vector(const size_t& size) {
    if (size > 0) {
        m_array = new T[size];
    }

    m_size = size;
    m_capacity = size;
}

template <typename T>
Vector::Vector(const size_t& size, const T& defaultValue) : Vector(size) {
    for (size_t i = 0; i < size; ++i) {
        m_array[i] = defaultValue;
    }
}

template <typename T>
Vector::~Vector() {
    if (m_capacity > 0 && m_array != nullptr) {
        delete [] m_array;
    }
}

}

#endif // VECTOR_DS_HPP
