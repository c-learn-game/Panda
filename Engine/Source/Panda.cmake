add_library("Panda" STATIC
    "Engine/Source/Base/Base.h"
        "Engine/Source/Base/Private/Logging/Logging.cpp"
        "Engine/Source/Base/Private/Thread/Thread.cpp"
      "Engine/Source/Base/Public/Assert.h"
        "Engine/Source/Base/Public/Logging/Logging.h"
      "Engine/Source/Base/Public/Pointer.h"
        "Engine/Source/Base/Public/Thread/Thread.h"
        "Engine/Source/Base/Public/Thread/ThreadBase.h"
        "Engine/Source/Base/Public/Types/Array.h"
        "Engine/Source/Base/Public/Types/List.h"
        "Engine/Source/Base/Public/Types/Map.h"
        "Engine/Source/Base/Public/Types/Math.h"
        "Engine/Source/Base/Public/Types/Queue.h"
        "Engine/Source/Base/Public/Types/Size.h"
        "Engine/Source/Base/Public/Types/String.h"
      "Engine/Source/Event/Public/ApplicationEvents.h"
      "Engine/Source/Event/Public/Event.h"
      "Engine/Source/Event/Public/WindowEvents.h"
    "Engine/Source/Launch/EngineLaunch.h"
    "Engine/Source/Launch/GraphicsThreadPoolSubsystem.cpp"
    "Engine/Source/Launch/GraphicsThreadPoolSubsystem.h"
        "Engine/Source/RHI/Private/OpenGL/OpenGLPlatformRHI.cpp"
        "Engine/Source/RHI/Private/OpenGL/OpenGLPlatformRHI.h"
          "Engine/Source/RHI/Private/OpenGL/Public/OpenGLBase.h"
          "Engine/Source/RHI/Private/OpenGL/Public/OpenGLObject.h"
          "Engine/Source/RHI/Private/OpenGL/Public/OpenGLShaderObject.cpp"
          "Engine/Source/RHI/Private/OpenGL/Public/OpenGLShaderObject.h"
          "Engine/Source/RHI/Private/OpenGL/Public/VertexArrayObject.cpp"
          "Engine/Source/RHI/Private/OpenGL/Public/VertexArrayObject.h"
          "Engine/Source/RHI/Private/OpenGL/Public/VertexBufferObject.cpp"
          "Engine/Source/RHI/Private/OpenGL/Public/VertexBufferObject.h"
      "Engine/Source/RHI/Private/PlatformRHI.cpp"
      "Engine/Source/RHI/Public/PlatformRHI.h"
      "Engine/Source/Renderer/Command/ContextChangeCommand.h"
        "Engine/Source/Renderer/Command/Private/ContextChangeCommand.cpp"
        "Engine/Source/Renderer/Command/Private/ViewportCommand.cpp"
      "Engine/Source/Renderer/Command/ViewportCommand.h"
        "Engine/Source/Renderer/Private/Command/RenderCommandBase.h"
      "Engine/Source/Renderer/Private/GLFWRendererContextPrivate.cpp"
      "Engine/Source/Renderer/Private/GLFWRendererContextPrivate.h"
      "Engine/Source/Renderer/Private/RendererContext.cpp"
      "Engine/Source/Renderer/Private/RendererContextPrivate.cpp"
      "Engine/Source/Renderer/Private/RendererContextPrivate.h"
      "Engine/Source/Renderer/Public/RenderThread.cpp"
      "Engine/Source/Renderer/Public/RenderThread.h"
      "Engine/Source/Renderer/Public/RendererContext.h"
      "Engine/Source/Scene/Actor/Actor.h"
        "Engine/Source/Scene/Component/Public/Component.h"
      "Engine/Source/Surface/Private/Application.cpp"
      "Engine/Source/Surface/Private/ApplicationPrivate.cpp"
      "Engine/Source/Surface/Private/ApplicationPrivate.h"
      "Engine/Source/Surface/Private/GLFWApplicationPrivate.cpp"
      "Engine/Source/Surface/Private/GLFWApplicationPrivate.h"
      "Engine/Source/Surface/Private/GLFWWindowPrivate.cpp"
      "Engine/Source/Surface/Private/GLFWWindowPrivate.h"
      "Engine/Source/Surface/Private/Window.cpp"
      "Engine/Source/Surface/Private/WindowPrivate.cpp"
      "Engine/Source/Surface/Private/WindowPrivate.h"
      "Engine/Source/Surface/Public/Application.h"
      "Engine/Source/Surface/Public/Window.h"
        Scene/Component/Private/StaticMeshComponent.cpp Scene/Component/Public/StaticMeshComponent.h Renderer/Scene/Private/RenderObject.cpp Renderer/Scene/Public/RenderObject.h Renderer/Scene/Public/BasicMeshRenderObject.cpp Renderer/Scene/Public/BasicMeshRenderObject.h RHI/Public/RHIShader.h RHI/Private/RHIShader.cpp RHI/Public/RHIVertexBuffer.cpp RHI/Public/RHIVertexBuffer.h)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  set_target_properties("Panda" PROPERTIES
    OUTPUT_NAME "Panda"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
    LIBRARY_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
    RUNTIME_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
  )
endif()
target_include_directories("Panda" PRIVATE
  $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Source>
  $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Third/glfw/include>
  $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Third/glm/glm>
  $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Third/glad/include>
)
target_compile_definitions("Panda" PRIVATE
  $<$<CONFIG:Debug>:PANDA_PLATFORM_GLFW>
  $<$<CONFIG:Debug>:PANDA_OPENGL>
  $<$<CONFIG:Debug>:PANDA_OPENGL_VERSION_MAJOR=4>
  $<$<CONFIG:Debug>:PANDA_OPENGL_VERSION_MINOR=0>
  $<$<CONFIG:Debug>:PANDA_BUDEG>
)
target_link_directories("Panda" PRIVATE
)
target_link_libraries("Panda"
        "Glad"
)
target_compile_options("Panda" PRIVATE
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  set_target_properties("Panda" PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE False
    INTERPROCEDURAL_OPTIMIZATION False
  )
endif()
if(CMAKE_BUILD_TYPE STREQUAL Release)
  set_target_properties("Panda" PROPERTIES
    OUTPUT_NAME "Panda"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
    LIBRARY_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
    RUNTIME_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
  )
endif()
target_include_directories("Panda" PRIVATE
  $<$<CONFIG:Release>:/Users/chendebi/Develop/Panda/Engine/Source>
  $<$<CONFIG:Release>:/Users/chendebi/Develop/Panda/Engine/Third/glfw/include>
  $<$<CONFIG:Release>:/Users/chendebi/Develop/Panda/Engine/Third/glm/glm>
  $<$<CONFIG:Release>:/Users/chendebi/Develop/Panda/Engine/Third/glad/include>
)
target_compile_definitions("Panda" PRIVATE
  $<$<CONFIG:Release>:PANDA_PLATFORM_GLFW>
  $<$<CONFIG:Release>:PANDA_OPENGL>
  $<$<CONFIG:Release>:PANDA_OPENGL_VERSION_MAJOR=4>
  $<$<CONFIG:Release>:PANDA_OPENGL_VERSION_MINOR=0>
  $<$<CONFIG:Release>:PANDA_NO_BUDEG>
)
target_link_directories("Panda" PRIVATE
)
target_link_libraries("Panda"
)
target_compile_options("Panda" PRIVATE
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>
)
if(CMAKE_BUILD_TYPE STREQUAL Release)
  set_target_properties("Panda" PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE False
    INTERPROCEDURAL_OPTIMIZATION False
  )
endif()