cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
project(Test)
add_subdirectory(Engine/Third)
add_subdirectory(Engine/Source)

include(./Scripts/CMake/PandaApplication.cmake)

add_executable(Test ${PANDA_SOURCE_FILES})

target_link_libraries(
        Test
        Panda
)