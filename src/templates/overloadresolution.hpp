#ifndef OVERLOADRESOLUTION_H_
#define OVERLOADRESOLUTION_H_

#include <iostream>
#include <string>

using namespace std;

void meow (const string &str)
{
    cout << "Its'a string: " << str << endl;
}

template <int N>
void meow(const char (&arr)[N])
{
    cout << "This is char array size " << N << " with info " << arr << endl;
}

template <typename T>
void foo(const T& t)
{
    cout << "foo(const T& t): " << t << endl;
}

template <typename T>
void foo(const T* t)
{
    cout << "foo(const T* t): " << t << endl;
}

void StartOR()
{
    meow("purr");
    string str("cat");
    meow(str);

    const int *cp = NULL;
    int *p = NULL;
    foo(cp);
    foo(p);
    foo(42);
}

#endif /* OVERLOADRESOLUTION_H_ */
