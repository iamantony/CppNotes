#ifndef QSORT_VS_SORT_HPP
#define QSORT_VS_SORT_HPP

#include <cstdlib>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <functional>

// http://www.geeksforgeeks.org/c-qsort-vs-c-sort/
// Main idea: qsort is slower than std::sort

// Comparison to qsort and sort()
// 1. Implementation details:
// As the name suggests, qsort function uses QuickSort algorithm to sort
// the given array, although the C standard does not require it to implement
// quicksort.

// C++ sort function uses introsort which is a hybrid algorithm. Different
// implementations use different algorithms. The GNU Standard C++ library,
// for example, uses a 3-part hybrid sorting algorithm: introsort is performed
// first (introsort itself being a hybrid of quicksort and heap sort) followed
// by an insertion sort on the result.

// 2. Complexity :
// The C standard doesn’t talk about its complexity of qsort. The new C++11
// standard requires that the complexity of sort to be O(Nlog(N)) in the worst
// case. Previous versions of C++ such as C++03 allow possible worst case
// scenario of O(N^2). Only average complexity was required to be O(N log N).

// 3. Running time:
// STL’s sort ran faster than C’s qsort, because C++’s templates generate
// optimized code for a particular data type and a particular comparison
// function.

// 4. Flexibility:
// STL’s sort works for all data types and for different data containers like
// C arrays, C++ vectors, C++ deques, etc and other containers that can be
// written by the user. This kind of flexibility is rather difficult to
// achieve in C.

// 5. Safety:
// Compared to qsort, the templated sort is more type-safe since it does not
// require access to data items through unsafe void pointers, as qsort does.

// During test I found out that if we forbid inlining via compiler flags,
// std::sort will run slower than qsort (sometimes 2-3 times slower). So
// be carefull and benchmark your code!

namespace {

const size_t numOfElements = 100000000;

void SortIntegers() {
    std::cout << "Going to test how fast algorithms could sort integers"
              << std::endl;

    // Prepare vector that will contain numbers to sort
    std::vector<int> v(numOfElements);

    // Setup random numbers generator
    std::random_device rnd_device;
    std::mt19937 mersenne_engine(rnd_device());
    std::uniform_int_distribution<int> dist(0, 1000000);

    // Fill container with random numbers
    auto gen = std::bind(dist, mersenne_engine);
    std::generate(v.begin(), v.end(), gen);

    {
        std::vector<int> numbers(v);

        auto start = std::chrono::high_resolution_clock::now();
        std::qsort(numbers.data(), numbers.size(), sizeof(int),
                   [](const void* a, const void* b) {
                        int arg1 = *static_cast<const int*>(a);
                        int arg2 = *static_cast<const int*>(b);

                        if(arg1 < arg2) return -1;
                        if(arg1 > arg2) return 1;
                        return 0;
                    }
        );

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "qsort time: " << elapsed.count() << std::endl;
        if (!std::is_sorted(numbers.begin(), numbers.end())) {
            std::cout << "Failed to sort numbers with qsort" << std::endl;
        }
    }

    {
        std::vector<int> numbers(v);

        auto start = std::chrono::high_resolution_clock::now();
        std::sort(numbers.begin(), numbers.end());
        auto finish = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "STL sort time: " << elapsed.count() << std::endl;
        if (!std::is_sorted(numbers.begin(), numbers.end())) {
            std::cout << "Failed to sort numbers with STL sort" << std::endl;
        }
    }
}

void SortDoubles() {
    std::cout << "Going to test how fast algorithms could sort doubles"
              << std::endl;

    // Prepare vector that will contain numbers to sort

    std::vector<double> v(numOfElements);

    // Setup random numbers generator
    std::random_device rnd_device;
    std::mt19937 mersenne_engine(rnd_device());
    std::uniform_real_distribution<double> dist(0.0, 1000000.0);

    // Fill container with random numbers
    auto gen = std::bind(dist, mersenne_engine);
    std::generate(v.begin(), v.end(), gen);

    {
        std::vector<double> numbers(v);

        auto start = std::chrono::high_resolution_clock::now();
        std::qsort(numbers.data(), numbers.size(), sizeof(double),
                   [](const void* a, const void* b) {
                        double arg1 = *static_cast<const double*>(a);
                        double arg2 = *static_cast<const double*>(b);

                        if(arg1 < arg2) return -1;
                        if(arg1 > arg2) return 1;
                        return 0;
                    }
        );

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "qsort time: " << elapsed.count() << std::endl;
        if (!std::is_sorted(numbers.begin(), numbers.end())) {
            std::cout << "Failed to sort numbers with qsort" << std::endl;
        }
    }

    {
        std::vector<double> numbers(v);

        auto start = std::chrono::high_resolution_clock::now();
        std::sort(numbers.begin(), numbers.end());
        auto finish = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "STL sort time: " << elapsed.count() << std::endl;
        if (!std::is_sorted(numbers.begin(), numbers.end())) {
            std::cout << "Failed to sort numbers with STL sort" << std::endl;
        }
    }
}

}

void CompareQsortAndSort() {
    SortIntegers();
    SortDoubles();
}

#endif // QSORT_VS_SORT_HPP
