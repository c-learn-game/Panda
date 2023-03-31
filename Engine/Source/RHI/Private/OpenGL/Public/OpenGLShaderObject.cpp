#include "OpenGLShaderObject.h"

namespace Panda
{
    FOpenGLShaderObject::FOpenGLShaderObject()
    = default;

    FOpenGLShaderObject::FOpenGLShaderObject(const char* VertexShaderSource, const char* FragmentShaderSource)
    {
        Compile(VertexShaderSource, FragmentShaderSource);
    }

    void FOpenGLShaderObject::Compile(const char* VertexShaderSource, const char* FragmentShaderSource)
    {
        check(!IsValid())
        ProgramId = glCreateProgram();
        auto CompileShader = [&](const char* ShaderSource, uint ShaderType) -> uint
        {
            PANDA_GL_CALL(uint Shader = glCreateShader(ShaderType))
            PANDA_GL_CALL(glShaderSource(Shader, 1, &ShaderSource, nullptr))
            PANDA_GL_CALL(glCompileShader(Shader))
            int Success = 1;
            char InfoLog[512];
            PANDA_GL_CALL(glGetShaderiv(Shader, GL_COMPILE_STATUS, &Success))
            if (!Success)
            {
                PANDA_GL_CALL(glGetShaderInfoLog(Shader, 512, NULL, InfoLog))
                LogWarning(LogSystem, "Shader compile failed!")
                LogWarning(LogSystem, "    %s", InfoLog)
                PANDA_GL_CALL(glDeleteShader(Shader))
                Shader = 0;
            }
            return Shader;
        };
        uint vs = CompileShader(VertexShaderSource, GL_VERTEX_SHADER);
        uint fs = CompileShader(FragmentShaderSource, GL_FRAGMENT_SHADER);

        if (vs && fs)
        {
            glAttachShader(ProgramId, vs);
            glAttachShader(ProgramId, fs);
            glLinkProgram(ProgramId);

            int Success = 1;
            char InfoLog[512];
            PANDA_GL_CALL(glGetProgramiv(ProgramId, GL_LINK_STATUS, &Success))
            if (!Success)
            {
                PANDA_GL_CALL(glGetProgramInfoLog(ProgramId, 512, NULL, InfoLog))
                LogWarning(LogSystem, "Program links failed!")
                LogWarning(LogSystem, "    %s", InfoLog)
                PANDA_GL_CALL(glDeleteProgram(ProgramId))
                ProgramId = 0;
            }
            PANDA_GL_CALL(glDeleteShader(vs))
            PANDA_GL_CALL(glDeleteShader(fs))
        }
        else
        {
            if (vs) PANDA_GL_CALL(glDeleteShader(vs))
            if (fs) PANDA_GL_CALL(glDeleteShader(vs))
        }
    }

    bool FOpenGLShaderObject::IsValid()
    {
        return ProgramId > 0;
    }

    void FOpenGLShaderObject::Use()
    {
        check(IsValid())
        PANDA_GL_CALL(glUseProgram(ProgramId))
    }

    void FOpenGLShaderObject::UnUse()
    {
        check(IsValid())
        PANDA_GL_CALL(glUseProgram(0))
    }

    void FOpenGLShaderObject::Destroy()
    {
        check(IsValid())
        PANDA_GL_CALL(glDeleteProgram(ProgramId))
        ProgramId = 0;
    }
}
