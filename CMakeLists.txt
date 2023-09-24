cmake_minimum_required(VERSION 3.5.1)

project(chess LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

find_package(SDL2 REQUIRED)

if(UNIX)
    set(SDL2_image_name SDL2_image)
    set(SDL2_ttf_name SDL2_ttf)
    set(SDL2_mixer_name SDL2_mixer)
elseif(WIN32 OR APPLE)
    set(SDL2_image_name SDL2_IMAGE)
    set(SDL2_ttf_name SDL2_TTF)
    set(SDL2_mixer_name SDL2_MIXER)
endif()

find_package(${SDL2_image_name} REQUIRED)
find_package(${SDL2_ttf_name} REQUIRED)
find_package(${SDL2_mixer_name} REQUIRED)

file(COPY resources DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src) 

add_executable(
    ${PROJECT_NAME} 
        ${_SRC_DIR}/common/CommonDefines.h
        
        ${_SRC_DIR}/engine/config/EngineConfig.h
        ${_SRC_DIR}/engine/Engine.h
        ${_SRC_DIR}/engine/EngineConfigLoader.h

        ${_SRC_DIR}/game/board/ChessBoard.h
        ${_SRC_DIR}/game/chess_defines/ChessDefines.h
        ${_SRC_DIR}/game/chess_pieces/types/ChessPiece.h
        ${_SRC_DIR}/game/chess_pieces/PieceHandler.h
        ${_SRC_DIR}/game/config/GameConfig.h
        ${_SRC_DIR}/game/utility/BoardPos.h
        ${_SRC_DIR}/game/utility/BoardUtils.h
        ${_SRC_DIR}/game/proxies/GameBoardProxy.h
        ${_SRC_DIR}/game/Game.h
        
        ${_SRC_DIR}/engine/Engine.cpp
        ${_SRC_DIR}/engine/EngineConfigLoader.cpp
        
        ${_SRC_DIR}/game/board/ChessBoard.cpp
        ${_SRC_DIR}/game/chess_pieces/types/ChessPiece.cpp
        ${_SRC_DIR}/game/chess_pieces/PieceHandler.cpp
        ${_SRC_DIR}/game/utility/BoardUtils.cpp
        ${_SRC_DIR}/game/Game.cpp
        
        ${_SRC_DIR}/main.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
        PRIVATE 
            ${_SRC_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE 
            manager_utils
)

add_subdirectory(src/utils)
add_subdirectory(src/sdl_utils)
add_subdirectory(src/manager_utils)
