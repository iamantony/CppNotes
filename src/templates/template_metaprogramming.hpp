#ifndef TEMP_METAPROG_H_
#define TEMP_METAPROG_H_

#include <iostream>

#include "functemplate.hpp"

using namespace std;

class Currency
{
public:
    int m_dollars;
    int m_cents;

    Currency() : m_dollars(0), m_cents(0) {}

    double GetValue()
    {
        return static_cast<double>(m_dollars) +
                static_cast<double>(m_cents) / 100.0;
    }

    friend ostream& operator << (ostream &out, Currency& t_currency)
    {
        out << t_currency.GetValue();
        return out;
    }

    double operator* (int t_multiplier)
    {
        return GetValue() * t_multiplier;
    }

    operator double()
    {
        return GetValue();
    }

    Currency operator + (Currency t_other)
    {
        Currency result;
        result.m_dollars = this->m_dollars + t_other.m_dollars;
        result.m_cents = this->m_cents + t_other.m_cents;

        return result;
    }

    Currency operator += (Currency t_other)
    {
        this->m_dollars += t_other.m_dollars;
        this->m_cents += t_other.m_cents;

        return *this;
    }

    //Currency& operator [] (int t_element)
    //{
    //    return this[t_element];
    //}
    //
    //const Currency& operator [] (int t_element) const
    //{
    //    return this[t_element];
    //}
};

template <class T>
void Display(T t_value)
{
    cout << t_value;
    cout << endl;
}

template <class T>
void PrintDouble(T t_value)
{
    cout << t_value * 2;
    cout << endl;
}

template <class T>
T Add(T t_value1, T t_value2)
{
    return t_value1 + t_value2;
}

template <class T>
double GetAverage(T tArray[], int nElements)
{
    T tSum = T();
    for (int nIndex = 0; nIndex < nElements; ++nIndex)
    {
        tSum += tArray[nIndex];
    }

    return double(tSum) / nElements;
}

void TemplateMetaprogrammingExamples()
{
    Display("Phase One:");

    Currency dollars;
    dollars.m_dollars = 10;
    dollars.m_cents = 56;

    Display(dollars);
    PrintDouble(dollars);

    Currency dollars2;
    dollars2.m_dollars = 1;
    dollars2.m_cents = 0;

    Currency dollarsSumm = Add(dollars, dollars2);
    Display(dollarsSumm);

    Currency dollarsArray[3] = {dollars, dollars2, dollarsSumm};
    double average = GetAverage(dollarsArray, 3);
    Display(average);

    Display("\nPhase Two:");
    DisplayTwice(42);
}

#endif /* TEMP_METAPROG_H_ */
