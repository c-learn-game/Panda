include(SimpleApp/SimpleApp.cmake)

set_target_properties(SimpleApp PROPERTIES FOLDER "Test")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SimpleApp)