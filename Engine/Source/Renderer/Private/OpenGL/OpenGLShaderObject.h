//
// Created by chendebi on 2023/5/1.
//

#ifndef TEST_OPENGLSHADEROBJECT_H
#define TEST_OPENGLSHADEROBJECT_H

#include "Renderer/Private/RendererObject.h"

namespace Panda
{
    class FOpenGLShaderObject : public FRendererObject
    {
    public:
        explicit FOpenGLShaderObject(const FString& VertexShaderSource, const FString& PixelShaderSource);

        ~FOpenGLShaderObject() override;

        void Bind();

        bool IsValid() const override;

        void Destroy() override;

    private:

        uint ShaderId = 0;
    };
}

#endif //TEST_OPENGLSHADEROBJECT_H
