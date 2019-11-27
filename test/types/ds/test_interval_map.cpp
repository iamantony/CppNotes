#include <boost/test/unit_test.hpp>
#include <vector>
#include <limits>
#include <iostream>
#include <random>

#include "types/ds/interval_map.hpp"

class Key {
public:
    Key() : m_key(0) {}
    Key(const size_t& key) : m_key(key) {}
    Key(const Key& other) {
        m_key = other.m_key;
    }

    Key& operator=(const Key& other) {
        m_key = other.m_key;
        return *this;
    }

    friend bool operator<(const Key& left, const Key& right) {
        return left.m_key < right.m_key;
    }

private:
    size_t m_key;
};

namespace std {
    template <>
    class numeric_limits<Key> {
    public:
       static Key lowest() { return std::numeric_limits<size_t>::lowest(); }
       static Key min() { return std::numeric_limits<size_t>::min(); }
       static Key max() { return std::numeric_limits<size_t>::max(); }
    };
}

class Value {
public:
    Value() : m_value(0) {}
    Value(const char& value) : m_value(value) {}
    Value(const Value& other) {
        m_value = other.m_value;
    }

    Value& operator=(const Value& other) {
        m_value = other.m_value;
        return *this;
    }

    friend bool operator==(const Value& left, const Value& right) {
        return left.m_value == right.m_value;
    }

private:
    char m_value;
};

BOOST_AUTO_TEST_SUITE(IntervalMap)

BOOST_AUTO_TEST_CASE(special) {
    interval_map<size_t, int> im(std::numeric_limits<int>::lowest());
    im.assign(0, 6, 9);
    im.assign(6, 9, 1);
    im.assign(9, 10, 8);
    im.assign(10, std::numeric_limits<size_t>::max(),
              std::numeric_limits<int>::max());

    // Insert in the middle, with value equal to the value of the next element
    im.assign(7, 9, 8);
    im.assign(5, 7, 2);
    BOOST_CHECK(im.checkNodes());
}

BOOST_AUTO_TEST_CASE(random_with_check_vector)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distK(0, 10);
    std::uniform_int_distribution<char> distV(std::numeric_limits<char>::min(),
                                             std::numeric_limits<char>::max());

    const Value defaultValue(distV(gen));
    std::vector<Value> v(10, defaultValue);
    interval_map<Key, Value> im(defaultValue);

    for (size_t cycle = 0; cycle < 100000; ++cycle) {
        const size_t kBegin = distK(gen);
        const size_t kEnd = distK(gen);
        const Value value(distV(gen));

        if (kBegin < kEnd && kBegin < v.size()) {
            size_t begin = kBegin;
            for (size_t i = begin - 1; i < v.size(); --i) {
                if (v[i] == value) {
                    begin = i;
                }
                else {
                    break;
                }

                if (begin == 0) {
                    break;
                }
            }

            for (size_t i = begin; i < kEnd; ++i) {
                v[i] = value;
            }
        }

        im.assign(kBegin, kEnd, value);

        for (size_t i = 0; i < v.size(); ++i) {
            BOOST_CHECK(v[i] == im[i]);
        }

        BOOST_CHECK(im.checkNodes());
    }
}


BOOST_AUTO_TEST_CASE(random_values)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distK(
        std::numeric_limits<size_t>::min(), std::numeric_limits<size_t>::max());

    std::uniform_int_distribution<char> distV(
            std::numeric_limits<char>::min(), std::numeric_limits<char>::max());

    const Value defaultValue(distV(gen));
    interval_map<Key, Value> im(defaultValue);

    for (size_t cycle = 0; cycle < 100000; ++cycle) {
        const size_t kBegin = distK(gen);
        const size_t kEnd = distK(gen);
        const Value value(distV(gen));

        im.assign(kBegin, kEnd, value);
        BOOST_CHECK(im.checkNodes());
    }
}

BOOST_AUTO_TEST_SUITE_END()
