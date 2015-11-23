#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <string>

template <class T>
class Matrix
{
    // == METHODS ==
public:
    Matrix() : m_width(0), m_height(0), m_matrix() {}
    virtual ~Matrix() {}

    // Setup matrix by values in string
    bool SetData(const int &t_width,
                 const int &t_height,
                 const std::string &t_str,
                 const char &t_delimiter);

    T At(const int &t_width, const int &t_height) const;
    int GetWidth() const;
    int GetHeight() const;

private:
    void Clear();
    std::vector<std::string> Split(const std::string &t_str,
                                   const char &t_delimiter) const;

    void FillMatrix(const std::vector<std::string> &t_elements);
    bool ValidatePosition(const int &t_width, const int &t_height) const;

    // == DATA ==
private:
    int m_width;
    int m_height;
    std::vector<T> m_matrix;
};

#endif /* MATRIX_H_ */
