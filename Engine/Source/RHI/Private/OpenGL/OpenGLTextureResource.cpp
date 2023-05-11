
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

    void FOpenGLTextureResource::ReleaseResource()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteTextures(1, &TexId))
        TexId = 0;
    }

}