#ifndef SIZE_H
#define SIZE_H

namespace Panda
{
    template<typename T>
    struct CSize
    {
        union {T X; T Width;};
        union {T Y; T Height;};

        CSize() : X(0), Y(0) {}

        CSize(T SizeX, T SizeY) : X(SizeX), Y(SizeY) {}

        virtual bool IsValid() const
        {
            return X > 0 && Y > 0;
        }
    };

    using CIntSize = CSize<int>;
}

#endif
