add_library("GLFW" STATIC
      "Engine/Third/glfw/include/GLFW/glfw3.h"
      "Engine/Third/glfw/include/GLFW/glfw3native.h"
    "Engine/Third/glfw/src/cocoa_init.m"
    "Engine/Third/glfw/src/cocoa_joystick.h"
    "Engine/Third/glfw/src/cocoa_joystick.m"
    "Engine/Third/glfw/src/cocoa_monitor.m"
    "Engine/Third/glfw/src/cocoa_platform.h"
    "Engine/Third/glfw/src/cocoa_time.c"
    "Engine/Third/glfw/src/cocoa_time.h"
    "Engine/Third/glfw/src/cocoa_window.m"
    "Engine/Third/glfw/src/context.c"
    "Engine/Third/glfw/src/egl_context.c"
    "Engine/Third/glfw/src/init.c"
    "Engine/Third/glfw/src/input.c"
    "Engine/Third/glfw/src/internal.h"
    "Engine/Third/glfw/src/monitor.c"
    "Engine/Third/glfw/src/nsgl_context.m"
    "Engine/Third/glfw/src/null_init.c"
    "Engine/Third/glfw/src/null_joystick.c"
    "Engine/Third/glfw/src/null_monitor.c"
    "Engine/Third/glfw/src/null_window.c"
    "Engine/Third/glfw/src/osmesa_context.c"
    "Engine/Third/glfw/src/platform.c"
    "Engine/Third/glfw/src/posix_module.c"
    "Engine/Third/glfw/src/posix_poll.c"
    "Engine/Third/glfw/src/posix_poll.h"
    "Engine/Third/glfw/src/posix_thread.c"
    "Engine/Third/glfw/src/posix_thread.h"
    "Engine/Third/glfw/src/posix_time.c"
    "Engine/Third/glfw/src/posix_time.h"
    "Engine/Third/glfw/src/vulkan.c"
    "Engine/Third/glfw/src/window.c"
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  set_target_properties("GLFW" PROPERTIES
    OUTPUT_NAME "GLFW"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
    LIBRARY_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
    RUNTIME_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
  )
endif()
target_include_directories("GLFW" PRIVATE
)
target_compile_definitions("GLFW" PRIVATE
  $<$<CONFIG:Debug>:PANDA_PLATFORM_GLFW>
  $<$<CONFIG:Debug>:PANDA_OPENGL>
  $<$<CONFIG:Debug>:PANDA_OPENGL_VERSION_MAJOR=4>
  $<$<CONFIG:Debug>:PANDA_OPENGL_VERSION_MINOR=0>
  $<$<CONFIG:Debug>:PANDA_BUDEG>
  $<$<CONFIG:Debug>:_GLFW_COCOA>
)
target_link_directories("GLFW" PRIVATE
)
target_link_libraries("GLFW"
)
target_compile_options("GLFW" PRIVATE
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  set_target_properties("GLFW" PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE False
    INTERPROCEDURAL_OPTIMIZATION False
  )
endif()
if(CMAKE_BUILD_TYPE STREQUAL Release)
  set_target_properties("GLFW" PROPERTIES
    OUTPUT_NAME "GLFW"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
    LIBRARY_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
    RUNTIME_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
  )
endif()
target_include_directories("GLFW" PRIVATE
)
target_compile_definitions("GLFW" PRIVATE
  $<$<CONFIG:Release>:PANDA_PLATFORM_GLFW>
  $<$<CONFIG:Release>:PANDA_OPENGL>
  $<$<CONFIG:Release>:PANDA_OPENGL_VERSION_MAJOR=4>
  $<$<CONFIG:Release>:PANDA_OPENGL_VERSION_MINOR=0>
  $<$<CONFIG:Release>:PANDA_NO_BUDEG>
  $<$<CONFIG:Release>:_GLFW_COCOA>
)
target_link_directories("GLFW" PRIVATE
)
target_link_libraries("GLFW"
)
target_compile_options("GLFW" PRIVATE
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>
)
if(CMAKE_BUILD_TYPE STREQUAL Release)
  set_target_properties("GLFW" PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE False
    INTERPROCEDURAL_OPTIMIZATION False
  )
endif()