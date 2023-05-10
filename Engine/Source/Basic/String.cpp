
#include "String.h"

namespace Panda
{


    FString::FString(const char *const InString)
    {
        String = InString;
    }

    FString& FString::operator=(const char * const InString)
    {
        String = InString;
        return *this;
    }

    FString& FString::Replace(const FString &OldString, const FString &NewString)
    {
        size_t SubStringStartPos = String.find(OldString.ToStdString());
        while (SubStringStartPos != std::string::npos)
        {
            String.replace(SubStringStartPos, OldString.Count(), NewString.String);
            SubStringStartPos = String.find(OldString.ToStdString());
        }
        return *this;
    }

    FString& FString::Append(const FString &InString)
    {
        String += InString.String;
        return *this;
    }

    bool FString::IsEmpty() const
    {
        return String.empty();
    }

    char FString::operator[](int Index) const
    {
        return String[Index];
    }

    FString::FString(const std::string &InString)
    {
        String = InString;
    }

    FString::FString(const FString &InString)
    {
        String = InString.String;
    }

    bool FString::operator==(const FString &InString) const
    {
        return String == InString.String;
    }

    char &FString::operator[](int Index)
    {
        return String[Index];
    }
}