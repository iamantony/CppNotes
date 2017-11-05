#ifndef ROTATE_MATRIX_HPP_
#define ROTATE_MATRIX_HPP_

// Given an image represented by an NxN matrix, where each pixel in the image
// is 4 bytes, write a method to rotate the image by 90 degrees. Can you do
// this in place?

template<typename T>
void RotateMatrix(T** array, const int& size)
{
    if (nullptr == array || size <= 1)
    {
        return;
    }

    const int layersNum = size / 2;
    for (int ln = 0; ln < layersNum; ++ln)
    {
        const int start = ln;
        const int end = size - ln - 1;
        for (int i = start; i < end; ++i)
        {
            const int offset = i - start;

            T topElem = array[start][i];

            // top = left
            array[start][i] = array[end - offset][start];

            // left = bottom
            array[end - offset][start] = array[end][end - offset];

            // bottom = right
            array[end][end - offset] = array[i][end];

            // right = top
            array[i][end] = topElem;
        }
    }
}

#endif /* ROTATE_MATRIX_HPP_ */
