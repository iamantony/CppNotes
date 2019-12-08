#include <boost/test/unit_test.hpp>
#include "types/ds/priority_queue.hpp"

BOOST_AUTO_TEST_SUITE(DSPriorityQueue)

BOOST_AUTO_TEST_CASE(create_empty_pq) {
    {
        Types::DS::PriorityQueue<int> pq(Types::DS::PriorityQueue<int>::Type::MAX);
        BOOST_CHECK(pq.size() == 0);
        BOOST_CHECK(pq.isEmpty());
    }

    {
        Types::DS::PriorityQueue<int> pq(Types::DS::PriorityQueue<int>::Type::MIN);
        BOOST_CHECK(pq.size() == 0);
        BOOST_CHECK(pq.isEmpty());
    }
}

BOOST_AUTO_TEST_CASE(insert_elements_in_pq) {
    Types::DS::PriorityQueue<int> pq(Types::DS::PriorityQueue<int>::Type::MAX);
    pq.insert(10, 200);
    BOOST_CHECK(pq.top() == 10);

    pq.insert(9, 210);
    BOOST_CHECK(pq.top() == 9);

    pq.insert(1, 210);
    BOOST_CHECK(pq.top() == 9);

    pq.insert(20, 150);
    BOOST_CHECK(pq.top() == 9);

    pq.insert(10, 180);
    BOOST_CHECK(pq.top() == 9);

    pq.insert(15, 205);
    BOOST_CHECK(pq.top() == 9);
}

BOOST_AUTO_TEST_CASE(pop_elements_from_pq) {
    Types::DS::PriorityQueue<int> pq(Types::DS::PriorityQueue<int>::Type::MAX);
    pq.insert(10, 200);
    pq.insert(9, 210);
    pq.insert(1, 210);
    pq.insert(20, 150);
    pq.insert(10, 180);
    pq.insert(15, 205);

    BOOST_CHECK(pq.top() == 9);

    pq.pop();
    BOOST_CHECK(pq.top() == 1);

    pq.pop();
    BOOST_CHECK(pq.top() == 15);

    pq.pop();
    BOOST_CHECK(pq.top() == 10);

    pq.pop();
    BOOST_CHECK(pq.top() == 10);

    pq.pop();
    BOOST_CHECK(pq.top() == 20);

    pq.pop();
    BOOST_CHECK(pq.isEmpty());
}

BOOST_AUTO_TEST_CASE(change_priority_in_pq) {
    Types::DS::PriorityQueue<int> pq(Types::DS::PriorityQueue<int>::Type::MAX);
    pq.insert(10, 200);
    pq.insert(9, 210);
    pq.insert(1, 210);
    pq.insert(20, 150);
    pq.insert(10, 180);
    pq.insert(15, 205);

    pq.setPriority(10, 300);
    pq.setPriority(1, 140);

    BOOST_CHECK(pq.top() == 10);

    pq.pop();
    BOOST_CHECK(pq.top() == 10);

    pq.pop();
    BOOST_CHECK(pq.top() == 9);

    pq.pop();
    BOOST_CHECK(pq.top() == 15);

    pq.pop();
    BOOST_CHECK(pq.top() == 20);

    pq.pop();
    BOOST_CHECK(pq.top() == 1);

    pq.pop();
    BOOST_CHECK(pq.isEmpty());
}

BOOST_AUTO_TEST_SUITE_END()
