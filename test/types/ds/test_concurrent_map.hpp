#ifndef TEST_CONCURRENT_MAP_H_
#define TEST_CONCURRENT_MAP_H_

#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <thread>
#include <iostream>
#include <chrono>

#include "types/ds/concurrent_map.hpp"

BOOST_AUTO_TEST_CASE(test_cm_create)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_cm_insert)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    BOOST_CHECK(false == map.isEmpty());
    BOOST_CHECK(1 == map.size());
    BOOST_CHECK("one" == map.at("1"));
}

BOOST_AUTO_TEST_CASE(test_cm_double_insert)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    BOOST_CHECK(false == map.insert("1", "one"));
}

BOOST_AUTO_TEST_CASE(test_cm_set)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    map.set("1", "oneone");
    BOOST_CHECK("oneone" == map.at("1"));
}

BOOST_AUTO_TEST_CASE(test_cm_set_new_key)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    map.set("2", "two");
    BOOST_CHECK(false == map.isEmpty());
    BOOST_CHECK(2 == map.size());
    BOOST_CHECK("one" == map.at("1"));
    BOOST_CHECK("two" == map.at("2"));
}

BOOST_AUTO_TEST_CASE(test_cm_keys)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    BOOST_CHECK(map.insert("2", "two"));
    BOOST_CHECK(map.insert("3", "three"));

    std::vector<std::string> keys = map.keys();
    BOOST_CHECK(1 == std::count(keys.begin(), keys.end(), "1"));
    BOOST_CHECK(1 == std::count(keys.begin(), keys.end(), "2"));
    BOOST_CHECK(1 == std::count(keys.begin(), keys.end(), "3"));
}

BOOST_AUTO_TEST_CASE(test_cm_contains)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    BOOST_CHECK(map.insert("2", "two"));
    BOOST_CHECK(map.insert("3", "three"));
    BOOST_CHECK(map.contains("3"));
    BOOST_CHECK(map.contains("1"));
    BOOST_CHECK(map.contains("2"));
}

BOOST_AUTO_TEST_CASE(test_cm_erase)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    BOOST_CHECK(map.insert("2", "two"));
    BOOST_CHECK(map.insert("3", "three"));

    map.erase("2");
    BOOST_CHECK(map.contains("3"));
    BOOST_CHECK(map.contains("1"));
    BOOST_CHECK(false == map.contains("2"));
}

BOOST_AUTO_TEST_CASE(test_cm_clear)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    BOOST_CHECK(map.insert("2", "two"));
    BOOST_CHECK(map.insert("3", "three"));

    map.clear();
    BOOST_CHECK(map.isEmpty());
    BOOST_CHECK(0 == map.size());
    BOOST_CHECK(false == map.contains("3"));
    BOOST_CHECK(false == map.contains("1"));
    BOOST_CHECK(false == map.contains("2"));
}

BOOST_AUTO_TEST_CASE(test_cm_at_invalid_key)
{
    DS::ConcurrentMap map;
    BOOST_CHECK(map.insert("1", "one"));
    BOOST_CHECK(string() == map.at("2"));
}

BOOST_AUTO_TEST_CASE(test_cm_threads_insert)
{
    DS::ConcurrentMap map;

    auto firstFunc = [](DS::ConcurrentMap& t_map) {
        t_map.insert("1", "one");
        t_map.insert("2", "two");
        t_map.insert("3", "three");
    };

    auto secondFunc = [](DS::ConcurrentMap& t_map) {
        t_map.insert("4", "four");
        t_map.insert("2", "two");
        t_map.insert("1", "oneone");
    };

    std::thread t1(firstFunc, std::ref(map));
    std::thread t2(secondFunc, std::ref(map));

    t1.join();
    t2.join();

    BOOST_CHECK(4 == map.size());
    BOOST_CHECK("one" == map.at("1"));
    BOOST_CHECK("two" == map.at("2"));
    BOOST_CHECK("three" == map.at("3"));
    BOOST_CHECK("four" == map.at("4"));
}

BOOST_AUTO_TEST_CASE(test_cm_threads_work)
{
    DS::ConcurrentMap map;

    auto insertFunc = [](DS::ConcurrentMap& t_map,
            const int t_iterations,
            const int t_sleep)
    {
        for (int i = 0; i < t_iterations; ++i)
        {
            string value = std::to_string(std::rand() % 1000);
            t_map.insert(value, value);
            std::this_thread::sleep_for(std::chrono::milliseconds(t_sleep));
        }
    };

    auto readFunc = [](DS::ConcurrentMap& t_map,
            const int t_iterations,
            const int t_sleep)
    {
        for (int i = 0; i < t_iterations; ++i)
        {
            string value = std::to_string(std::rand() % 100);
            t_map.at(value);
            std::this_thread::sleep_for(std::chrono::milliseconds(t_sleep));
        }
    };

    auto setFunc = [](DS::ConcurrentMap& t_map,
            const int t_iterations,
            const int t_sleep)
    {
        for (int i = 0; i < t_iterations; ++i)
        {
            string value = std::to_string(std::rand() % 100);
            t_map.set(value, string());
            std::this_thread::sleep_for(std::chrono::milliseconds(t_sleep));
        }
    };

    auto eraseFunc = [](DS::ConcurrentMap& t_map,
            const int t_iterations,
            const int t_sleep)
    {
        for (int i = 0; i < t_iterations; ++i)
        {
            string value = std::to_string(std::rand() % 100);
            t_map.erase(value);
            std::this_thread::sleep_for(std::chrono::milliseconds(t_sleep));
        }
    };

    std::thread t1(insertFunc, std::ref(map), 1000, 1);
    std::thread t2(readFunc, std::ref(map), 100, 3);
    std::thread t3(setFunc, std::ref(map), 200, 2);
    std::thread t4(eraseFunc, std::ref(map), 200, 2);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << map.size() << std::endl;
}

#endif /* TEST_LINKED_LIST_H_ */
