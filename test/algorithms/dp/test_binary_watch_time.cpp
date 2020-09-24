#include <boost/test/unit_test.hpp>
#include "algorithms/dp/binary_watch_time.hpp"

BOOST_AUTO_TEST_SUITE(TestBinaryWatchTime)

    BOOST_AUTO_TEST_CASE(test_get_possible_time)
    {
        {
            const int num_led_on = 0;
            const std::vector<std::string> expected = {"0:00"};
            BOOST_CHECK(expected == Algo::DP::BinaryWatch::get_time(num_led_on));
        }

        {
            const int num_led_on = 1;
            auto result = Algo::DP::BinaryWatch::get_time(num_led_on);
            std::vector<std::string> expected = {
                "1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"};

            std::sort(result.begin(), result.end());
            std::sort(expected.begin(), expected.end());

            BOOST_CHECK(expected == result);
        }

        {
            const int num_led_on = -1;
            const std::vector<std::string> expected = {};
            BOOST_CHECK(expected == Algo::DP::BinaryWatch::get_time(num_led_on));
        }

        {
            const int num_led_on = 9;
            const std::vector<std::string> expected = {};
            BOOST_CHECK(expected == Algo::DP::BinaryWatch::get_time(num_led_on));
        }

        {
            const int num_led_on = 11;
            const std::vector<std::string> expected = {};
            BOOST_CHECK(expected == Algo::DP::BinaryWatch::get_time(num_led_on));
        }
    }

BOOST_AUTO_TEST_SUITE_END()


