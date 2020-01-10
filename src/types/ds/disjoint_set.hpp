#ifndef TYPES_DS_DISJOINT_SET_HPP
#define TYPES_DS_DISJOINT_SET_HPP

#include <vector>
#include <string>

namespace Types::DS {
    class DisjointSet {
        std::vector<size_t> m_parentMap;
        std::vector<size_t> m_rank;

        void checkElementIndex(size_t elementIndex) const;
        void setParent(size_t elementIndex, size_t parentIndex);
        size_t getRank(size_t elementIndex) const;
        void increaseRank(size_t elementIndex);

    public:
        DisjointSet(const size_t elementsNum);

        size_t parent(size_t elementIndex) const;
        bool inUnion(size_t firstElement, size_t secondElement) const;
        void makeUnion(size_t firstElement, size_t secondElement);
    };

    DisjointSet::DisjointSet(const size_t elementsNum) :
        m_parentMap(elementsNum, 0), m_rank(elementsNum, 0)
    {
        for (size_t i = 0; i < m_parentMap.size(); ++i) {
            m_parentMap[i] = i;
        }
    }

    void DisjointSet::checkElementIndex(const size_t elementIndex) const {
        if (elementIndex >= m_parentMap.size()) {
            std::string msg =
                std::string("Invalid element index: ") + std::to_string(elementIndex);

            throw std::runtime_error(msg);
        }
    }

    size_t DisjointSet::parent(size_t elementIndex) const {
        checkElementIndex(elementIndex);

        while (elementIndex != m_parentMap[elementIndex]) {
            elementIndex = m_parentMap[elementIndex];
        }

        return elementIndex;
    }

    void DisjointSet::setParent(const size_t elementIndex, const size_t parentIndex) {
        const auto elementParent = parent(elementIndex);
        m_parentMap[elementParent] = parentIndex;
    }

    bool DisjointSet::inUnion(size_t firstElement, size_t secondElement) const {
        return parent(firstElement) == parent(secondElement);
    }

    void DisjointSet::makeUnion(size_t firstElement, size_t secondElement) {
        if (inUnion(firstElement, secondElement)) { return; }

        const auto firstParent = parent(firstElement);
        const auto secondParent = parent(secondElement);

        const auto firstParentRank = getRank(firstParent);
        const auto secondParentRank = getRank(secondParent);

        if (firstParentRank > secondParentRank) {
            setParent(secondParent, firstParent);
        }
        else if (firstParentRank < secondParentRank) {
            setParent(firstParent, secondParent);
        }
        else {
            setParent(secondParent, firstParent);
            increaseRank(firstParent);
        }
    }

    size_t DisjointSet::getRank(const size_t elementIndex) const {
        return m_rank[elementIndex];
    }

    void DisjointSet::increaseRank(const size_t elementIndex) {
        ++m_rank[elementIndex];
    }
}

#endif //TYPES_DS_DISJOINT_SET_HPP
