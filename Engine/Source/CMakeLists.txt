include(../../Scripts/CMake/PandaGlobal.cmake)


set(FileFilters)
list(APPEND FileFilters "./**.cpp" "./**.h")

file(GLOB_RECURSE SOURCE_FILES ${FileFilters})
panda_init_files_group("${CMAKE_CURRENT_SOURCE_DIR}" "${SOURCE_FILES}")
add_library(Panda STATIC "${SOURCE_FILES}")

set_target_properties(Panda PROPERTIES FOLDER "Engine")

add_compile_definitions(
        PANDA_OPENGL
        PANDA_PLATFORM_GLFW
)

if(APPLE)
    add_compile_definitions(
            PANDA_OPENGL_VERSION_MAJOR=4
            PANDA_OPENGL_VERSION_MINOR=0
    )
elseif(WIN32)
    add_compile_definitions(
            PANDA_OPENGL_VERSION_MAJOR=4
            PANDA_OPENGL_VERSION_MINOR=5
    )
endif()

if (CMAKE_BUILD_TYPE)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_definitions( PANDA_DEBUG )
    else()
        add_compile_definitions( PANDA_RELEASE PANDA_NO_DEBUG )
    endif()
endif()

target_include_directories(
        Panda PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(Panda PROPERTIES FOLDER "Engine/Engine")
target_link_libraries(Panda GLFW Glad Glm Spdlog)