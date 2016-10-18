#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <vector>
#include <stdexcept>

template <typename T>
class Matrix
{
public:
    Matrix() {}
    Matrix(const size_t& rows, const size_t& cols, const T& value);
    Matrix(const Matrix<T>& other);
    Matrix<T>& operator=(const Matrix<T>& other);

    template<typename K>
    friend bool operator==(const Matrix<K>& left, const Matrix<K>& right);

    void setSize(const size_t& rows, const size_t& cols);
    size_t getRowsNum() const;
    size_t getColsNum() const;
    bool empty() const;
    T getValue(const size_t& row, const size_t& col) const;
    void setValue(const size_t& row, const size_t& col, const T& value);
    void setRowValues(const size_t& row, const std::vector<T>& values);

private:
    std::vector<std::vector<T>> m_values;
};

template<typename T>
Matrix<T>::Matrix(const size_t& rows, const size_t& cols, const T& value)
{
    std::vector<T> basicRow(cols, value);
    m_values = std::vector<std::vector<T>>(rows, basicRow);
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
    m_values = other.m_values;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
    m_values = other.m_values;
    return *this;
}

template<typename K>
bool operator==(const Matrix<K>& left, const Matrix<K>& right)
{
    return left.m_values == right.m_values;
}

template<typename T>
void Matrix<T>::setSize(const size_t& rows, const size_t& cols)
{
    if (0 == rows || cols == 0)
    {
        m_values.clear();
        return;
    }

    if (cols != getColsNum())
    {
        for (std::vector<T> row : m_values)
        {
            row.resize(cols, T());
        }
    }

    if (rows != getRowsNum())
    {
        m_values.resize(rows, std::vector<T>(getColsNum(), T()));
    }
}

template<typename T>
size_t Matrix<T>::getRowsNum() const
{
    return m_values.size();
}

template<typename T>
size_t Matrix<T>::getColsNum() const
{
    if (m_values.empty())
    {
        return 0;
    }

    return m_values.at(0).size();
}

template<typename T>
bool Matrix<T>::empty() const
{
    return m_values.empty();
}

template<typename T>
T Matrix<T>::getValue(const size_t& row, const size_t& col) const
{
    if (getRowsNum() <= row || getColsNum() <= col)
    {
        throw std::out_of_range("Invalid matrix indices");
    }

    return m_values.at(row).at(col);
}

template<typename T>
void Matrix<T>::setValue(const size_t& row, const size_t& col, const T& value)
{
    if (getRowsNum() <= row || getColsNum() <= col)
    {
        throw std::out_of_range("Invalid matrix indices");
    }

    m_values[row][col] = value;
}

template<typename T>
void Matrix<T>::setRowValues(const size_t& row, const std::vector<T>& values)
{
    if (getRowsNum() <= row)
    {
        throw std::out_of_range("Invalid matrix row index");
    }

    if (values.size() != getColsNum())
    {
        throw std::invalid_argument("Invalid number of columns");
    }

    m_values[row] = values;
}

#endif /* MATRIX_HPP_ */
