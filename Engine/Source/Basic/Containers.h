
#ifndef PANDA_CONTAINERS_H
#define PANDA_CONTAINERS_H

#include <vector>
#include <unordered_map>

namespace Panda
{
    template<typename T>
    using TArray = std::vector<T>;

    template<typename Key, typename Value>
    using THash = std::unordered_map<Key, Value>;
}

#endif //PANDA_CONTAINERS_H
