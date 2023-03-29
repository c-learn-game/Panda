#ifndef OPENGLSHADEROBJECT_H
#define OPENGLSHADEROBJECT_H

#include "OpenGLBase.h"

namespace Panda
{
    class FOpenGLShaderObject : public FOpenGLObject
    {
    public:

        explicit  FOpenGLShaderObject();

        explicit FOpenGLShaderObject(const char* VertexShaderSource, const char* FragmentShaderSource);

        void Compile(const char* VertexShaderSource, const char* FragmentShaderSource);
        
        bool IsValid() override;

        void Use() override;

        void UnUse() override;

        void Destroy() override;

    private:
        uint ProgramId = 0;
    };
}

#endif