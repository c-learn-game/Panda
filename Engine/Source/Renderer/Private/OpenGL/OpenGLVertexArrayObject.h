//
// Created by chendebi on 2023/5/2.
//

#ifndef TEST_OPENGLVERTEXARRAYOBJECT_H
#define TEST_OPENGLVERTEXARRAYOBJECT_H

#include "Renderer/Private/RendererObject.h"

namespace Panda
{
    class FOpenGLVertexArrayObject : public FRendererObject
    {
    public:
        explicit FOpenGLVertexArrayObject(const SharedPtr<class FOpenGLVertexBufferObject>& InVertexBufferObject = nullptr);

        bool IsValid() const override
        { return ArrayId > 0; }

        void SetVertexBufferObject(const SharedPtr<class FOpenGLVertexBufferObject>& InVertexBufferObject);

        void Generate();

        void Destroy() override;

        void Draw();

    private:
        uint ArrayId = 0;
        SharedPtr<class FOpenGLVertexBufferObject> VertexBufferObject = nullptr;
        size_t VertexCount = 0;
    };
}


#endif //TEST_OPENGLVERTEXARRAYOBJECT_H
