#include "Renderer.h"
#include "glad/glad.h"
#include "Public/RendererContext.h"

namespace Panda
{
    FRenderer::FRenderer(const SharedPtr<FRenderContext>& Context)
        : RendererContext(Context)
    {
        
    }

    void FRenderer::Init()
    {
        RendererContext->Init();
    }

    void FRenderer::RenderMain()
    {
        RendererContext->Init();
        glClearColor(0.2, 0.3, 0.4, 1.0);
        while (true)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            RendererContext->SwapBuffers();
        }
    }
}
