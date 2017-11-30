#ifndef TEST_HAMMING_DISTANCE_OF_ARRAY_HPP
#define TEST_HAMMING_DISTANCE_OF_ARRAY_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/hamming_distance_of_array.hpp"

BOOST_AUTO_TEST_CASE(test_hdoa_vector_empty)
{
    HammingDistanceOfArray::Solution solution;
    BOOST_CHECK(0 == solution.totalHammingDistance(std::vector<int>()));
}

BOOST_AUTO_TEST_CASE(test_hdoa_vector_one_elem)
{
    HammingDistanceOfArray::Solution solution;
    BOOST_CHECK(0 == solution.totalHammingDistance({1}));
}

BOOST_AUTO_TEST_CASE(test_hdoa_vector_two_elements)
{
    HammingDistanceOfArray::Solution solution;
    BOOST_CHECK(2 == solution.totalHammingDistance({1, 2}));
}

BOOST_AUTO_TEST_CASE(test_hdoa_vector_leetcode_base_cases)
{
    HammingDistanceOfArray::Solution solution;
    BOOST_CHECK(6 == solution.totalHammingDistance({4, 14, 2}));
    BOOST_CHECK(4 == solution.totalHammingDistance({4, 14, 4}));
}

BOOST_AUTO_TEST_CASE(test_hdoa_vector_leetcode_long_vector)
{
    std::vector<int> nums = {
        346450570,966562973,457581303,222998192,364627507,169160189,954431542,
        221061882,240341464,2245441,231904888,735611889,365662644,741343641,
        855432971,6410579,954376059,436042748,1757003,612662010,619293283,
        756454019,412485671,362438559,34216799,142080553,739017385,767259094,
        477271201,645653662,266228943,301408300,648353405,543652957,779813961,
        33523464,581122512,963411206,25440862,235321881,537459840,564290176,
        530181458,643091781,951346494,264772743,242353595,253371384,100262534,
        923703199,520381430,497283426,629165236,170643624,116719823,850474028,
        58812742,416255752,301680516,135541845,719123095,56870927,992425752,
        194127615,675165512,203169436,169712122,493351238,319895999,340486752,
        309900187,844598934,307377068,388210841,397263679,76973008,693168540,
        777845383,514392792,423470900,514610142,136010125,792549045,323715552,
        111204613,498136379,79844425,353928756,743878480,863304173,946695057,
        190460954,119598426,632009346,519938738,292388501,523930549,810762921,
        501651610,30789726,732344533,285785174,63479657,750706287,447118062,
        460965759,123491715,56051003,96864966,216879136,807889793,812134617,
        933426165,725513820,298625074,322335679,541999219,548221737,257888129,
        496763035,472888287,143945709,667418150,989758769,467300921,578882168,
        171676666,92166119,138726055,549049390,928845149,41789200,916910409,
        170593191,269092392,35271762,107017362,196990595,194125069,632374890,
        428207227,661163092,87697666,553869198,330979619,791810803,8005562,
        405494420,972083587,546238911,144786252,323565313,733621387,271033882,
        246618065,59358323,995901031,414061877,83929037,284525936,374303061,
        931944164,587326777,11794358,659279382,640438401,453145421,831057063,
        135396331,66447875,97938685,83005193,144370426,363185828,708665000,
        381327316,669975942,821874551,423739731,530864043,230395994,352455617,
        961656493,598750529,91771061,502963681,814951975,247143259,503380715,
        381591472,814678540,739467086,735449213,926534406,652815823,174563216,
        214288088,2797575,567181369,84843397,619788927,142303070,538398379,
        158445973,121745931,779430373,29010889,900202132,674939409,698023609,
        127116549,287567434,100636066,759204582,751062847,997371041,705221252,
        484313149,681051691,140910705,404734872,298283655,819536065,775511175,
        938064582,373977047,540572738,550180756,616360688,860453735,284023825};

    HammingDistanceOfArray::Solution solution;
    BOOST_CHECK(397592 == solution.totalHammingDistance(nums));
}

BOOST_AUTO_TEST_CASE(test_hdoa_vector_leetcode_many_same_elements)
{
    std::vector<int> nums = {
        0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911,
        0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911,
        0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911,
        0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911,
        0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911,
        0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911,
        0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911, 0, 536870911};

    HammingDistanceOfArray::Solution solution;
    BOOST_CHECK(35525 == solution.totalHammingDistance(nums));
}

#endif // TEST_HAMMING_DISTANCE_OF_ARRAY_HPP
