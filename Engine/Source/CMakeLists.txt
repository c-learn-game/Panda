include(../../Scripts/CMake/PandaGlobal.cmake)


set(FileFilters)
list(APPEND FileFilters "./**.cpp" "./**.h")

file(GLOB_RECURSE SOURCE_FILES ${FileFilters})
panda_init_files_group("${CMAKE_CURRENT_SOURCE_DIR}" "${SOURCE_FILES}")
add_library(Panda STATIC "${SOURCE_FILES}")

set_target_properties(Panda PROPERTIES FOLDER "Engine")

add_compile_definitions(PANDA_OPENGL)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        "../Third/glm/glm"
)

target_link_libraries(Panda GLFW Glad)