#include <boost/test/unit_test.hpp>
#include "types/ds/unordered_map_ds.hpp"
#include <limits>
#include <unordered_map>

BOOST_AUTO_TEST_SUITE(TestUnorderedMapDS)

    BOOST_AUTO_TEST_CASE(creation)
    {
        Types::DS::UnorderedMap<int32_t> map;
        BOOST_CHECK(map.size() == 0);
    }

    BOOST_AUTO_TEST_CASE(insert_same_keys)
    {
        Types::DS::UnorderedMap<int32_t> map;
        map.insert(9, 10);
        map.insert(9, 10);
        map.insert(9, 10);
        map.insert(9, 10);
        map.insert(9, 10);
        map.insert(9, 10);
        map.insert(9, 10);
        BOOST_CHECK(map.size() == 1);
        BOOST_CHECK(map.contains(9));
    }

    BOOST_AUTO_TEST_CASE(insert_several_keys)
    {
        Types::DS::UnorderedMap<int32_t> map;
        map.insert(1, 10);
        map.insert(2, 122);
        map.insert(3, 30);
        map.insert(2, 789);
        map.insert(4, 150);
        map.insert(5, 106);
        map.insert(6, 456);
        map.insert(7, 456);
        map.insert(8, 456);
        map.insert(9, 456);
        BOOST_CHECK(map.size() == 9);
        BOOST_CHECK(map.get(2) == 789);
        BOOST_CHECK(map.get(21) == -1);
    }

    BOOST_AUTO_TEST_CASE(delete_keys)
    {
        Types::DS::UnorderedMap<int32_t> map;
        map.insert(-1, 0);
        map.insert(2, 29);
        BOOST_CHECK(map.size() == 2);

        map.remove(0);
        map.remove(-1);
        BOOST_CHECK(map.size() == 1);
    }

    BOOST_AUTO_TEST_CASE(load_test)
    {
        std::mt19937 mt(321);
        std::normal_distribution<> dist(1000, 10000);

        std::unordered_map<int32_t, int32_t> std_map;
        Types::DS::UnorderedMap<int32_t> my_map;
        for (size_t i = 0; i < 100000; ++i) {
            const auto num = static_cast<int32_t>(std::round(dist(mt)));
            const auto insert_operation = (num % 7 == 0);
            if (insert_operation) {
                const auto value = static_cast<int32_t>(std::round(dist(mt)));
                my_map.insert(num, value);
                std_map.insert_or_assign(num, value);
            }
            else {
                my_map.remove(num);
                std_map.erase(num);
            }
        }

        BOOST_CHECK(my_map.size() == std_map.size());
        for (const auto& [key, value] : std_map) {
            BOOST_CHECK(my_map.contains(key));
            BOOST_CHECK(my_map.get(key) == value);
        }
    }

BOOST_AUTO_TEST_SUITE_END()
