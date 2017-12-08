#ifndef BITWISE_OPERATORS_HPP
#define BITWISE_OPERATORS_HPP

namespace BitwiseOperators {

int BitwiseAdd(int a, int b) {
    // Iterate till there is no carry
    while(b != 0) {
        // carry now contains common set bits of a and b
        int carry = a & b;

        // Sum of bits of a and b where at least one of the bits is not set
        a = a ^ b;

        // Carry is shifted by one so that adding it to a gives the required sum
        b = carry << 1;
    }

    return a;
}

int BitwiseAddRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }

    return BitwiseAddRecursive(a ^ b, (a & b) << 1);
}

// http://graphics.stanford.edu/~seander/bithacks.html#IntegerAbs
// https://stackoverflow.com/a/12041874/1536843
int BitwiseAbs(int a) {
//    std::cout << "Value: " << a << ", as hex = " << std::hex << a << std::endl;

    // CHAR_BIT - number of bits in byte
    //https://ru.wikipedia.org/wiki/Limits.h

    // For positive number mask will be equal to 0x0
    // For negative number mask will be equal to 0xFFFFFFFF

    int mask = a >> (sizeof(int) * CHAR_BIT - 1);
//    std::cout << "Mask: " << mask << ", as hex = " << std::hex << mask <<
//                 std::endl;

    int result = (a + mask) ^ mask;
//    std::cout << "Result: " << result << ", as hex = " << std::hex << result <<
//                 std::endl;

    return result;
}

}

#endif // BITWISE_OPERATORS_HPP
