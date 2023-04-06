#include "OpenGLPlatformRHI.h"
#include "Public/OpenGLBase.h"

namespace Panda
{ 
    void FOpenGLPlatformRHI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void FOpenGLPlatformRHI::SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void FOpenGLPlatformRHI::SetViewport(int x, int y, int w, int h)
    {
        glViewport(x, y, w, h);
    }

    int FOpenGLPlatformRHI::CompileShader(const char *VertShaderSource, const char *FragShaderSource) {
        check(!IsValid())
        int ProgramId = glCreateProgram();
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
        uint vs = CompileShader(VertShaderSource, GL_VERTEX_SHADER);
        uint fs = CompileShader(FragShaderSource, GL_FRAGMENT_SHADER);

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
            PANDA_GL_CALL(glDeleteProgram(ProgramId))
            ProgramId = 0;
        }
        return ProgramId;
    }

    void FOpenGLPlatformRHI::UseShader(const int &ShaderId)
    {
        PANDA_GL_CALL(glUseProgram(ShaderId))
    }

    uint FOpenGLPlatformRHI::CreateVertexBufferObject(float *Vertices, int BufferSize, EBufferUsage Usage) {
        uint BufferId = 0;
        PANDA_GL_CALL(glGenBuffers(1, &BufferId))
        PANDA_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, BufferId))
        PANDA_GL_CALL(glBufferData(GL_ARRAY_BUFFER, BufferSize, Vertices, (int)Usage))
        return BufferId;
    }

    uint FOpenGLPlatformRHI::CreateVertexArrayObject(int StrideSize, const CArray<FVertexBufferLayout> &Layouts) {
        uint VaoId = 0;
        PANDA_GL_CALL(glGenVertexArrays(1, &VaoId))
        PANDA_GL_CALL(glBindVertexArray(VaoId))
        for (int i = 0; i < Layouts.size(); ++i) 
		{
            const FVertexBufferLayout& Layout = Layouts[i];
            PANDA_GL_CALL(glVertexAttribPointer(i, Layout.Count, GL_FLOAT,
                                                GL_FALSE, StrideSize, (void*)Layout.Offset))

            // 保持最大的attrib index 是启用的
            PANDA_GL_CALL(glEnableVertexAttribArray(i))
        }
        return VaoId;
    }

    FOpenGLPlatformRHI::FOpenGLPlatformRHI() {
        static_assert(PLATFORM_VAR_FLOAT == GL_FLOAT);
    }

    void FOpenGLPlatformRHI::DrawArray(uint VaoId, int Count) {
        PANDA_GL_CALL(glBindVertexArray(VaoId))
        PANDA_GL_CALL(glDrawArrays(GL_TRIANGLES, 0, Count))
    }
}
