#ifndef QUEUE_H
#define QUEUE_H

#include <queue>

namespace Panda
{
    template <typename ListType>
    using CQueue = std::queue<ListType>;

    template <typename ListType>
    using CQueueIterator  = typename CQueue<ListType>::iterator;
}

#endif