#ifndef LOGGING_H
#define LOGGING_H

#include "Base/Public/Types/String.h"

struct CLogBaseCategory
{
    Panda::CString Name;

    CLogBaseCategory() {}

    CLogBaseCategory(const Panda::CString& InCategoryName) : Name(InCategoryName)
    {}
};

#ifdef CG_SYSTEM_WINDOWS

#define DECLARE_LOG_CATEGORY_EXTERN(CategoryName)\
    extern struct CLogCategory##CategoryName : public CLogBaseCategory\
    {\
        CLogCategory##CategoryName() : CLogBaseCategory(#CategoryName) {}\
    } CategoryName;

#define DEFINE_LOG_CATEGORY(CategoryName)\
    CLogCategory##CategoryName CategoryName;

#define LogInfo(LogCategory, Msg, ...)\
    {\
        Panda::CString OutMsg = "[" + LogCategory.Name + "] [Info] " + Msg + "\n";\
        fprintf(stdout, OutMsg.c_str(), ##__VA_ARGS__);\
    }

#define LogWarning(LogCategory, Msg, ...)\
    {\
        Panda::CString OutMsg = "[" + LogCategory.Name + "] [Warning] " + Msg + "\n";\
        fprintf(stdout, OutMsg.c_str(), ##__VA_ARGS__);\
    }

#define LogError(LogCategory, Msg, ...)\
    {\
        Panda::CString OutMsg = "[" + LogCategory.Name + "] [Error] " + Msg + "\n";\
        fprintf(stderr, OutMsg.c_str(), ##__VA_ARGS__);\
    }
#else
#define DECLARE_LOG_CATEGORY_EXTERN(CategoryName)\
    extern struct CLogCategory##CategoryName : public CLogBaseCategory\
    {\
        CLogCategory##CategoryName() : CLogBaseCategory(#CategoryName) {}\
    } CategoryName;

#define DEFINE_LOG_CATEGORY(CategoryName)\
    CLogCategory##CategoryName CategoryName;

#define LogInfo(LogCategory, Msg, ...)\
    {\
        Panda::CString OutMsg = "[" + LogCategory.Name + "] [Info] " + Msg + "\n";\
fprintf(stdout, OutMsg.c_str(), ##__VA_ARGS__);\
    }

#define LogWarning(LogCategory, Msg, ...)\
    {\
        Panda::CString OutMsg = "[" + LogCategory.Name + "] [Warning] " + Msg + "\n";\
fprintf(stdout, OutMsg.c_str(), ##__VA_ARGS__);\
    }

#define LogError(LogCategory, Msg, ...)\
    {\
        Panda::CString OutMsg = "[" + LogCategory.Name + "] [Error] " + Msg + "\n";\
fprintf(stderr, OutMsg.c_str(), ##__VA_ARGS__);\
    }
#endif

DECLARE_LOG_CATEGORY_EXTERN(LogSystem)

#endif
