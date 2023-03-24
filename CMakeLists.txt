cmake_minimum_required(VERSION 3.24)
project(Proyecto1_A_D2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proyecto1_A_D2
        main.cpp Game.h Game.cpp)
target_link_libraries(Proyecto1_A_D2 SDL2main SDL2)
