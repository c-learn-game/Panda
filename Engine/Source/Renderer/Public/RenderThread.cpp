#include "RenderThread.h"

#include "RendererContext.h"
#include "Base/Public/Logging/Logging.h"
#include "Renderer/Private/Command/RenderCommandBase.h"
#include "RHI/Public/PlatformRHI.h"
#include "RHI/Public/RHIVertexBuffer.h"
#include "RHI/Public/RHIVertexArray.h"
#include "RHI/Public/RHIShader.h"

static float Vertices[] = {
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
     0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
};

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "layout (location = 1) in vec3 aColor;\n"
                                 "out vec4 OutColor;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "   OutColor = vec4(aColor.x,aColor.y,aColor.z,1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "in vec4 OutColor;\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = OutColor;\n"
                                   "}\n\0";

namespace Panda
{

    FMutex FRenderer::CommandMutex;

    FThreadCondition FRenderer::Condition;

    CDequeue<SharedPtr<FRenderCommandBase>> FRenderer::Commands;

    FRenderer::FRenderer()
    {
    }

    void FRenderer::SetContext(const SharedPtr<FRenderContext>& NewContext)
    {
        // 必须在渲染线程调用
        Context = NewContext;
        Commands.clear();
    }

    void FRenderer::InitContext() const
    {
        Context->Init();
        RHICommand->SetClearColor(0.2f, 0.4f, 0.8f);
    }

    FRenderer* FRenderer::Get()
    {
        static FRenderer Renderer;
        return &Renderer;
    }

    FRenderThread::FRenderThread(SharedPtr<FRenderContext> Context)
        : FThreadBase("Render Thread")
    {
        FRenderer::Get()->SetContext(Context);
    }

    [[noreturn]] void FRenderThread::ThreadMain()
    {
        FRenderer::Get()->InitContext();
        RHICommand->Clear();
        SharedPtr<FRHIVertexBuffer> Buffer = MakeSharedPtr<FRHIVertexBuffer>(Vertices, sizeof (Vertices));
        FRHIShader Shader(vertexShaderSource, fragmentShaderSource);
        Buffer->AddLayout<float>(3);
        Buffer->AddLayout<float>(3);
        FRHIVertexArray Elem(Buffer);
        RHICommand->Clear();
        Shader.Execute();
        Elem.DrawArray();
        FRenderer::Get()->Context->SwapBuffers();
        while (bRunning)
        {
            // 执行指令
            SharedPtr<FRenderCommandBase> Command;
            {
                FUniqueLock<FMutex> Lock(FRenderer::CommandMutex);
                FRenderer::Condition.wait(Lock);
				while (!FRenderer::Commands.empty())
				{
					Command = FRenderer::Commands.front();
					FRenderer::Commands.pop_front();
					Command->Execute();
				}
				Lock.unlock();
            }
            // 收集场景数据
            RHICommand->Clear();
            Shader.Execute();
            Elem.DrawArray();
            FRenderer::Get()->Context->SwapBuffers();
        }
        LogInfo(LogSystem, "Thread %d Quit", GetThreadId())
    }
}
