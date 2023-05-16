
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

        void* Deserialize(longlong & Size);

        template<typename T>
        inline friend FArchive& operator<<(FArchive& Archive, const T& Data);

        template<typename T>
        inline friend FArchive& operator>>(FArchive& Archive, T& Data);

    private:
        class FFile* AssetFile = nullptr;
    };

    template <typename ClassType>
    inline FArchive& operator << (FArchive& Archive, const ClassType& Data)
    {
        ClassType TempData = Data;
        Archive.Serialize(&TempData, sizeof (ClassType));
        return Archive;
    }

    template <typename ClassType>
    inline FArchive& operator >> (FArchive& Archive, ClassType& Data)
    {
        longlong DataSize = 0;
        Data = *(ClassType*)Archive.Deserialize(DataSize);
        return Archive;
    }

    // string
    template <>
    inline FArchive& operator<<(FArchive& Archive, const FString& String)
    {
        std::string StdString = String.ToStdString();
        const char *StringData = StdString.c_str();
        Archive.Serialize((void*)StringData, StdString.size()+1);
        return Archive;
    }

    template <>
    inline FArchive& operator>>(FArchive& Archive, FString& String)
    {
        longlong StringLength = 0;
        char* Data = (char *)Archive.Deserialize(StringLength);
        String = Data;
        return Archive;
    }

}

#endif //PANDA_SARCHIVE_H
