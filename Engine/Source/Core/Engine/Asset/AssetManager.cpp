
#include <Core/Platform/File.h>
#include "AssetManager.h"

namespace Panda
{
    FString UAssetManager::LoadFileText(const FString &FilePath)
    {
        LogInfo("load file text from: {}", FilePath.ToStdString())
        FFile File(FilePath);
        FString Text;
        if (File.Open())
        {
            Text = File.ReadAll();
            File.Close();
        }
        else
        {
            LogWarn("Open file failed!!!")
        }
        return Text;
    }
}