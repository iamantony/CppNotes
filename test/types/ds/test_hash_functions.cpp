#include <boost/test/unit_test.hpp>
#include "types/ds/hash_functions.hpp"
#include <limits>
#include <iostream>

BOOST_AUTO_TEST_SUITE(TestHashFunctions)

    BOOST_AUTO_TEST_CASE(hash_division_method_m_is_power_of_2)
    {
        const size_t num_of_buckets = 16;
        Types::DS::HashModulo hash_func(num_of_buckets);
        std::vector<size_t> stat(num_of_buckets, 0);
        const auto max = static_cast<size_t>(std::numeric_limits<uint8_t>::max());
        for (size_t i = 0; i < max; ++i) {
            ++stat[hash_func(i)];
        }

//        std::cout << "Test of hash function that uses division method. Num of buckets is " <<
//            "power of 2: " << num_of_buckets << std::endl;
//        std::cout << "Here is statistics that shows how many numbers [0, max(uchar)] would be " <<
//            "assigned to the same bucket" << std::endl;
//        for (size_t i = 0; i < stat.size(); ++i) {
//            std::cout << i << ": " << stat[i] << std::endl;
//        }
    }

    BOOST_AUTO_TEST_CASE(hash_multiplication_method)
    {
        const size_t num_of_buckets = 16;
        Types::DS::HashMultiplication hash_func(num_of_buckets);
        std::vector<size_t> stat(num_of_buckets, 0);
        const auto max = static_cast<size_t>(std::numeric_limits<uint8_t>::max());
        for (size_t i = 0; i < max; ++i) {
            ++stat[hash_func(i)];
        }

//        std::cout << "Test of hash function that uses multiplication method. Num of buckets is " <<
//                  "power of 2: " << num_of_buckets << std::endl;
//        std::cout << "Here is statistics that shows how many numbers [0, max(uchar)] would be " <<
//                  "assigned to the same bucket" << std::endl;
//        for (size_t i = 0; i < stat.size(); ++i) {
//            std::cout << i << ": " << stat[i] << std::endl;
//        }
    }

    BOOST_AUTO_TEST_CASE(hash_multiply_shift_method)
    {
        const size_t num_of_buckets = 16;
        Types::DS::HashMultiplyShift hash_func(num_of_buckets);
        std::vector<size_t> stat(num_of_buckets, 0);
        const auto max = static_cast<int32_t>(std::numeric_limits<uint8_t>::max());
        for (int32_t i = 1; i < max; ++i) {
            ++stat[hash_func(i)];
        }

//        std::cout << "Test of hash function that uses multiply-shift method. Num of buckets is " <<
//                  "power of 2: " << num_of_buckets << std::endl;
//        std::cout << "Here is statistics that shows how many numbers [0, max(uchar)] would be " <<
//                  "assigned to the same bucket" << std::endl;
//        for (size_t i = 0; i < stat.size(); ++i) {
//            std::cout << i << ": " << stat[i] << std::endl;
//        }
    }

    BOOST_AUTO_TEST_CASE(hash_multiply_add_shift_method)
    {
        const size_t num_of_buckets = 16;
        Types::DS::HashMultiplyAddShift hash_func(num_of_buckets);
        std::vector<size_t> stat(num_of_buckets, 0);
        const auto max = static_cast<int32_t>(std::numeric_limits<uint8_t>::max());
        for (int32_t i = 1; i < max; ++i) {
            ++stat[hash_func(i)];
        }

//        std::cout << "Test of hash function that uses multiply-add-shift method. Num of buckets is " <<
//                  "power of 2: " << num_of_buckets << std::endl;
//        std::cout << "Here is statistics that shows how many numbers [0, max(uchar)] would be " <<
//                  "assigned to the same bucket" << std::endl;
//        for (size_t i = 0; i < stat.size(); ++i) {
//            std::cout << i << ": " << stat[i] << std::endl;
//        }
    }

    BOOST_AUTO_TEST_CASE(hash_vector)
    {
        const size_t num_of_buckets = 16;
        Types::DS::HashVector hash_func(num_of_buckets);
        std::vector<size_t> stat(num_of_buckets, 0);

        Types::DS::helpers::RandomGenerator size_generator(10);
        Types::DS::helpers::RandomGenerator num_generator(8);
        for (size_t i = 0; i < 100; ++i) {
            std::vector<int32_t> v(size_generator.generate(), 0);
            std::generate(
                v.begin(), v.end(), [&num_generator](){ return num_generator.generate(); });

            ++stat[hash_func(v)];
        }

//        std::cout << "Test of hash function for vectors. Num of buckets is " <<
//                  "power of 2: " << num_of_buckets << std::endl;
//        std::cout << "Here is statistics that shows how many vectors would be " <<
//                  "assigned to the same bucket" << std::endl;
//        for (size_t i = 0; i < stat.size(); ++i) {
//            std::cout << i << ": " << stat[i] << std::endl;
//        }
    }

    BOOST_AUTO_TEST_CASE(hash_string)
    {
        const size_t num_of_buckets = 16;
        Types::DS::HashString<char> hash_func(num_of_buckets);
        std::vector<size_t> stat(num_of_buckets, 0);

        Types::DS::helpers::RandomGenerator size_generator(10);
        Types::DS::helpers::RandomGenerator char_generator(1, 127);
        for (size_t i = 0; i < 100; ++i) {
            std::string s(size_generator.generate(), '0');
            std::generate(
                s.begin(), s.end(), [&char_generator](){ return char_generator.generate(); });

            ++stat[hash_func(s)];
        }

//        std::cout << "Test of hash function for vectors. Num of buckets is " <<
//                  "power of 2: " << num_of_buckets << std::endl;
//        std::cout << "Here is statistics that shows how many vectors would be " <<
//                  "assigned to the same bucket" << std::endl;
//        for (size_t i = 0; i < stat.size(); ++i) {
//            std::cout << i << ": " << stat[i] << std::endl;
//        }
    }

BOOST_AUTO_TEST_SUITE_END()
