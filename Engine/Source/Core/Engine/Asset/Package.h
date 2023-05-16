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

        static FString PackagePathToAssetPath(const FString& PackagePath);
    };

    template <typename T>
    inline T* LoadObject(const FString& PackagePath)
    {
        LogInfo("Load Object {}", PackagePath.ToStdString())
        FString AssetPath = UPackage::PackagePathToAssetPath(PackagePath);
        FFileInfo Info(AssetPath);
        if (!Info.IsDir() && Info.Exist())
        {
            FFile File(AssetPath);
            if (File.Open(FFile::ReadOnly))
            {
                T* AssetObject = new T();
                auto* Object = dynamic_cast<UAssetObject*>(AssetObject);
                if (!Object)
                {
                    delete Object;
                    return nullptr;
                }
                FArchive Archive(&File);
                Archive >> Object->PackagePath;
                Object->Deserialize(Archive);
                File.Close();
                if (Object->PackagePath != PackagePath)
                {
                    LogWarn("Asset path does not match load path.")
                    LogWarn("   asset path: {}", Object->PackagePath.ToStdString())
                    LogWarn("   load path: {}", PackagePath.ToStdString())
                    LogWarn("update object path to load path")
                    Object->PackagePath = PackagePath;
                }
                return AssetObject;
            }
        }
        return nullptr;
    }
}

#endif //PANDA_PACKAGE_H
