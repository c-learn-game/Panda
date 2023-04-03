include(../../SCripts/CMake/PandaGlobal.cmake)

message(STATUS "collect GLFW source files")

add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

set(AllFiles)
list(APPEND AllFiles
    "glfw/src/context.c"
    "glfw/src/init.c"
    "glfw/src/input.c"
    "glfw/src/monitor.c"
    "glfw/src/vulkan.c"
    "glfw/src/window.c"
    "glfw/src/platform.c"
    "glfw/src/egl_context.c"
    "glfw/src/null_*.c"
)

if (WIN32)
    list(APPEND AllFiles
        "glfw/src/wgl_context.c"
        "glfw/src/osmesa_context.c"
        "glfw/src/win32_*.c"
    )
    add_compile_definitions(
        _GLFW_WIN32 
    )

elseif(APPLE)
    list(APPEND AllFiles
        "glfw/src/*.m"
        "glfw/src/posix_*.c"
        "glfw/src/posix_*.h"
        "glfw/src/cocoa*.h"
        "glfw/src/cocoa*.c"
        "glfw/src/osmesa_context.c"
        "glfw/src/internal.h"
    )
    add_compile_definitions(
        _GLFW_COCOA
    )
endif()

file(GLOB_RECURSE SOURCE_FILES ${AllFiles})
set(GLFW_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw")
panda_init_files_group("${GLFW_BASE_DIR}" ${SOURCE_FILES})

add_library("GLFW" STATIC
    "${SOURCE_FILES}"
)

target_include_directories("GLFW" PUBLIC
    "glfw/include"
)