#ifndef TEST_HEAP_HPP
#define TEST_HEAP_HPP

#include <boost/test/unit_test.hpp>

#include "types/ds/heap.hpp"

using namespace Types::DS;

BOOST_AUTO_TEST_CASE(test_heapds_create_empty_heap)
{
    {
        Heap<int> heap(std::vector<int>(), Heap<int>::Type::MAX);
        BOOST_CHECK(heap.size() == 0);
        BOOST_CHECK(heap.isEmpty());
    }

    {
        Heap<int> heap(std::vector<int>(), Heap<int>::Type::MIN);
        BOOST_CHECK(heap.size() == 0);
        BOOST_CHECK(heap.isEmpty());
    }
}

BOOST_AUTO_TEST_CASE(test_heapds_create_with_one_elem)
{
    std::vector<int> data = {1};

    {
        Heap<int> heap(data, Heap<int>::Type::MAX);
        BOOST_CHECK(1 == heap.size());
        BOOST_CHECK(false == heap.isEmpty());
        BOOST_CHECK(1 == heap.at(0));
    }

    {
        Heap<int> heap(data, Heap<int>::Type::MIN);
        BOOST_CHECK(1 == heap.size());
        BOOST_CHECK(1 == heap.at(0));
    }
}

BOOST_AUTO_TEST_CASE(test_heapds_create_with_several_elem)
{
    std::vector<int> data = {3, 2, 10, 15, 1};

    {
        std::vector<int> expected = {15, 3, 10, 2, 1};
        Heap<int> heap(data, Heap<int>::Type::MAX);
        BOOST_CHECK(expected == heap.exportData());
    }

    {
        std::vector<int> expected = {1, 2, 10, 15, 3};
        Heap<int> heap(data, Heap<int>::Type::MIN);
        BOOST_CHECK(expected == heap.exportData());
    }
}

#endif // TEST_HEAP_HPP

