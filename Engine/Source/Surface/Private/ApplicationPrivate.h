#ifndef APPLICATIONPRIVATE_H
#define APPLICATIONPRIVATE_H

namespace Panda
{
    class CApplicationPrivate
    {
    public:
        virtual ~CApplicationPrivate() = default;

        virtual void PollEvents() = 0;

        static CApplicationPrivate* Create();
    };
}

#endif