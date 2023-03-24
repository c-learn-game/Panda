#ifndef EVENT_H
#define EVENT_H
#include "Base/Base.h"

#define PANDA_REGISTER_EVENT(_type, _category_flags)\
    public:\
        static EEventType Type() { return EEventType::_type; }\
        EEventType GetType() override { return Type(); }\
        CString GetEventName() override { return #_type; }\
        int GetCategoryFlags() override { return _category_flags; }

namespace Panda
{
    enum class EEventType : uint32
    {
        None,
        ResizeEvent,
        CloseEvent
    };

    enum class EEventCategory : int32
    {
        None = 0,
        WindowEventCategory = BIT(1),
        ContextEventCategory = BIT(2),
    };
    
    class CEvent
    {
    public:
        virtual ~CEvent() = default;

        virtual EEventType GetType() = 0;

        virtual CString GetEventName() = 0;

        virtual int GetCategoryFlags() const = 0;

        bool GetInCategory(EEventCategory Category) const
        {
            return GetCategoryFlags() & Category;
        }
    };
}

#endif