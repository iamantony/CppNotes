#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/hashmap/bulls_and_cows_game.hpp"

BOOST_AUTO_TEST_SUITE(TestBullsAndCowsGame)

    BOOST_AUTO_TEST_CASE(empty_input)
    {
        BOOST_CHECK("0A0B" == Algo::DS::HashMap::BullsAndCows::play({}, {}));
    }

    BOOST_AUTO_TEST_CASE(valid_input_no_hint)
    {
        BOOST_CHECK("0A0B" == Algo::DS::HashMap::BullsAndCows::play("1", "2"));
        BOOST_CHECK("0A0B" == Algo::DS::HashMap::BullsAndCows::play("13", "2"));
        BOOST_CHECK("0A0B" == Algo::DS::HashMap::BullsAndCows::play("1", "29"));
        BOOST_CHECK("0A0B" == Algo::DS::HashMap::BullsAndCows::play("123", "590"));
    }

    BOOST_AUTO_TEST_CASE(valid_input_with_hint)
    {
        BOOST_CHECK("1A0B" == Algo::DS::HashMap::BullsAndCows::play("123", "92"));
        BOOST_CHECK("3A0B" == Algo::DS::HashMap::BullsAndCows::play("123", "123"));
        BOOST_CHECK("0A2B" == Algo::DS::HashMap::BullsAndCows::play("123", "31"));
        BOOST_CHECK("1A3B" == Algo::DS::HashMap::BullsAndCows::play("1807", "7810"));
        BOOST_CHECK("1A1B" == Algo::DS::HashMap::BullsAndCows::play("1123", "0111"));
        BOOST_CHECK("1A1B" == Algo::DS::HashMap::BullsAndCows::play("12345", "10159"));
        BOOST_CHECK("1A0B" == Algo::DS::HashMap::BullsAndCows::play("11", "10"));
        BOOST_CHECK("3A0B" == Algo::DS::HashMap::BullsAndCows::play("1122", "1222"));
    }

BOOST_AUTO_TEST_SUITE_END()
