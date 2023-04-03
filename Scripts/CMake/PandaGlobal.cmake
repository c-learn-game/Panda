function(to_relativepath SOURCE_FILES)
    foreach(fileItem ${ARGN})
        string(REPLACE "${SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    endforeach()
endfunction(to_relativepath)


# 参数是filters
function(panda_init_files_group BASE_DIR)
    message(STATUS "Add source files in base dir ${BASE_DIR}")
    foreach(fileItem ${ARGN})
        # 先获取文件的绝对路径
        get_filename_component(ABS_FILE_PATH "${fileItem}" ABSOLUTE "${BASE_DIR}")
        # 获取文件的文件夹路径
        get_filename_component(FILE_PATH "${ABS_FILE_PATH}" PATH)
        # 替换基础路径得到相对路径
        string(REPLACE "${BASE_DIR}" "" GROUP "${FILE_PATH}")
        # 替换windows路径分隔符
        string(REPLACE "/" "\\" GROUP "${GROUP}")
        # 添加到文件夹group
        set(GROUP "${GROUP}")
        source_group("${GROUP}" FILES "${fileItem}")
        message(STATUS "file: ${ABS_FILE_PATH} added to group ${GROUP}")
    endforeach()
endfunction()