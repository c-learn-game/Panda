#include "RHI/Resource/RHIVertexBufferResource.h"
#include "RHI/Resource/RHIVertexArrayResource.h"
#include "RHI/Resource/RHIIndexBufferResource.h"
#include "RHI/Resource/RHIShaderResource.h"
#include "RHI/Private/OpenGL/OpenGLVertexBufferResource.h"
#include "RHI/Private/OpenGL/OpenGLVertexArrayResource.h"
#include "RHI/Private/OpenGL/OpenGLIndexBufferResorce.h"
#include "RHI/Private/OpenGL/OpenGLShaderResource.h"

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
}