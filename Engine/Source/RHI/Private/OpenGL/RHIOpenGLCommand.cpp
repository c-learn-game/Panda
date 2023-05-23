

#include "RHIOpenGLCommand.h"
#include "RHI/Resource/RHIIndexBufferResource.h"
#include "RHI/Resource/RHIVertexArrayResource.h"
#include "OpenGLMacros.h"

namespace Panda
{
    void FRHIOpenGLCommand::SetViewport(const FIntRect &NewViewport)
    {
        glViewport(NewViewport.X, NewViewport.Y, NewViewport.Width, NewViewport.Height);
    }

    void FRHIOpenGLCommand::DrawMesh(const SharedPtr<FRHIVertexArrayResource> &VertexArrayResource,
                                     const SharedPtr<FRHIIndexBufferResource> &IndexBufferResource)
    {
        check(VertexArrayResource != nullptr && IndexBufferResource != nullptr)
        VertexArrayResource->Bind();
        IndexBufferResource->Bind();
        PANDA_GL_CALL(glDrawElements(GL_TRIANGLES, IndexBufferResource->GetIndexCount(),
                                     GL_UNSIGNED_INT, nullptr));
    }

    void FRHIOpenGLCommand::SetClearColor(const FLinearColor &Color)
    {
        glClearColor(Color.R, Color.G, Color.B, Color.A);
    }

    void FRHIOpenGLCommand::Clear(int Flag)
    {
        int ClearFlags = 0;
        if (Flag & FClearFlag::Color)
            ClearFlags |= GL_COLOR_BUFFER_BIT;
        if (Flag & FClearFlag::Depth)
            ClearFlags |= GL_DEPTH_BUFFER_BIT;
        glClear(ClearFlags);
    }
}