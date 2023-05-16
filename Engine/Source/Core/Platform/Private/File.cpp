
#include "Core/Platform/File.h"
#include "Core/Platform/Path.h"

namespace Panda
{

    FFile::FFile(const FString &InFilePath)
    : FilePath(FPath::ToLocalPath(InFilePath))
    {

    }

    FFile::~FFile()
    {
        Release();
        Close();
    }

    bool FFile::Open(EFileFlag Flag)
    {
        Release();
        Close();

        FileOpenFlag = Flag;

        switch (Flag)
        {
            case ReadOnly:
                FileStream.open(FilePath.ToStdString(), std::ios::in|std::ios::binary);
                break;
            case WriteOnly:
                FileStream.open(FilePath.ToStdString(), std::ios::out|std::ios::binary);
                break;
            case ReadWrite:
                FileStream.open(FilePath.ToStdString(), std::ios::in|std::ios::out|std::ios::binary);
                break;
            case Append:
                FileStream.open(FilePath.ToStdString(), std::ios::app | std::ios::binary);
                break;
        }

        return FileStream.is_open();
    }

    void FFile::Close()
    {
        if (FileStream.is_open())
            FileStream.close();
    }

    char *FFile::Read(longlong DataSize)
    {
        if (FileStream.is_open() && FileOpenFlag == ReadOnly)
        {
            char *Data = new char [DataSize];
            FileStream.read(Data, DataSize);
            ReadedDatas.push_back(Data);
            return Data;
        }
        else
        {
            LogWarn("Reading the file failed, the file is not open or open flag is not ReadOnly!")
        }
        return nullptr;
    }

    char *FFile::ReadAll()
    {
        if (FileStream.is_open())
        {
            FileStream.seekg(0, std::ios::end);
            size_t DataSize = FileStream.tellg();
            char * Data = new char [DataSize+1];
            FileStream.seekg(0, std::ios::beg);
            FileStream.read(Data, DataSize);
            ReadedDatas.push_back(Data);
            Data[DataSize] = '\0';
            return Data;
        }
        return nullptr;
    }

    void FFile::Release()
    {
        for (int i = 0; i < ReadedDatas.size(); i++)
        {
            delete [] (ReadedDatas[i]);
        }
        ReadedDatas.clear();
    }

    void FFile::Write(void *Data, longlong DataSize)
    {
        if (IsOpened() && FileOpenFlag != ReadOnly && DataSize > 0)
        {
            FileStream.write(static_cast<char*>(Data), DataSize);
        }
        else
        {
            LogWarn("file not open or not writable!")
        }
    }

}