#ifndef TEST_PALINDROME_SLL_HPP
#define TEST_PALINDROME_SLL_HPP

#include <boost/test/unit_test.hpp>

#include <algorithm>

#include "types/singly_linked_list_nodes.hpp"
#include "algorithms/data_structures/palindrome_sll.hpp"

BOOST_AUTO_TEST_CASE(test_palsll_empty_list)
{
    NodeSLL<int>* sll = nullptr;
    PalindromeSLL::Solution solution;
    BOOST_CHECK(true == solution.isPalindrome(sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(test_palsll_valid_palindrome)
{
    {
        NodeSLL<int>* sll = CreateSLL<int>({10, 9, 9, 10});
        PalindromeSLL::Solution solution;
        BOOST_CHECK(true == solution.isPalindrome(sll));
        DeleteSLL(&sll);
    }

    {
        NodeSLL<int>* sll = CreateSLL<int>({3, 2, 1, 2, 3});
        PalindromeSLL::Solution solution;
        BOOST_CHECK(true == solution.isPalindrome(sll));
        DeleteSLL(&sll);
    }
}

BOOST_AUTO_TEST_CASE(test_palsll_not_palindrome)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
    PalindromeSLL::Solution solution;
    BOOST_CHECK(false == solution.isPalindrome(sll));
    DeleteSLL(&sll);
}

#endif // TEST_PALINDROME_SLL_HPP
