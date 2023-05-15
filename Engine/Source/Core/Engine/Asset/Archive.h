
#ifndef PANDA_SARCHIVE_H
#define PANDA_SARCHIVE_H

#include "Basic/Basic.h"
#include "Core/Platform/File.h"
#include "Core/Math/Vector3.h"
#include "Core/Math/Vector4.h"

namespace Panda
{
    class FArchive
    {
    public:
        explicit FArchive(FFile* InAssetFile);

        void Serialize(void* Data, longlong DataSize);

        void* Deserialize(size_t & Size);


        template<typename T>
        inline FArchive& operator<<(const T& Data)
        {
            check(false)
            return *this;
        }

        template<typename T>
        inline FArchive& operator>>(T& Data)
        {
            check(false)
            return *this;
        }

    private:
        class FFile* AssetFile = nullptr;
    };

#define PANDA_ARCHIVE_TYPE(TypeClass) \
    template<>\
    inline FArchive& FArchive::operator<<(const TypeClass &Data)\
    {\
        size_t TempSize = sizeof (TypeClass);\
        TypeClass temp = Data;\
        AssetFile->Write(&TempSize, sizeof (size_t));\
        AssetFile->Write(&temp, sizeof (TypeClass));\
        return *this;\
    }\
\
    template<>\
    inline FArchive& FArchive::operator>>(TypeClass& Data)\
    {\
        size_t DataSize = *(size_t*)(AssetFile->Read(sizeof (size_t )));\
        Data = *(TypeClass*)(AssetFile->Read(DataSize));\
        return *this;\
    }

    PANDA_ARCHIVE_TYPE(bool)
    PANDA_ARCHIVE_TYPE(char)
    PANDA_ARCHIVE_TYPE(int)
    PANDA_ARCHIVE_TYPE(uint)
    PANDA_ARCHIVE_TYPE(size_t)
    PANDA_ARCHIVE_TYPE(long)
    PANDA_ARCHIVE_TYPE(float)
    PANDA_ARCHIVE_TYPE(double)
    PANDA_ARCHIVE_TYPE(FVector3)
    PANDA_ARCHIVE_TYPE(FVector4)

    // string
    template<>
    inline FArchive& FArchive::operator<<(const FString &String)
    {
        std::string StdString = String.ToStdString();
        const char *Data = StdString.c_str();
        Serialize((void*)Data, StdString.size());
        return *this;
    }
}

#endif //PANDA_SARCHIVE_H
