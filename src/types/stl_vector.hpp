#ifndef STL_VECTOR_HPP
#define STL_VECTOR_HPP

#include <vector>
#include <iostream>

namespace Types {

void HowVectorGrows() {
    /*
    https://stackoverflow.com/questions/5232198/about-vectors-growth
     * To be able to provide amortized constant time insertions at the end of
     * the std::vector, the implementation must grow the size of the vector
     * (when needed) by a factor K where K > 1, such that when trying to
     * append to a vector of size N that is full, the vector grows to be K*N.

     * Different implementations use different constants K that provide
     * different benefits, in particular most implementations go for either
     * K = 2 or K = 1.5. A higher K will make it faster as it will require
     * less grows, but it will at the same time have a greater memory impact.
     * As an example, in gcc  K = 2, while in VS (Dinkumware) K = 1.5.

     * If the vector grew by a constant quantity, then the complexity of
     * push_back would become linear instead of amortized constant.
     * For example, if the vector grew by 10 elements when needed, the cost of
     * growing (copy of all element to the new memory address) would be
     * O( N / 10 ) (every 10 elements, move everything) or O( N ).
    */

    std::vector<size_t> v;
    v.shrink_to_fit();
    std::cout << "On start. Size = " << v.size() << "; capacity = " <<
                 v.capacity() << std::endl;
    for (size_t i = 1; i < 34; ++i) {
        v.push_back(i);
        std::cout << "Iteration " << i << ". Size = " << v.size() <<
                     "; capacity = " << v.capacity() << std::endl;
    }
}

void StartVector() {
    HowVectorGrows();
}

}

#endif // STL_VECTOR_HPP
