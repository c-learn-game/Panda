include(../../Scripts/CMake/PandaGlobal.cmake)


set(FileFilters)
list(APPEND FileFilters "./**.cpp" "./**.h")

file(GLOB_RECURSE SOURCE_FILES ${FileFilters})
panda_init_files_group("${CMAKE_CURRENT_SOURCE_DIR}" "${SOURCE_FILES}")
add_library(Panda STATIC "${SOURCE_FILES}")

set_target_properties(Panda PROPERTIES FOLDER "Engine")

#set(ApplicationVersion "0.0.0.0" PARENT_SCOPE)

add_compile_definitions(
        PANDA_APPLICATION_NAME="${CMAKE_PROJECT_NAME}"
        #PANDA_APPLICATION_VERSION="${ApplicationVersion}"
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


target_include_directories(
        Panda PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(Panda PROPERTIES FOLDER "Engine/Engine")
set_target_properties(Panda PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Panda GLFW Glad Spdlog)