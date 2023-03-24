#ifndef BASE_H
#define BASE_H

#include "Public/Logging/Logging.h"
#include "Public/Types/Size.h"
#include "Public/Assert.h"
#include "Public/Pointer.h"
#include "Public/Types/Array.h"
#include "Public/Types/List.h"
#include "Public/Types/Map.h"
#include "Public/Types/Math.h"
#include "Public/Types/Queue.h"

// 参数未使用时标记为未使用
#define PANDA_UNUSED(x) (void)x

// 位移
#define BIT(x) (1 << (x))

using uint = unsigned int;
using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using ulong = unsigned long;

using int32 = glm::int32;

namespace Panda
{
    enum MouseButton
    {
        NoButton,
        MouseButtonLeft,
        MouseButtonRight,
    };

    using CPos = CIntSize;
}

#endif
