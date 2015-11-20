#ifndef CHARTYPE_H_
#define CHARTYPE_H_

#include <iostream>
#include <limits>
#include <ios>

void CharTypes()
{
    std::cout << "CharTypes()" << std::endl;

    std::cout << "char: " << std::endl;
    std::cout << "char size: " << sizeof(char) << std::endl;
    std::cout << "min char = " <<
                static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
    std::cout << "max char = " <<
                static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
    std::cout << "is signed: " << std::boolalpha <<
            bool(std::numeric_limits<char>::is_signed) << std::endl;
    std::cout << std::endl;

    std::cout << "signed char: " << std::endl;
    std::cout << "signed char size: " << sizeof(signed char) << std::endl;
    std::cout << "min signed char = " <<
        static_cast<int>(std::numeric_limits<signed char>::min()) << std::endl;
    std::cout << "max signed char = " <<
        static_cast<int>(std::numeric_limits<signed char>::max()) << std::endl;
    std::cout << "is signed: " << std::boolalpha <<
            bool(std::numeric_limits<signed char>::is_signed) << std::endl;
    std::cout << std::endl;

    std::cout << "unsigned char: " << std::endl;
    std::cout << "unsigned char size: " << sizeof(unsigned char) << std::endl;
    std::cout << "min unsigned char = " <<
        static_cast<int>(std::numeric_limits<unsigned char>::min()) << std::endl;
    std::cout << "max unsigned char = " <<
        static_cast<int>(std::numeric_limits<unsigned char>::max()) << std::endl;
    std::cout << "is signed: " << std::boolalpha <<
            bool(std::numeric_limits<unsigned char>::is_signed) << std::endl;
    std::cout << std::endl;
}

void CharAssigments()
{
    std::cout << "CharAssigments()" << std::endl;

    const char c = 127;
    const signed char sc = 127;
    const unsigned char uc = 255;

    char testChar = 10;
    std::cout << "char + signed char = " << (testChar + sc) << std::endl;
    std::cout << "char + unsigned char = " << (testChar + uc) << std::endl;

    signed char testSigChar = 10;
    std::cout << "signed char + char = " << (testSigChar + c) << std::endl;
    std::cout << "signed char + unsigned char = " <<
            (testSigChar + uc) << std::endl;

    unsigned char testUnSigChar = 10;
    std::cout << "unsigned char + char = " << (testUnSigChar + c) << std::endl;
    std::cout << "unsigned char + signed char = " <<
                    (testUnSigChar + sc) << std::endl;
    std::cout << std::endl;
}

void Start()
{
    CharTypes();
    CharAssigments();
}

#endif /* CHARTYPE_H_ */
