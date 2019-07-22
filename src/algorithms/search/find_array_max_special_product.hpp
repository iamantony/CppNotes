#ifndef FIND_ARRAY_MAX_SPECIAL_PRODUCT_HPP
#define FIND_ARRAY_MAX_SPECIAL_PRODUCT_HPP

#include <map>
#include <vector>
#include <stack>

/*
You are given an array A containing N integers. The special product of each
ith integer in this array is defined as the product of the following:

1. LeftSpecialValue: For an index i, it is defined as the index j such that
A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions,
the LeftSpecialValue is the maximum value of j.

2. RightSpecialValue: For an index i, it is defined as the index j such that
A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions,
the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.
*/
namespace Algo::Search {

class FindArrayMaxSpecialProduct {
    static std::map<size_t, size_t> LeftSpecialValues(std::vector<int>& A) {
        if (A.empty()) {
            return {};
        }

        std::map<size_t, size_t> leftSpecials;
        std::stack<size_t> indexes;
        for (size_t i = A.size() - 1; ; --i) {
            while (!indexes.empty() && A[i] > A[indexes.top() - 1]) {
                auto prevIndex = indexes.top();
                indexes.pop();

                leftSpecials[prevIndex] = i + 1;
            }

            indexes.push(i + 1);

            if (i == 0) {
                break;
            }
        }

        return leftSpecials;
    }

    static std::map<size_t, size_t> RightSpecialValues(std::vector<int>& A) {
        if (A.empty()) {
            return {};
        }

        std::map<size_t, size_t> rightSpecials;
        std::stack<size_t> indexes;
        for (size_t i = 0; i < A.size(); ++i) {
            while (!indexes.empty() && A[i] > A[indexes.top() - 1]) {
                auto prevIndex = indexes.top();
                indexes.pop();

                rightSpecials[prevIndex] = i + 1;
            }

            indexes.push(i + 1);
        }

        return rightSpecials;
    }

public:
    static int Find(std::vector<int> &A) {
        auto leftSpecials = LeftSpecialValues(A);
        auto rightSpecials = RightSpecialValues(A);

        unsigned long long maxProduct = 0;
        for (auto iter = leftSpecials.cbegin();
             iter != leftSpecials.cend();
             ++iter) {
            auto index = iter->first;
            if (rightSpecials.count(index) == 0) {
                continue;
            }

            auto leftSpPos = static_cast<unsigned long long>(iter->second) - 1;
            auto rightSpPos =
                    static_cast<unsigned long long>(rightSpecials[index]) - 1;

            maxProduct = std::max(maxProduct, leftSpPos * rightSpPos);
        }

        return static_cast<int>(maxProduct % 1000000007);
    }
};
}

#endif // FIND_ARRAY_MAX_SPECIAL_PRODUCT_HPP
