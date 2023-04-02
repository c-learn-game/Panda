add_executable("SimpleApp"
  "Test/SimpleApp/SimpleApp.cpp"
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  add_dependencies("SimpleApp"
    "Panda"
    "GLFW"
    "Glad"
  )
  set_target_properties("SimpleApp" PROPERTIES
    OUTPUT_NAME "SimpleApp"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
    LIBRARY_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
    RUNTIME_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
  )
endif()
target_include_directories("SimpleApp" PRIVATE
  $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Source>
  $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Third/glfw/include>
  $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Third/glad/include>
  $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Third/glm/glm>
)
target_compile_definitions("SimpleApp" PRIVATE
  $<$<CONFIG:Debug>:PANDA_PLATFORM_GLFW>
  $<$<CONFIG:Debug>:PANDA_OPENGL>
  $<$<CONFIG:Debug>:PANDA_OPENGL_VERSION_MAJOR=4>
  $<$<CONFIG:Debug>:PANDA_OPENGL_VERSION_MINOR=0>
  $<$<CONFIG:Debug>:PANDA_BUDEG>
)
target_link_directories("SimpleApp" PRIVATE
)
target_link_libraries("SimpleApp"
  $<$<CONFIG:Debug>:Panda>
  $<$<CONFIG:Debug>:GLFW>
  $<$<CONFIG:Debug>:Glad>
  $<$<CONFIG:Debug>:AppKit.framework>
  $<$<CONFIG:Debug>:IOKit.framework>
  $<$<CONFIG:Debug>:CoreFoundation.framework>
  $<$<CONFIG:Debug>:OpenGL.framework>
)
target_compile_options("SimpleApp" PRIVATE
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  set_target_properties("SimpleApp" PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE False
    INTERPROCEDURAL_OPTIMIZATION False
  )
endif()
if(CMAKE_BUILD_TYPE STREQUAL Release)
  add_dependencies("SimpleApp"
    "Panda"
    "GLFW"
    "Glad"
  )
  set_target_properties("SimpleApp" PROPERTIES
    OUTPUT_NAME "SimpleApp"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
    LIBRARY_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
    RUNTIME_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
  )
endif()
target_include_directories("SimpleApp" PRIVATE
  $<$<CONFIG:Release>:/Users/chendebi/Develop/Panda/Engine/Source>
  $<$<CONFIG:Release>:/Users/chendebi/Develop/Panda/Engine/Third/glfw/include>
  $<$<CONFIG:Release>:/Users/chendebi/Develop/Panda/Engine/Third/glad/include>
  $<$<CONFIG:Release>:/Users/chendebi/Develop/Panda/Engine/Third/glm/glm>
)
target_compile_definitions("SimpleApp" PRIVATE
  $<$<CONFIG:Release>:PANDA_PLATFORM_GLFW>
  $<$<CONFIG:Release>:PANDA_OPENGL>
  $<$<CONFIG:Release>:PANDA_OPENGL_VERSION_MAJOR=4>
  $<$<CONFIG:Release>:PANDA_OPENGL_VERSION_MINOR=0>
  $<$<CONFIG:Release>:PANDA_NO_BUDEG>
)
target_link_directories("SimpleApp" PRIVATE
)
target_link_libraries("SimpleApp"
  $<$<CONFIG:Release>:Panda>
  $<$<CONFIG:Release>:GLFW>
  $<$<CONFIG:Release>:Glad>
  $<$<CONFIG:Release>:AppKit.framework>
  $<$<CONFIG:Release>:IOKit.framework>
  $<$<CONFIG:Release>:CoreFoundation.framework>
  $<$<CONFIG:Release>:OpenGL.framework>
)
target_compile_options("SimpleApp" PRIVATE
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>
)
if(CMAKE_BUILD_TYPE STREQUAL Release)
  set_target_properties("SimpleApp" PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE False
    INTERPROCEDURAL_OPTIMIZATION False
  )
endif()