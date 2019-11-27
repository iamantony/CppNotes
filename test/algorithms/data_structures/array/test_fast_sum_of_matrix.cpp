#include <limits>
#include <random>
#include <iostream>
#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/array/fast_sum_of_matrix.hpp"

BOOST_AUTO_TEST_SUITE(TestFastSumOfMatrices)

BOOST_AUTO_TEST_CASE(small_matrix) {
    std::vector<std::vector<int>> matrix {
        {3, 31, -7}, {-46, -1,  -38}, {-3, 38, -40}, {16, 37, -26}
    };

    Algo::DS::Array::NumMatrix nm(matrix);

    BOOST_CHECK(-45 == nm.sumRegion(0, 2, 1, 2));
}

BOOST_AUTO_TEST_CASE(rand_tests) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<size_t> sizeDist(1, 10);
    std::uniform_int_distribution<int> valuesDist(-50, 50);

    for (size_t i = 0; i < 10; ++i) {
        std::vector<std::vector<int>> matrix(sizeDist(gen));
        const size_t colsNum = sizeDist(gen);

        for (size_t r = 0; r < matrix.size(); ++r) {
            matrix[r] = std::vector<int>(colsNum, 0);
            for (size_t c = 0; c < colsNum; ++c) {
                matrix[r][c] = valuesDist(gen);
            }
        }

        Algo::DS::Array::NumMatrix nm(matrix);

        std::uniform_int_distribution<int> rowsDist(
                    0, static_cast<int>(matrix.size() - 1));

        std::uniform_int_distribution<int> colsDist(
                    0, static_cast<int>(colsNum - 1));

        for (size_t j = 0; j < 100; ++j) {
            int r1 = rowsDist(gen);
            int c1 = colsDist(gen);

            std::uniform_int_distribution<int> secondRowDist(
                        r1, static_cast<int>(matrix.size() - 1));

            std::uniform_int_distribution<int> secondColDist(
                        c1, static_cast<int>(colsNum - 1));

            int r2 = secondRowDist(gen);
            int c2 = secondColDist(gen);

            int expected = 0;
            for (size_t rIter = static_cast<size_t>(r1);
                 rIter <= static_cast<size_t>(r2);
                 ++rIter)
            {
                for (size_t cIter = static_cast<size_t>(c1);
                     cIter <= static_cast<size_t>(c2);
                     ++cIter) {
                    expected += matrix[rIter][cIter];
                }

            }

            int result = nm.sumRegion(r1, c1, r2, c2);
            BOOST_CHECK(expected == result);
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
