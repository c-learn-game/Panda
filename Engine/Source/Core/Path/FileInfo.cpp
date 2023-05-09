
#include "FileInfo.h"
#include <filesystem>
#include "Directory.h"

namespace Panda
{
    FFileInfo::FFileInfo(const FString& InFilePath)
    : FilePath(InFilePath)
    {

    }

    bool FFileInfo::IsDir() const
    {
        std::filesystem::path path(FilePath);
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
            std::filesystem::path path(FilePath);
            return FDirectory(path.parent_path().string());
        }
    }

    bool FFileInfo::Exist(const FString &FilePath)
    {
        return std::filesystem::exists(FilePath);
    }
}