//
// Created by chendebi on 2023/5/1.
//

#ifndef TEST_RENDERER_H
#define TEST_RENDERER_H

#include "RHI/RenderContext.h"

namespace Panda
{
    class FRenderer
    {
    public:
        explicit FRenderer(const SharedPtr<FRenderContext> &RenderContext);
        virtual ~FRenderer() = default;

        virtual void Initialize();

        virtual void RendererMain();

    private:
        SharedPtr<FRenderContext> Context;

        // 临时测试
        SharedPtr<class FOpenGLVertexArrayObject> vao;
        SharedPtr<class FOpenGLShaderObject> Shader;
        SharedPtr<class FOpenGLVertexBufferObject> vbo;
    };
}


#endif //TEST_RENDERER_H
