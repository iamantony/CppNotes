#ifndef FACTORIAL_HPP_
#define FACTORIAL_HPP_

// Compute factorial at runtime
class Factorial
{
    // == METHODS ==
public:
    static long long unsigned int Calc(const int& num);
};

// Compute factorial at compile-time using templates
template <unsigned int N = 1>
struct FactorialTemplate
{
    enum { value = N * FactorialTemplate<N - 1>::value };
};

template <>
struct FactorialTemplate<0>
{
    enum { value = 1 };
};

// Compute factorial at compile-time using constexpr function
constexpr unsigned int FactorialCE(unsigned int n)
{
    return (n <= 1? 1 : (n * FactorialCE(n - 1)));
}
#endif /* FACTORIAL_HPP_ */
