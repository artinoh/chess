cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME chess_v2)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 17)

include_directories(headers assets chess)

set(SOURCE_FILES src/main.cpp src/StateMachine.cpp headers/StateMachine.h headers/State.h src/MainMenuState.cpp headers/MainMenuState.h headers/Definitions.h src/AssetManager.cpp headers/AssetManager.h src/GameState.cpp headers/GameState.h src/Game.cpp headers/Game.h src/InputManager.cpp headers/InputManager.h chess/Chess.cpp chess/Chess.h chess/Piece.cpp chess/Piece.h chess/Pawn.cpp chess/Pawn.h chess/Rook.cpp chess/Rook.h chess/Knight.cpp chess/Knight.h chess/Bishop.cpp chess/Bishop.h chess/King.cpp chess/King.h chess/Queen.cpp chess/Queen.h chess/Computer.cpp src/GameOverState.cpp headers/GameOverState.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()