#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

// Implement Iterator class that would iterate over some vector.
// Iteration step - 2 elements

#include <iterator>
#include <vector>
#include <exception>

namespace Types {

template <typename T>
class VectorIterator : public std::bidirectional_iterator_tag {
    std::vector<T>& m_v;
    size_t m_pos;

public:
    VectorIterator(std::vector<T>& v) : m_v(v), m_pos(0) {}
    VectorIterator(VectorIterator<T>& other) :
        m_v(other.m_v), m_pos(other.m_pos) { }

    VectorIterator<T>& operator=(VectorIterator<T>& other) {
        if (&m_v == &other.m_v) {
            m_pos = other.m_pos;
        }
        else {
            throw std::logic_error(
                        "Can't assign iterator that work with other container");
        }

        return *this;
    }

    ~VectorIterator() {}

    VectorIterator() = delete;
    VectorIterator(VectorIterator<T>&& other) = delete;
    VectorIterator<T>& operator=(VectorIterator<T>&& other) = delete;

    friend bool operator==(const VectorIterator<T>& left,
                           const VectorIterator<T>& right) {
        if (&left.m_v == &right.m_v &&
                ((left.m_pos >= left.m_v.size() &&
                            right.m_pos >= right.m_v.size()) ||
                 left.m_pos == right.m_pos))
        {
            return true;
        }

        return false;
    }

    friend bool operator !=(const VectorIterator<T>& left,
                            const VectorIterator<T>& right) {
        return !(left == right);
    }

    T& operator*() {
        return const_cast<T&>(static_cast<const VectorIterator<T>*>(this)->operator*());
    }

    const T& operator*() const {
        if (isEndIter()) {
            throw std::out_of_range("Operation on end iterator");
        }

        return m_v[m_pos];
    }

    VectorIterator<T>& operator++() {
        m_pos = m_pos > m_v.size() - 2 ? m_v.size() : m_pos + 2;
        return *this;
    }

    VectorIterator<T> operator++(int) {
        VectorIterator<T> temp(*this);
        this->operator++();
        return temp;
    }

    VectorIterator<T>& operator--() {
        m_pos = m_pos > 1 ? m_pos - 2 : 0;
        return *this;
    }

    VectorIterator<T> operator--(int) {
        VectorIterator<T> temp(*this);
        this->operator--();
        return temp;
    }

    VectorIterator<T> begin() {
        VectorIterator<T> beginIter(*this);
        beginIter.m_pos = 0;
        return beginIter;
    }

    VectorIterator<T> end() {
        VectorIterator<T> endIter(*this);
        endIter.m_pos = endIter.m_v.size();
        return endIter;
    }

private:
    bool isEndIter() const {
        return m_pos >= m_v.size();
    }
};

}

#endif // VECTOR_ITERATOR_HPP
