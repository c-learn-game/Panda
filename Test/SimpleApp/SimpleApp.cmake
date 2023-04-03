add_executable("SimpleApp"
  "SimpleApp/SimpleApp.cpp"
)

if(APPLE)
    set(CMAKE_CXX_FLAGS "-framework Cocoa -framework IOKit")
endif()

target_link_libraries(
        SimpleApp
        Panda
        GLFW
        Glad
)