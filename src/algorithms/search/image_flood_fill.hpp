#ifndef IMAGE_FLOOD_FILL_HPP
#define IMAGE_FLOOD_FILL_HPP

/*
https://leetcode.com/problems/flood-fill/
An image is represented by a 2-D array of integers, each integer representing the pixel value
of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill,
and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally
to the starting pixel of the same color as the starting pixel, plus any pixels connected
4-directionally to those pixels (also with the same color as the starting pixel), and so on.
Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

Note:
- The length of image and image[0] will be in the range [1, 50].
- The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
- The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

namespace Algo::Search {
    class ImageFloodFill {
    public:
        static std::vector<std::vector<int>> fill(
            const std::vector<std::vector<int>>& image,
            const size_t pixelRow,
            const size_t pixelCol,
            const int newColor)
        {
            const auto maxRow = image.size();
            if (maxRow <= 0) { return image; }

            const auto maxCol = image[0].size();
            if (maxCol <= 0) { return image; }

            if (pixelRow >= maxRow || pixelCol >= maxCol) { return image; }

            auto resultImage = image;
            const auto oldColor = image[pixelRow][pixelCol];
            const auto tempColor = std::numeric_limits<int>::min();

            std::queue<std::pair<size_t, size_t>> pixelsToColor;
            pixelsToColor.push({pixelRow, pixelCol});

            while (!pixelsToColor.empty()) {
                const auto [pRow, pCol] = pixelsToColor.front();
                pixelsToColor.pop();

                resultImage[pRow][pCol] = tempColor;

                const std::vector<std::pair<size_t, size_t>> neighbors = {
                    {pRow > 0 ? pRow - 1 : maxRow, pCol},
                    {pRow, pCol + 1},
                    {pRow + 1, pCol},
                    {pRow, pCol > 0 ? pCol - 1: maxCol}
                };

                for (auto& [nRow, nCol] : neighbors) {
                    if (nRow >= maxRow || nCol >= maxCol) { continue; }

                    if (resultImage[nRow][nCol] == oldColor) {
                        pixelsToColor.push({nRow, nCol});
                    }
                }
            }

            for (auto& row : resultImage) {
                for (auto& p : row) {
                    if (p == tempColor) { p = newColor; }
                }
            }

            return resultImage;
        }
    };
}

#endif //IMAGE_FLOOD_FILL_HPP
