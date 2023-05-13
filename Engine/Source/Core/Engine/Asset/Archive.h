
#ifndef PANDA_SARCHIVE_H
#define PANDA_SARCHIVE_H

#include "Basic/Basic.h"
#include "Core/Platform/File.h"

namespace Panda
{
    class FArchive
    {
    public:
        explicit FArchive(FFile* InAssetFile);

        void Serialize(int Type, void* Data, long DataSize);

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


    template<>
    inline FArchive& FArchive::operator<<(const int &Data)
    {
        size_t TempSize = sizeof (int);
        int temp = Data;
        AssetFile->Write(&TempSize, sizeof (size_t));
        AssetFile->Write(&temp, sizeof (int));
        return *this;
    }

    template<>
    inline FArchive& FArchive::operator>>(int& Data)
    {
        size_t DataSize = *(size_t*)(AssetFile->Read(sizeof (size_t )));
        LogInfo("read data size is {}", DataSize);
        Data = *(int*)(AssetFile->Read(DataSize));
        return *this;
    }
}

#endif //PANDA_SARCHIVE_H
