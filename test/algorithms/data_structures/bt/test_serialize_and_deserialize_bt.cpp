#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/bt/serialize_and_deserialize_bt.hpp"

using Types::DS::NodeBT;
using Algo::DS::BT::Serializator;

BOOST_AUTO_TEST_SUITE(TestBTSerializator)

    BOOST_AUTO_TEST_CASE(empty_bt)
    {
        Serializator s;
        const std::string expected = {"n"};
        BOOST_CHECK(s.serialize(nullptr) == expected);
        BOOST_CHECK(s.deserialize("") == nullptr);
        BOOST_CHECK(s.deserialize(s.NO_NODE) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(bt_with_one_node)
    {
        NodeBT<int> root(1);
        const std::string expected = {"1,e"};

        Serializator s;
        BOOST_CHECK(s.serialize(&root) == expected);

        auto* bt_result = s.deserialize(expected);
        const std::vector<int> expected_values = {1};
        BOOST_CHECK( expected_values == Types::DS::ValuesInBT(bt_result));
        DeleteBT(&bt_result);
    }

    BOOST_AUTO_TEST_CASE(bt_with_three_levels)
    {
        /*
            3
           / \
          9  20
               \
                7
        */

        auto* root = Types::DS::CreateBT<int>({{3}, {9,20}, {0,0,0,7}}, 0);
        const std::string expected = {"3,9,e,20,n,7,e"};

        Serializator s;
        BOOST_CHECK(s.serialize(root) == expected);

        auto* bt_result = s.deserialize(expected);
        const std::vector<int> expected_values = {9,3,20,7};
        BOOST_CHECK( expected_values == Types::DS::ValuesInBT(bt_result));

        DeleteBT(&root);
        DeleteBT(&bt_result);
    }

BOOST_AUTO_TEST_SUITE_END()
