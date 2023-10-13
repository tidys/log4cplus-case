cmake_minimum_required(VERSION 3.8)
project("SticPos")
add_definitions("-DUNICODE" "-D_UNICODE")
# add_compile_options(/utf-8)
# find_package(Qt5 COMPONENTS Core Gui Widgets Sql)
set(qsp_header_files

    # mainwindow.h
    core/qsplogger.h
)

set(qsp_source_files
    main.cpp

    # mainwindow.cpp
    core/qsplogger.cpp
)

set(qsp_ui_files
)
file(GLOB_RECURSE src ${CMAKE_CURRENT_LIST_DIR}/../../include/log4cplus/*.h)
source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/../../ FILES ${src})
add_executable(${PROJECT_NAME} ${src} ${qsp_header_files} ${qsp_source_files} ${qsp_ui_files})

# target_link_libraries(${PROJECT_NAME} PRIVATE
# Qt5::Core
# Qt5::Gui
# Qt5::Widgets
# Qt5::Sql
# )
add_library(log4cplusU SHARED IMPORTED GLOBAL)
set_target_properties(log4cplusU PROPERTIES
    IMPORTED_IMPLIB_DEBUG ${CMAKE_CURRENT_LIST_DIR}/../../lib/log4cplusUD.lib
    IMPORTED_LOCATION_DEBUG ${CMAKE_CURRENT_LIST_DIR}/../../bin/log4cplusUD.dll
)
target_link_libraries(${PROJECT_NAME} PUBLIC log4cplusU)