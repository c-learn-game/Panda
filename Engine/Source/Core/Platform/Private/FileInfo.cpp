
#include "Core/Platform/FileInfo.h"
#include <filesystem>
#include "Core/Platform/Directory.h"

namespace Panda
{
    FFileInfo::FFileInfo(const FString& InFilePath)
    : FilePath(InFilePath)
    {

    }

    bool FFileInfo::IsDir() const
    {
        std::filesystem::path path(FilePath.ToStdString());
        return std::filesystem::is_directory(path);
    }

    FDirectory FFileInfo::Dir()
    {
        if (IsDir())
        {
            return FDirectory(FilePath);
        }
        else
        {
            std::filesystem::path path(FilePath.ToStdString());
            return FDirectory(path.parent_path().string());
        }
    }

    bool FFileInfo::Exist() const
    {
        return FFileInfo::Exist(FilePath);
    }

    bool FFileInfo::Exist(const FString &FilePath)
    {
        return std::filesystem::exists(FilePath.ToStdString());
    }
}