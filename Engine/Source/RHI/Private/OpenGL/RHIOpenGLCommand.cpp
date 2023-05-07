

#include "RHIOpenGLCommand.h"
#include "RHI/Resource/RHIIndexBufferResource.h"
#include "RHI/Resource/RHIVertexArrayResource.h"
#include "OpenGLMacros.h"

namespace Panda
{
    void FRHIOpenGLCommand::DrawMesh(const SharedPtr<FRHIVertexArrayResource> &VertexArrayResource,
                                     const SharedPtr<FRHIIndexBufferResource> &IndexBufferResource)
    {
        check(VertexArrayResource != nullptr && IndexBufferResource != nullptr)
        VertexArrayResource->Bind();
        IndexBufferResource->Bind();
        PANDA_GL_CALL(glDrawElements(GL_TRIANGLES, IndexBufferResource->GetIndexCount(),
                                     GL_UNSIGNED_INT, nullptr));
    }
}