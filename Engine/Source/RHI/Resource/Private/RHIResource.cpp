#include "RHI/Resource/RHIVertexBufferResource.h"
#include "RHI/Resource/RHIVertexArrayResource.h"
#include "OpenGL/OpenGLVertexBufferResource.h"
#include "OpenGL/OpenGLVertexArrayResource.h"

namespace Panda
{
	SharedPtr<FRHIVertexBufferResource> FRHIVertexBufferResource::Create()
	{
		return MakeShared<FOpenGLVertexBufferResource>();
	}
	
	SharedPtr<FRHIVertexArrayResource> FRHIVertexBufferResource::Create()
	{
		return MakeShared<FOpenGLVertexArrayResource>();
	}
}