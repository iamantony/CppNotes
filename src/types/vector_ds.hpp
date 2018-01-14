#ifndef VECTOR_DS_HPP
#define VECTOR_DS_HPP

// Specification of Vector:
// - use only raw pointers
// - by default allocate 16 items
// - increase capacity by factor 2

#include <algorithm>
#include <stdexcept>

namespace DS {

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
    const T& at(const size_t& index) const;
    void push_back(const T& item);
    void prepend(const T& item);
    void insert(const size_t& index, const T& item);
    T& pop();
    void deleteItem(const size_t& index);
    void remove(const T& item);
    bool find(const T& item, size_t& index);

    T& operator[](const size_t& index);
    const T& operator[](const size_t& index) const;

private:
    void clear();
    void recreate(const size_t& newSize, const size_t& newCapacity);

private:
    T* m_array;
    size_t m_size;
    size_t m_capacity;
    const size_t DEFAULT_CAPACITY = 16;
};

template <typename T>
Vector::Vector() : Vector(DEFAULT_CAPACITY) {
    m_size = 0;
}

template <typename T>
Vector::Vector(const size_t& size) {
    if (size > 0) {
        m_array = new T[size];
    }

    m_size = 0;
    m_capacity = size;
}

template <typename T>
Vector::Vector(const size_t& size, const T& defaultValue) : Vector(size) {
    if (size > 0) {
        std::fill_n(m_array, m_size, defaultValue);
    }
}

template <typename T>
Vector::~Vector() {
    clear();
}

template <typename T>
void Vector::clear() {
    if (m_array != nullptr) {
        delete [] m_array;
        m_array = nullptr;
    }

    m_size = m_capacity = 0;
}

template <typename T>
size_t Vector::size() const {
    return m_size;
}

template <typename T>
size_t Vector::capacity() const {
    return m_capacity;
}

template <typename T>
void Vector::resize(const size_t& size) {
    if (size == m_size) {
        return;
    }

    if (0 == size) {
        clear();
        return;
    }

    if (size < m_size) {
        size_t newCapacity =
                (size * 2 <= m_capacity / 2) ? size * 2 : m_capacity;

        recreate(size, newCapacity);
    }
    else if (size > m_size) {
        if (size <= m_capacity ) {
            m_size = size;
        }
        else {
            recreate(size, size * 2);
        }
    }
}

template <typename T>
void Vector::recreate(const size_t& newSize, const size_t& newCapacity) {
    if (newCapacity == 0) {
        clear();
        return;
    }

    T* newArray = new T[newCapacity];
    size_t minSize = std::min(m_size, newSize);

    // Copy elements from original array to new array
    std::copy_n(m_array, minSize, newArray);

    // Replace copied elements with default-constructed elements of type T.
    // On the next step we will call 'delete' for original array, that would
    // call destructors for all elements. We don't want to destruct copied
    // elements, that is why we replace them with default values.
    std::fill_n(m_array, minSize, T());

    clear();
    m_array = newArray;
    m_size = minSize;
    m_capacity = newCapacity;
}

template <typename T>
bool Vector::isEmpty() const {
    return m_size == 0;
}

template <typename T>
T& Vector::at(const size_t& index) {
    // Effective C++ by Meyers, Item 3
    // To remove code duplication we call const version of at() from
    // non-const version of at().
    // First of all, we need to cast 'this' to 'const this' to access
    // const at(). After that we should remove constness with const_cast.

    // "Even more worth knowing is that trying to do things the other way
    // around — avoiding duplication by having the const version call the
    // non-const version — is not something you want to do. Remember, a
    // const member function promises never to change the logical state of
    // its object, but a non-const member function makes no such promise.
    // If you were to call a non-const function from a const one, you’d run the
    // risk that the object you’d promised not to modify would be changed.
    // That’s why having a const member function call a non-const one is
    // wrong: the object could be changed. In fact, to get the code to compile,
    // you’d have to use a const_cast to get rid of the const on *this, a clear
    // sign of trouble. The reverse calling sequence — the one we used above
    // — is safe: the non-const member function can do whatever it wants
    // with an object, so calling a const member function imposes no risk.
    // That’s why a static_cast works on *this in that case: there’s no
    // constrelated danger."

    return const_cast<T&>(static_cast<const Vector&>(*this).at(index));
}

template <typename T>
const T& Vector::at(const size_t& index) const {
    // Check that index is valid. Throw exception on error.
    if (index >= size) {
        throw std::out_of_range("Invalid index");
    }

    return m_array[index];
}

template <typename T>
T& Vector::operator[](const size_t& index) {
    // For explanations see non-const at() function
    return const_cast<T&>(static_cast<const Vector&>(*this)[index]);
}

template <typename T>
const T& Vector::operator[](const size_t& index) const {
    // Warning: No bounds checking!
    return m_array[index];
}

template <typename T>
void Vector::push_back(const T& item) {
    insert(m_size, item);
}

template <typename T>
void Vector::prepend(const T& item) {
    insert(0, item);
}

template <typename T>
void Vector::insert(const size_t& index, const T& item) {
    // Make sure that we have enough space to insert new item
    if (m_size == m_capacity) {
        size_t newCapacity =
                (m_capacity == 0) ? DEFAULT_CAPACITY : m_capacity * 2;
        recreate(m_size + 1, newCapacity);
    }

    // If index is bigger than size of the array, then we will insert item
    // at the end of the array
    if (index >= m_size) {
        m_array[m_size] = item;
        ++m_size;
        return;
    }

    // Move 'size - index' elements one step to the end of the array to free
    // space for new item
    for (size_t toInd = m_size, fromInd = m_size -1; fromInd >= index;
         --toInd, --fromInd) {
        m_array[toInd] = m_array[fromInd];

        // When we reach first element, break for cycle so we not overflow
        // unsigned integer 'fromInd'
        if (fromInd == 0) {
            break;
        }
    }

    m_array[index] = item;
    ++m_size;
}

template <typename T>
T& Vector::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Vector is empty");
    }

    T item = m_array[m_size - 1];
    m_array[m_size - 1] = T();
    --m_size;
    return item;
}

template <typename T>
void Vector::deleteItem(const size_t& index) {
    if (index >= m_size) {
        throw std::out_of_range("Invalid index");
    }

    // If we remove element somewhere in the middle of the array, then we
    // need to move all elements from the right of this element to one position
    // to the left
    for (size_t toInd = index, fromInd = index + 1; toInd < m_size - 1;
         ++toInd, ++fromInd) {
        m_array[toInd] = m_array[fromInd];
    }

    // Set up last element as default-constructed element
    m_array[m_size -1] = T();
    --m_size;
}

template <typename T>
void Vector::remove(const T& item) {
    if (isEmpty()) {
        return;
    }

    for (size_t i = m_size - 1; i >= 0; --i) {
        if (m_array[i] == item) {
            deleteItem(i);
        }

        if (i == 0) {
            break;
        }
    }
}

template <typename T>
bool Vector::find(const T& item, size_t& index) {
    for (size_t i = 0 ; i < m_size; ++i) {
        if (m_array[i] == item) {
            index = i;
            return true;
        }
    }

    return false;
}

}

#endif // VECTOR_DS_HPP
