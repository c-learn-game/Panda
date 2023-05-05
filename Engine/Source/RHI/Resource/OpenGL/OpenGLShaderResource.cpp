//
// Created by chendebi on 2023/5/1.
//

#include "OpenGLShaderResource.h"
#include "OpenGLMacros.h"

namespace Panda
{
    void FOpenGLShaderResource::InitResource()
    {
        auto CreateShader = [&](GLenum ShaderType, const FString& ShaderSource) -> uint
        {
            PANDA_GL_CALL(uint Shader = glCreateShader(ShaderType))
            const char* Source = ShaderSource.c_str();
            PANDA_GL_CALL(glShaderSource(Shader, 1, &Source, nullptr))
            PANDA_GL_CALL(glCompileShader(Shader))
            int success = 0;
            char InfoLog[512];
            PANDA_GL_CALL(glGetShaderiv(Shader, GL_COMPILE_STATUS, &success))
            if (!success)
            {
                PANDA_GL_CALL(glGetShaderInfoLog(Shader, 512, nullptr, InfoLog))
                LogWarn("Compile shader failed!")
                LogWarn("   {}", InfoLog)
                PANDA_GL_CALL(glDeleteShader(Shader))
                Shader = 0;
            }
            return Shader;
        };

        uint VertShader = CreateShader(GL_VERTEX_SHADER, VertexShaderSource);
        uint FragShader = CreateShader(GL_FRAGMENT_SHADER, FragShaderSource);

        if (VertShader > 0 && FragShader > 0)
        {
            PANDA_GL_CALL(ShaderId = glCreateProgram())
            PANDA_GL_CALL(glAttachShader(ShaderId, VertShader))
            PANDA_GL_CALL(glAttachShader(ShaderId, FragShader))
            PANDA_GL_CALL(glLinkProgram(ShaderId))
            int success = 0;
            char InfoLog[512];
            PANDA_GL_CALL(glGetProgramiv(ShaderId, GL_LINK_STATUS, &success))
            if (!success)
            {
                PANDA_GL_CALL(glGetProgramInfoLog(ShaderId, 512, nullptr, InfoLog))
                LogWarn("OpenGL shader program link failed!")
                LogWarn("   {}", InfoLog)
                PANDA_GL_CALL(glDeleteProgram(ShaderId))
                ShaderId = 0;
            }
        }

        if (VertShader > 0) PANDA_GL_CALL(glDeleteShader(VertShader))
        if (FragShader > 0) PANDA_GL_CALL(glDeleteShader(FragShader))
    }

    FOpenGLShaderResource::~FOpenGLShaderResource()
    {
        if (IsValid())
        {
            ReleaseResource();
        }
    }

    bool FOpenGLShaderResource::IsValid() const
    {
        return ShaderId > 0;
    }

    void FOpenGLShaderResource::Bind()
    {
        check(IsValid())
        PANDA_GL_CALL(glUseProgram(ShaderId))
    }

    void FOpenGLShaderResource::ReleaseResource()
    {
        if (IsValid())
        {
            PANDA_GL_CALL(glDeleteProgram(ShaderId))
            ShaderId = 0;
        }
    }

    void FOpenGLShaderResource::SetShaderSource(const FString &InVertexShaderSource,
                                                const FString &InFragShaderSource)
    {
        VertexShaderSource = InVertexShaderSource;
        FragShaderSource = InFragShaderSource;
    }
}