#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/sll/palindrome_sll.hpp"

BOOST_AUTO_TEST_SUITE(PalindromSLL)

BOOST_AUTO_TEST_CASE(empty_list)
{
    NodeSLL<int>* sll = nullptr;
    BOOST_CHECK(true == Algo::DS::SLL::PalindromeDetection::IsPalindrome(sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_CASE(valid_palindrome)
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

BOOST_AUTO_TEST_CASE(not_palindrome)
{
    NodeSLL<int>* sll = CreateSLL<int>({10, 9, 8, 7});
    BOOST_CHECK(false == Algo::DS::SLL::PalindromeDetection::IsPalindrome(sll));
    DeleteSLL(&sll);
}

BOOST_AUTO_TEST_SUITE_END()
