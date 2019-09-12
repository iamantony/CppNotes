#ifndef TEST_PARTITION_EQUALLY_HPP
#define TEST_PARTITION_EQUALLY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/partition_equally.hpp"

BOOST_AUTO_TEST_CASE(test_parteq_test)
{
    {
        const std::vector<uint32_t> elements = { 2, 1, 4, 5, 3, 3 };
        const uint32_t numOfPartitions = 3;
        BOOST_CHECK(
            Algo::Math::PartitionEqually::CanPartition(elements, numOfPartitions));
    }

    {
        const std::vector<uint32_t> elements = { 3, 3, 3, 3 };
        const uint32_t numOfPartitions = 3;
        BOOST_CHECK(
            false == Algo::Math::PartitionEqually::CanPartition(elements, numOfPartitions));
    }

    {
        const std::vector<uint32_t> elements = { 40 };
        const uint32_t numOfPartitions = 3;
        BOOST_CHECK(
            false == Algo::Math::PartitionEqually::CanPartition(elements, numOfPartitions));
    }

    {
        const std::vector<uint32_t> elements =
            { 17, 59, 34, 57, 17, 23, 67, 1, 18, 2, 59 };
        const uint32_t numOfPartitions = 3;
        BOOST_CHECK(
            Algo::Math::PartitionEqually::CanPartition(elements, numOfPartitions));
    }

    {
        const std::vector<uint32_t> elements =
            { 1, 2, 3, 4, 5, 5, 7, 7, 8, 10, 12, 19, 25 };
        const uint32_t numOfPartitions = 3;
        BOOST_CHECK(
            Algo::Math::PartitionEqually::CanPartition(elements, numOfPartitions));
    }
}

#endif // TEST_PARTITION_EQUALLY_HPP
