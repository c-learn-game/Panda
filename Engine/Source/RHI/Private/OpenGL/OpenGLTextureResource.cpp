
#include "OpenGLTextureResource.h"
#include "OpenGLMacros.h"

namespace Panda
{
    static GLenum GetInternelFormat(FTextureFormat Format)
    {
        switch (Format) {
            case RGB:
                return GL_RGB;
            case RGBA:
                return GL_RGBA;
        }
        check(false)
    }

    FOpenGLTextureResource::~FOpenGLTextureResource()
    {
        if (IsValid())
        {
            ReleaseResource();
        }
    }

    void FOpenGLTextureResource::SetData(void *InData, int InWidth, int InHeight, FTextureFormat InFormat)
    {
        Data = InData;
        Width = InWidth;
        Height = InHeight;
        Format = InFormat;
    }

    void FOpenGLTextureResource::InitResource()
    {
        check(Data && Width > 0 && Height>0)
        PANDA_GL_CALL(glGenTextures(1, &TexId))
        PANDA_GL_CALL(glBindTexture(GL_TEXTURE_2D, TexId))
        PANDA_GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GetInternelFormat(Format), Width, Height, 0, GetInternelFormat(Format), GL_UNSIGNED_BYTE,Data))
        PANDA_GL_CALL(glGenerateMipmap(GL_TEXTURE_2D))
    }

    void FOpenGLTextureResource::ReleaseResource()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteTextures(1, &TexId))
        TexId = 0;
    }

    void FOpenGLTextureResource::Bind()
    {
        PANDA_GL_CALL(glBindTexture(GL_TEXTURE_2D, TexId))
    }
}