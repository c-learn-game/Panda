include(./Scripts/CMake/PandaGlobal.cmake)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (CMAKE_BUILD_TYPE)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_definitions( PANDA_DEBUG )
    else()
        add_compile_definitions( PANDA_RELEASE PANDA_NO_DEBUG )
    endif()
endif()

if(APPLE)
    set(CMAKE_CXX_FLAGS "-framework Cocoa -framework IOKit")
endif()

set(FileFilters)
list(APPEND FileFilters "./${CMAKE_PROJECT_NAME}/**.cpp" "./${CMAKE_PROJECT_NAME}/**.h")
file(GLOB_RECURSE PANDA_SOURCE_FILES ${FileFilters})
panda_init_files_group("${CMAKE_CURRENT_SOURCE_DIR}" "${PANDA_SOURCE_FILES}")