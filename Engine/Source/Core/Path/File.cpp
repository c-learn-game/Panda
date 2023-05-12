
#include "File.h"
#include "Path.h"

namespace Panda
{

    FFile::FFile(const FString &InFilePath)
    : FilePath(Path::ToLocalPath(InFilePath))
    {

    }

    FFile::~FFile()
    {
        Release();
        Close();
    }

    bool FFile::Open(EFileOpenState OpenState)
    {
        Release();
        Close();

        switch (OpenState)
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
        }
        return FileStream.is_open();
    }

    void FFile::Close()
    {
        if (FileStream.is_open())
            FileStream.close();
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

}