#ifndef ARRAY_H
#define ARRAY_H
#include <vector>

namespace Panda
{
    template <typename ArrayType>
    class CArray : public std::vector<ArrayType>
    {
    public:
        void Add(const ArrayType& Value);
    };

    template <typename ArrayType>
    void CArray<ArrayType>::Add(const ArrayType& Value)
    {
        this->push_back(Value);
    }
}

#endif
