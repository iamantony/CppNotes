#ifndef TEST_PALINDROME_SLL_HPP
#define TEST_PALINDROME_SLL_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/data_structures/sll/palindrome_sll.hpp"

BOOST_AUTO_TEST_CASE(test_palsll_empty_list)
{
    NodeSLL<int>* sll = nullptr;
    BOOST_CHECK(true == Algo::DS::SLL::PalindromeDetection::IsPalindrome(sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_palsll_valid_palindrome)
{
    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 9, 10});
        BOOST_CHECK(true ==
                    Algo::DS::SLL::PalindromeDetection::IsPalindrome(sll));
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = CreateSLL<int>({3, 2, 1, 2, 3});
        BOOST_CHECK(true ==
                    Algo::DS::SLL::PalindromeDetection::IsPalindrome(sll));
        DeleteSLL(&sll);
    }
}

BOOST_AUTO_TEST_CASE(test_palsll_not_palindrome)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
    BOOST_CHECK(false == Algo::DS::SLL::PalindromeDetection::IsPalindrome(sll));
    DeleteSLL(&sll);
}

#endif // TEST_PALINDROME_SLL_HPP
