#include <boost/test/unit_test.hpp>
#include "algorithms/greedy/task_scheduler.hpp"

BOOST_AUTO_TEST_SUITE(TestTaskScheduler)

    BOOST_AUTO_TEST_CASE(test)
    {
        {
            const std::vector<char> tasks = {};
            const int n = 1;
            const int expected_queue_size = 0;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A'};
            const int n = 1;
            const int expected_queue_size = 1;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A', 'B'};
            const int n = 1;
            const int expected_queue_size = 2;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A', 'A'};
            const int n = 1;
            const int expected_queue_size = 3;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A', 'B'};
            const int n = 3;
            const int expected_queue_size = 2;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A', 'A', 'B'};
            const int n = 2;
            const int expected_queue_size = 4;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A', 'A', 'B'};
            const int n = 3;
            const int expected_queue_size = 5;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
            const int n = 2;
            const int expected_queue_size = 8;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
            const int n = 1;
            const int expected_queue_size = 6;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
            const int n = 0;
            const int expected_queue_size = 6;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }

        {
            const std::vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
            const int n = 2;
            const int expected_queue_size = 16;
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_full(tasks, n));
            BOOST_CHECK(expected_queue_size == Algo::Greedy::TaskScheduler::schedule_quick(tasks, n));
        }
    }

BOOST_AUTO_TEST_SUITE_END()

