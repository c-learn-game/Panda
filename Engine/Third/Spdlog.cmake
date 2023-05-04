include(../../SCripts/CMake/PandaGlobal.cmake)

message(STATUS "collect Spdlog source files")

set(AllFiles)
list(APPEND AllFiles
        "spdlog/include/spdlog/**.h"
        )

file(GLOB_RECURSE SOURCE_FILES ${AllFiles})
set(GLFW_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include/spdlog")
panda_init_files_group("${GLFW_BASE_DIR}" ${SOURCE_FILES})

add_library("Spdlog" INTERFACE)

target_include_directories("GLFW" PUBLIC
    "spdlog/include"
)