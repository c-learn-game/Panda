include (../../Scripts/CMake/PandaGlobal.cmake)

message(STATUS "collect Glad source files")

set(AllFiles)
list(APPEND AllFiles "glad/src/**.c" "glad/include/**.h")
file(GLOB_RECURSE SOURCE_FILES ${AllFiles})
set(GLAD_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glad")
panda_init_files_group("${GLAD_BASE_DIR}" ${SOURCE_FILES})

add_library("Glad" STATIC
    "${SOURCE_FILES}"
)

include_directories(
  "${GLAD_BASE_DIR}/include"
)

target_include_directories("GLFW" PUBLIC
    "glad/include"
)