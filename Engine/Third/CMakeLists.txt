include(GLFW.cmake)
include(Glad.cmake)
include(Glm.cmake)
include(Spdlog.cmake)

set_target_properties(GLFW PROPERTIES FOLDER "Engine/Third")
set_target_properties(Glad PROPERTIES FOLDER "Engine/Third")
set_target_properties(Glm PROPERTIES FOLDER "Engine/Third")
set_target_properties(Spdlog PROPERTIES FOLDER "Engine/Third")