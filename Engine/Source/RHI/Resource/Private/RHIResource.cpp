#include "RHI/Resource/RHIVertexBufferResource.h"
#include "RHI/Resource/RHIVertexArrayResource.h"
#include "RHI/Resource/RHIIndexBufferResource.h"
#include "RHI/Resource/RHIShaderResource.h"
#include "RHI/Resource/RHITextureResource.h"
#include "RHI/Private/OpenGL/OpenGLVertexBufferResource.h"
#include "RHI/Private/OpenGL/OpenGLVertexArrayResource.h"
#include "RHI/Private/OpenGL/OpenGLIndexBufferResorce.h"
#include "RHI/Private/OpenGL/OpenGLShaderResource.h"
#include "RHI/Private/OpenGL/OpenGLTextureResource.h"

namespace Panda
{
	SharedPtr<FRHIVertexBufferResource> FRHIVertexBufferResource::Create()
	{
		return MakeShared<FOpenGLVertexBufferResource>();
	}
	
	SharedPtr<FRHIVertexArrayResource> FRHIVertexArrayResource::Create()
	{
		return MakeShared<FOpenGLVertexArrayResource>();
	}

	SharedPtr<FRHIIndexBufferResource> FRHIIndexBufferResource::Create()
	{
        return MakeShared<FOpenGLIndexBufferResource>();
	}

	SharedPtr<FRHIShaderResource> FRHIShaderResource::Create()
	{
        return MakeShared<FOpenGLShaderResource>();
	}

    SharedPtr<FRHITextureResource> FRHITextureResource::Create(int Width, int Height, FTextureFormat Format)
    {
        auto TexResource = MakeShared<FOpenGLTextureResource>();
        TexResource->Width = Width;
        TexResource->Height = Height;
        TexResource->Format = Format;
        return TexResource;
    }
}