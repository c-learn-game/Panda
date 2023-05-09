
#include "File.h"

namespace Panda
{

    FFile::FFile(const FString &InFilePath)
    : FilePath(InFilePath)
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
                FileStream.open(FilePath, std::ios::in);
                break;
            case WriteOnly:
                FileStream.open(FilePath, std::ios::out);
                break;
            case ReadWrite:
                FileStream.open(FilePath, std::ios::in|std::ios::out);
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
            auto DataSize = FileStream.tellg();
            char * Data = new char [DataSize];
            FileStream.seekg(0, std::ios::beg);
            FileStream.read(Data, DataSize);
            ReadedDatas.push_back(Data);
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