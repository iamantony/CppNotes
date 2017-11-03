#ifndef QUICKSORT_RESEARCH_HPP_
#define QUICKSORT_RESEARCH_HPP_

#include <vector>

class QuickSortResearch
{
public:
    enum class PivotPosition
    {
        FIRST = 0,
        MEDIAN_OF_THREE,
        LAST
    };

private:
    long long int m_comparisons = 0;

public:
    // first and last are inclusive
    void Sort(std::vector<int>& array, const size_t& first,
            const size_t& last, const PivotPosition& pivotPosition)
    {
        if (array.empty() || last - first < 1)
        {
            return;
        }

        m_comparisons += static_cast<long long int>(last - first);

        ChoosePivot(array, first, last, pivotPosition);
        size_t result_position = Partition(array, first, last);
        if (first < result_position)
        {
            Sort(array, first, result_position - 1, pivotPosition);
        }

        if (result_position < last)
        {
            Sort(array, result_position + 1, last, pivotPosition);
        }
    }

    long long int GetComparisonsNumber() const
    {
        return m_comparisons;
    }

private:
    void ChoosePivot(std::vector<int>& array, const size_t& first,
            const size_t& last, const PivotPosition& pivotPosition)
    {
        switch(pivotPosition)
        {
            case PivotPosition::FIRST:
                break;

            case PivotPosition::MEDIAN_OF_THREE:
            {
                size_t middle = first + (last - first)/2;
                if(array[first] >= array[middle] && array[first] >= array[last])
                {
                    if(array[middle] >= array[last])
                    {
                        std::swap(array[middle], array[first]);
                    }
                    else
                    {
                        std::swap(array[last], array[first]);
                    }
                }
                else if(array[middle] >= array[first] && array[middle] >= array[last])
                {
                    if(array[last] >= array[first])
                    {
                        std::swap(array[last], array[first]);
                    }
                }
                else if(array[middle] >= array[first])
                {
                    std::swap(array[middle], array[first]);
                }

                break;
            }

            case PivotPosition::LAST:
            {
                std::swap(array[first], array[last]);
                break;
            }

            default:
            break;
        }
    }

    size_t Partition(std::vector<int>& array, const size_t& first,
            const size_t& last)
    {
        const int pivotValue = array[first];
        size_t i = first + 1;
        for(size_t j = first + 1; j <= last; ++j)
        {
            if (array[j] < pivotValue)
            {
                std::swap(array[i], array[j]);
                ++i;
            }
        }

        std::swap(array[i - 1], array[first]);
        return i - 1;
    }
};

// Quick Sort Algorithm
// @input:
// - array - vector of integers
// @output:
// - std::pair<std::vector<int>, long long int> - sorted array and number of
// comparisons
std::pair<std::vector<int>, long long int> QuickSort(
        const std::vector<int>& array,
        const QuickSortResearch::PivotPosition& pivotPosition)
{
    std::vector<int> result = array;
    QuickSortResearch qs;
    qs.Sort(result, 0, result.size() - 1, pivotPosition);
    return std::pair<std::vector<int>, long long int>(result,
            qs.GetComparisonsNumber());
}

#endif /* QUICKSORT_RESEARCH_HPP_ */
