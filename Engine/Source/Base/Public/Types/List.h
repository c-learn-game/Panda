#ifndef LIST_H
#define LIST_H

#include <list>
#include "Base/Public/Assert.h"

namespace Panda
{
    template <typename ListType>
    class CList : public std::list<ListType>
    {
    public:
        explicit CList() = default;

        int AddUnique(const ListType& Value);

        const ListType& operator[](const size_t& Pos) const;
    };

    template <typename ListType>
    using CListIterator  = typename CList<ListType>::iterator;

    template <typename ListType>
    int CList<ListType>::AddUnique(const ListType& Value)
    {
        int Index = 0;
        for (auto It = this->begin(); It != this->end(); ++It)
        {
            if ((*It) == Value)
            {
                return Index;
            }
            ++Index;
        }

        this->push_back(Value);
        return this->size() - 1;
    }

    template <typename ListType>
    const ListType& CList<ListType>::operator[](const size_t& Pos) const
    {
        check(0 <= Pos && Pos < this->size())
        CListIterator<ListType> It =  this->begin();
        int Index = 0;
        while (Index < Pos)
        {
            ++Index;
            ++It;
        }
        return *It;
    }
}

#endif
