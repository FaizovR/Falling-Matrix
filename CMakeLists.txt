cmake_minimum_required(VERSION 3.15)
project(LAB_1_V2)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -lncurses" )
set(CMAKE_CXX_STANDARD 17)

file(GLOB LAB_1_V2
        src/*.c
        includes/*.h)

add_executable(LAB_1_V2 src/main.cpp includes/Lab_1.h src/Game.cpp includes/Game.h src/Line.cpp includes/Line.h src/Point.cpp includes/Point.h src/Exception.cpp includes/Exception.h src/GameEngine.cpp src/UserInputUtilities.cpp)
