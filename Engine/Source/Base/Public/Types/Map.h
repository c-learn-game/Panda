#ifndef MAP_H
#define MAP_H
#include <map>

namespace Panda
{
    template<typename KeyType, typename ValueType>
    using CMap = std::map<KeyType, ValueType>;

    template<typename KeyType, typename ValueType>
    using CMapIterator = typename  std::map<KeyType, ValueType>::iterator;
}

#endif