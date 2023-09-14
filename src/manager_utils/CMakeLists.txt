cmake_minimum_required(VERSION 3.5.1)

project(manager_utils LANGUAGES CXX)

set(_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include) 
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src) 

add_library(
    ${PROJECT_NAME} STATIC

        ${_INC_DIR}/manager_utils/drawing/Image.h
        ${_INC_DIR}/manager_utils/drawing/Text.h
        ${_INC_DIR}/manager_utils/drawing/Widget.h
        ${_INC_DIR}/manager_utils/managers/config/DrawManagerCfg.h
        ${_INC_DIR}/manager_utils/managers/config/ManagerHandlerCfg.h
        ${_INC_DIR}/manager_utils/managers/config/ResourceManagerCfg.h
        ${_INC_DIR}/manager_utils/managers/DrawManager.h
        ${_INC_DIR}/manager_utils/managers/ManagerBase.h
        ${_INC_DIR}/manager_utils/managers/ManagerHandler.h
        ${_INC_DIR}/manager_utils/managers/ResourceManager.h

        ${_SRC_DIR}/drawing/Image.cpp
        ${_SRC_DIR}/drawing/Text.cpp
        ${_SRC_DIR}/drawing/Widget.cpp
        ${_SRC_DIR}/managers/DrawManager.cpp
        ${_SRC_DIR}/managers/ManagerHandler.cpp
        ${_SRC_DIR}/managers/ResourceManager.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC 
            ${_INC_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
        PUBLIC 
            sdl_utils
)
