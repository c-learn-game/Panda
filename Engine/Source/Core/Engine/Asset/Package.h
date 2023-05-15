#ifndef PANDA_PACKAGE_H
#define PANDA_PACKAGE_H

#include "Basic/Basic.h"
#include "AssetObject.h"
#include "Archive.h"
#include "Core/Platform/FileInfo.h"
#include "Core/Platform/File.h"

namespace Panda
{
    class UPackage
    {
    public:
        class UAssetObject* Object = nullptr;

    public:
        bool Save() const;
    };

    template <typename T>
    inline T* LoadObject(const FString& AssetPath)
    {
        FFileInfo Info(AssetPath);
        if (!Info.IsDir() && Info.Exist())
        {
            FFile File(AssetPath);
            if (File.Open(FFile::WriteOnly))
            {
                T* AssetObject = new T();
                auto* Object = dynamic_cast<UAssetObject*>(AssetObject);
                if (!Object)
                {
                    delete Object;
                    return nullptr;
                }
                FArchive Archive(&File);
                Object->Deserialize(Archive);
                File.Close();
                return AssetObject;
            }
        }
        return nullptr;
    }
}

#endif //PANDA_PACKAGE_H
