include(../../SCripts/CMake/PandaGlobal.cmake)

message(STATUS "collect Glm source files")

set(AllFiles)
list(APPEND AllFiles
    "glm/glm/**.hpp" "glm/glm./**.h"
)

file(GLOB_RECURSE SOURCE_FILES ${AllFiles})
set(GLFW_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glm")
panda_init_files_group("${GLFW_BASE_DIR}" ${SOURCE_FILES})

add_library("Glm" INTERFACE
    "${SOURCE_FILES}"
)

target_include_directories("GLFW" PUBLIC
    "glm/glm"
)