#include <boost/test/unit_test.hpp>
#include "types/ds/unordered_set_ds.hpp"
#include <limits>
#include <unordered_set>

BOOST_AUTO_TEST_SUITE(TestUnorderedSetDS)

    BOOST_AUTO_TEST_CASE(creation)
    {
        Types::DS::UnorderedSet set;
        BOOST_CHECK(set.size() == 0);
    }

    BOOST_AUTO_TEST_CASE(insert_same_keys)
    {
        Types::DS::UnorderedSet set;
        set.insert(9);
        set.insert(9);
        set.insert(9);
        set.insert(9);
        set.insert(9);
        set.insert(9);
        BOOST_CHECK(set.size() == 1);
        BOOST_CHECK(set.contains(9));
    }

    BOOST_AUTO_TEST_CASE(insert_several_keys)
    {
        Types::DS::UnorderedSet set;
        set.insert(1);
        set.insert(2);
        set.insert(3);
        set.insert(4);
        set.insert(5);
        set.insert(5);
        BOOST_CHECK(set.size() == 5);
    }

    BOOST_AUTO_TEST_CASE(delete_keys)
    {
        Types::DS::UnorderedSet set;
        set.insert(-1);
        set.insert(2);
        set.insert(-3);
        set.insert(-4);
        set.insert(5);
        set.insert(-5);
        BOOST_CHECK(set.size() == 6);

        set.remove(0);
        set.remove(-5);
        set.remove(2);
        BOOST_CHECK(set.size() == 4);
    }

    BOOST_AUTO_TEST_CASE(load_test)
    {
        std::mt19937 mt(321);
        std::normal_distribution<> dist(1000, 10000);

        std::unordered_set<int> std_set;
        Types::DS::UnorderedSet my_set;
        for (size_t i = 0; i < 100000; ++i) {
            const auto num = static_cast<int32_t>(std::round(dist(mt)));
            const auto insert_operation = (num % 7 == 0);
            if (insert_operation) {
                my_set.insert(num);
                std_set.insert(num);
            }
            else {
                my_set.remove(num);
                std_set.erase(num);
            }
        }

        BOOST_CHECK(my_set.size() == std_set.size());
        for (const auto& n : std_set) {
            BOOST_CHECK(my_set.contains(n));
        }
    }

BOOST_AUTO_TEST_SUITE_END()
