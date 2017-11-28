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

}

#endif // BITWISE_OPERATORS_HPP
