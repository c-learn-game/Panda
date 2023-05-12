
#include "OpenGLTextureResource.h"
#include "OpenGLMacros.h"

namespace Panda
{
    static GLint GetInternalFormat(FTextureFormat Format)
    {
        switch (Format) {
            case FTextureFormat::RGB:
                return GL_RGB;
            case FTextureFormat::RGBA:
                return GL_RGBA;
        }
        check(false)
    }

    static GLint GetGLTilingMode(FTextureTilingMethod Method)
    {
        switch (Method) {
            case FTextureTilingMethod::Wrap:
                return GL_REPEAT;
            case FTextureTilingMethod::Clamp:
                return GL_CLAMP;
            case FTextureTilingMethod::Mirror:
                return GL_MIRRORED_REPEAT;
        }
    }

    static GLint GetGLTextureFilter(FTextureFilter Filter)
    {
        switch (Filter) {
            case FTextureFilter::Nearest:
                return GL_NEAREST;
            case FTextureFilter::Linear:
                return GL_LINEAR;
        }
    }

    FOpenGLTextureResource::~FOpenGLTextureResource()
    {
        if (IsValid())
        {
            ReleaseResource();
        }
    }

    void FOpenGLTextureResource::ReleaseResource()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteTextures(1, &TexId))
        TexId = 0;
    }

    void FOpenGLTextureResource::InitResource(void *Data)
    {
        check(!IsValid())
        glGenTextures(1, &TexId);
        glBindTexture(GL_TEXTURE_2D, TexId);
        PANDA_GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GetInternalFormat(Format), Width, Height, 0, GetInternalFormat(Format), GL_UNSIGNED_BYTE, Data))
        PANDA_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GetGLTilingMode(XAxisTilingMethod)))
        PANDA_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GetGLTilingMode(YAxisTilingMethod)))
        PANDA_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GetGLTextureFilter(Filter)))
        PANDA_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GetGLTextureFilter(Filter)))

        if (bAutoMipmaps)
        {
            glGenerateMipmap(GL_TEXTURE_2D);
        }

        PANDA_CHECK_GL_ERROR()
    }

    void FOpenGLTextureResource::Bind(const int &TexSlot)
    {
        check(IsValid())
        glActiveTexture(GL_TEXTURE0 + TexSlot);
        glBindTexture(GL_TEXTURE_2D, TexId);
    }
}