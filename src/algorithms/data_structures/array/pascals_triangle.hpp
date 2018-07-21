#ifndef PASCALS_TRIANGLE_HPP
#define PASCALS_TRIANGLE_HPP

/*
// https://leetcode.com/problems/pascals-triangle/description/
Given a non-negative integer numRows, generate the first numRows of
Pascal's triangle.

Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

https://leetcode.com/problems/pascals-triangle-ii/description/
Given a non-negative index k where k ≤ 33, return the kth index row of the
Pascal's triangle.

Note that the row index starts from 0.

Example:
Input: 3
Output: [1,3,3,1]

Follow up: Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>

namespace Algo::DS::Array {

class PascalsTriangle {
public:
    static std::vector<std::vector<int>> Generate(const int& numRows) {
        std::vector<std::vector<int>> result;
        if (numRows <= 0) {
            return result;
        }

        // First row
        result.push_back( {1} );

        for (size_t i = 1; i < static_cast<size_t>(numRows); ++i) {
            const size_t elementsNum = i + 1;
            std::vector<int> elements(elementsNum, 1);

            const size_t prevRow = i - 1;
            for (size_t j = 1; j < result[prevRow].size(); ++j) {
                elements[j] = result[prevRow][j - 1] + result[prevRow][j];
            }

            result.push_back(elements);
        }

        return result;
    }

    static std::vector<int> GenerateRow(const int& rowIndex) {
        if (rowIndex < 0) {
            return std::vector<int>();
        }

        const size_t index = static_cast<size_t>(rowIndex);
        std::vector<int> result(index + 1, 0);
        result[0] = 1;
        if (index == 0) {
            return result;
        }

        result[1] = 1;
        if (index == 1) {
            return result;
        }

        for(size_t i = 2; i <= index; ++i)
        {
            for(size_t j = i; j > 0; --j) {
                result[j] += result[j - 1];
            }
        }

        return result;
    }
};

}

#endif // PASCALS_TRIANGLE_HPP
