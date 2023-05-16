
#include "Package.h"
#include "Core/Platform/Path.h"

namespace Panda
{
    bool UPackage::Save() const
    {
        if (Object)
        {
            FString AssetPath = PackagePathToAssetPath(Object->PackagePath);
            if (AssetPath.IsEmpty())
            {
                LogWarn("Invalid package path! {}", Object->PackagePath.ToStdString())
                return false;
            }
            FFileInfo Info(AssetPath);
            if (!Info.IsDir())
            {
                FFile File(AssetPath);
                if (File.Open(FFile::WriteOnly))
                {
                    FArchive Archive(&File);
                    Archive << Object->PackagePath;
                    Object->Serialize(Archive);
                    File.Close();
                    return true;
                }
            }
        }
        return false;
    }

    FString UPackage::PackagePathToAssetPath(const FString &PackagePath)
    {
        TArray<FString> PathScripts = PackagePath.Split("/");
        if (!PathScripts.empty())
        {
            if (PathScripts.front() == "Engine")
            {
                return FPath::ToLocalPath(PackagePath.Replace("/Engine", FPath::EnginContentPath));
            }
            else
            {
                checkf(false, "not supported path {}", PathScripts[0].ToStdString());
            }
        }
        return "";
    }
}