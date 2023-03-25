#ifndef EVENT_H
#define EVENT_H
#include "Base/Base.h"

// 构建Event类时通过这个宏创建
#define PANDA_REGISTER_EVENT(_type, _category_flags)\
    public:\
        static EEventType Type() { return EEventType::_type; }\
        EEventType GetType() override { return Type(); }\
        CString GetEventName() override { return #_type; }\
        int GetCategoryFlags() override { return (int)_category_flags; }

namespace Panda
{
    class CEvent
    {
    public:
        enum class EEventType : uint32
        {
            None,
            ResizeEvent,
            CloseEvent
        };

        enum EEventCategory
        {
            None = 0,
            WindowEventCategory = BIT(1),
            ContextEventCategory = BIT(2),
            ApplicationEventCategory = BIT(3)
        };
        
    public:
        virtual ~CEvent() = default;

        virtual EEventType GetType() = 0;

        virtual CString GetEventName() = 0;

        virtual int GetCategoryFlags() = 0;

        bool GetInCategory(EEventCategory Category)
        {
            return GetCategoryFlags() & static_cast<int>(Category);
        }
    };
}

#endif
