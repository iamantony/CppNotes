#include <boost/test/unit_test.hpp>
#include "algorithms/greedy/reconstruct_queue.hpp"

BOOST_AUTO_TEST_SUITE(TestReconstrunctQueue)

    BOOST_AUTO_TEST_CASE(empty_queue)
    {
        const std::vector<std::vector<int>> people;
        const std::vector<std::vector<int>> expected;
        const auto result = Algo::Greedy::ReconstructQueue::reconstruct(people);
        BOOST_CHECK(result == expected);
    }

    BOOST_AUTO_TEST_CASE(queue_with_one_person)
    {
        const std::vector<std::vector<int>> people = { {10, 0} };
        const std::vector<std::vector<int>> expected = people;
        const auto result = Algo::Greedy::ReconstructQueue::reconstruct(people);
        BOOST_CHECK(result == expected);
    }

    BOOST_AUTO_TEST_CASE(ordered_queue_with_two_person)
    {
        const std::vector<std::vector<int>> people = { {10, 0}, {4, 1} };
        const std::vector<std::vector<int>> expected = people;
        const auto result = Algo::Greedy::ReconstructQueue::reconstruct(people);
        BOOST_CHECK(result == expected);
    }

    BOOST_AUTO_TEST_CASE(unordered_queue_with_two_person)
    {
        const std::vector<std::vector<int>> people = { {4, 1}, {10, 0} };
        const std::vector<std::vector<int>> expected = { {10, 0}, {4, 1} };
        const auto result = Algo::Greedy::ReconstructQueue::reconstruct(people);
        BOOST_CHECK(result == expected);
    }

    BOOST_AUTO_TEST_CASE(unordered_queue_with_six_persons)
    {
        const std::vector<std::vector<int>> people = { {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2} };
        const std::vector<std::vector<int>> expected = { {5,0}, {7,0}, {5,2}, {6,1}, {4,4}, {7,1} };
        const auto result = Algo::Greedy::ReconstructQueue::reconstruct(people);
        BOOST_CHECK(result == expected);
    }

    BOOST_AUTO_TEST_CASE(unordered_queue_with_ten_persons)
    {
        const std::vector<std::vector<int>> people =
            { {2,4}, {3,4}, {9,0}, {0,6}, {7,1}, {6,0}, {7,3}, {2,5}, {1,1}, {8,0} };
        const std::vector<std::vector<int>> expected =
            { {6,0}, {1,1}, {8,0}, {7,1}, {9,0}, {2,4}, {0,6}, {2,5}, {3,4}, {7,3} };
        const auto result = Algo::Greedy::ReconstructQueue::reconstruct(people);
        BOOST_CHECK(result == expected);
    }

BOOST_AUTO_TEST_SUITE_END()
