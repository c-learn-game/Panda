cmake_minimum_required(VERSION 3.8)

set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

set(CMAKE_MSVC_RUNTIME_LIBRARY "")
set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")
set(CMAKE_CXX_FLAGS_RELEASE "")
set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("Panda")
add_subdirectory(Engine/Third)
#add_subdirectory(Engine/Source)
add_subdirectory(Test)