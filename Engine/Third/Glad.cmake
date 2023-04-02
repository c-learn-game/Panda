add_library("Glad" STATIC
  "Engine/Third/glad/src/glad.c"
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  set_target_properties("Glad" PROPERTIES
    OUTPUT_NAME "Glad"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
    LIBRARY_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
    RUNTIME_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Debug-macosx-x86_64"
  )
endif()
target_include_directories("Glad" PRIVATE
)
target_compile_definitions("Glad" PRIVATE
  $<$<CONFIG:Debug>:PANDA_PLATFORM_GLFW>
  $<$<CONFIG:Debug>:PANDA_OPENGL>
  $<$<CONFIG:Debug>:PANDA_OPENGL_VERSION_MAJOR=4>
  $<$<CONFIG:Debug>:PANDA_OPENGL_VERSION_MINOR=0>
  $<$<CONFIG:Debug>:PANDA_BUDEG>
)
target_link_directories("Glad" PRIVATE
)
target_link_libraries("Glad"
)
target_compile_options("Glad" PRIVATE
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-g>
)
if(CMAKE_BUILD_TYPE STREQUAL Release)
  set_target_properties("Glad" PROPERTIES
    OUTPUT_NAME "Glad"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
    LIBRARY_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
    RUNTIME_OUTPUT_DIRECTORY "/Users/chendebi/Develop/Panda/Bin/Release-macosx-x86_64"
  )
endif()
target_include_directories("Glad" PRIVATE
        $<$<CONFIG:Debug>:/Users/chendebi/Develop/Panda/Engine/Third/glad/include>
)
target_compile_definitions("Glad" PRIVATE
  $<$<CONFIG:Release>:PANDA_PLATFORM_GLFW>
  $<$<CONFIG:Release>:PANDA_OPENGL>
  $<$<CONFIG:Release>:PANDA_OPENGL_VERSION_MAJOR=4>
  $<$<CONFIG:Release>:PANDA_OPENGL_VERSION_MINOR=0>
  $<$<CONFIG:Release>:PANDA_NO_BUDEG>
)
target_link_directories("Glad" PRIVATE
)
target_link_libraries("Glad"
)
target_compile_options("Glad" PRIVATE
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-O2>
)