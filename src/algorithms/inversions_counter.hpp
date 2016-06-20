#ifndef INVERSIONS_COUNTER_HPP_
#define INVERSIONS_COUNTER_HPP_

#include <iterator>
#include <utility>

template<typename T>
class InversionsCounterAlg
{
public:
    static size_t Calc(const T& input)
    {
        return SortAndCalc(input).second;
    }

private:
    static std::pair<T, size_t> SortAndCalc(const T& input)
    {
        if(input.size() < 2)
        {
            return std::pair<T, size_t>(input, 0);
        }

        size_t middle = input.size()/2;
        typename T::const_iterator middleIter(input.cbegin());
        std::advance(middleIter, middle);

        T first(input.begin(), middleIter);
        T second(middleIter, input.end());

        std::pair<T, size_t> firstPart = SortAndCalc(first);
        std::pair<T, size_t> secondPart = SortAndCalc(second);
        return Merge(firstPart, secondPart);
    }

    static std::pair<T, size_t> Merge(const std::pair<T, size_t>& firstPart,
            const std::pair<T, size_t>& secondPart)
    {
    	T firstArr = firstPart.first;
    	T secondArr = secondPart.first;

        if (firstArr.empty() && secondArr.empty())
        {
            return std::pair<T, size_t>(T(), 0);
        }
        else if (firstArr.empty() &&
        		false == secondArr.empty())
        {
            return secondPart;
        }
        else if (false == firstArr.empty() &&
        		secondArr.empty())
        {
            return firstPart;
        }

        std::pair<T, size_t> result;
        std::copy(firstArr.begin(), firstArr.end(),
        		back_inserter(result.first));

        std::copy(secondArr.begin(), secondArr.end(),
        		back_inserter(result.first));

        result.second = firstPart.second + secondPart.second;

        for (size_t k = 0, i = 0, j = 0; k < result.first.size(); ++k)
        {
            if (i < firstArr.size() &&
            		(secondArr.size() <= j ||
            				firstArr[i] <= secondArr[j]))
            {
                result.first[k] = firstArr[i];
                ++i;
            }
            else
            {
                result.first[k] = secondArr[j];
                ++j;

                // number of inversion = number of elements in the sorted left
                // half of the input array (in this case firstArr) that
                // we don't iterate yet (max number of elements - number of
                // current position)
                result.second += firstArr.size() - i;
            }
        }

        return result;
    }
};

// Inversions Counter
// Input: array of numbers
// We need to calculate how many permutations we need to make
// so all numbers in array will be in increasing order.
// Example: 1, 3, 5, 2, 4, 6
// Here we have 3 inversions: (3, 2) (5, 2) (5, 4)
// As basic algorithm we will use Merge Sort
// @input:
// - container - object of container type
// @output:
// - T - number of inversions
template<typename T>
size_t InversionsCounter(const T& container)
{
    return InversionsCounterAlg<T>::Calc(container);
}

#endif /* INVERSIONS_COUNTER_HPP_ */
