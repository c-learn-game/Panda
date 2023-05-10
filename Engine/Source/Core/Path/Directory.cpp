
#include "Directory.h"
#include <filesystem>
#include "FileInfo.h"

namespace Panda
{
    FDirectory::FDirectory(const FString &InDirPath)
    : DirPath(InDirPath)
    {
    }

    bool FDirectory::CdUp()
    {
        DirPath = ParentPath();
        return true;
    }

    FString FDirectory::ParentPath() const
    {
        std::filesystem::path path(DirPath.ToStdString());
        return path.parent_path().string();
    }

    FString FDirectory::GetDirectoryLocalPath()
    {
        return DirPath;
    }

    bool FDirectory::Cd(const FString &DirectoryName)
    {
        if (Exist())
        {
            std::filesystem::directory_iterator DirList(DirPath.ToStdString());
            for (auto& Dir : DirList)
            {
                if (Dir.is_directory() && Dir.path().filename().string() == DirectoryName.ToStdString())
                {
                    DirPath = Dir.path().string();
                    return true;
                }
            }
        }
        return false;
    }

    bool FDirectory::Exist() const
    {
        if (FFileInfo::Exist(DirPath))
        {
            return std::filesystem::is_directory(DirPath.ToStdString());
        }
        return false;
    }

    FString FDirectory::GetFilePath(const FString &FileName, bool &Success)
    {
        if (Exist())
        {
            std::filesystem::directory_iterator DirList(DirPath.ToStdString());
            for (auto& Dir : DirList)
            {
                if ((!Dir.is_directory()) && Dir.path().filename().string() == FileName.ToStdString())
                {
                    Success = true;
                    return FString(Dir.path().string()).Replace("/","\\");
                }
            }
        }
        Success = false;
        return "";
    }
}