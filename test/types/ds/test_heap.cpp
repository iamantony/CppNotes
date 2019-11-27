#include <boost/test/unit_test.hpp>

#include "types/ds/heap.hpp"

BOOST_AUTO_TEST_SUITE(DSHeap)

BOOST_AUTO_TEST_CASE(create_empty_heap)
{
    {
        Types::DS::Heap<int> ds_heap(std::vector<int>(), Types::DS::Heap<int>::Type::MAX);
        BOOST_CHECK(ds_heap.size() == 0);
        BOOST_CHECK(ds_heap.isEmpty());
    }

    {
        Types::DS::Heap<int> heap(std::vector<int>(), Types::DS::Heap<int>::Type::MIN);
        BOOST_CHECK(heap.size() == 0);
        BOOST_CHECK(heap.isEmpty());
    }
}

BOOST_AUTO_TEST_CASE(create_with_one_elem)
{
    std::vector<int> data = {1};

    {
        Types::DS::Heap<int> heap(data, Types::DS::Heap<int>::Type::MAX);
        BOOST_CHECK(1 == heap.size());
        BOOST_CHECK(false == heap.isEmpty());
        BOOST_CHECK(1 == heap.at(0));
    }

    {
        Types::DS::Heap<int> heap(data, Types::DS::Heap<int>::Type::MIN);
        BOOST_CHECK(1 == heap.size());
        BOOST_CHECK(1 == heap.at(0));
    }
}

BOOST_AUTO_TEST_CASE(create_with_several_elem)
{
    std::vector<int> data = {3, 2, 10, 15, 1};

    {
        std::vector<int> expected = {15, 3, 10, 2, 1};
        Types::DS::Heap<int> heap(data, Types::DS::Heap<int>::Type::MAX);
        BOOST_CHECK(expected == heap.exportData());
    }

    {
        std::vector<int> expected = {1, 2, 10, 15, 3};
        Types::DS::Heap<int> heap(data, Types::DS::Heap<int>::Type::MIN);
        BOOST_CHECK(expected == heap.exportData());
    }
}

BOOST_AUTO_TEST_SUITE_END()
