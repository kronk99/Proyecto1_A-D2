cmake_minimum_required(VERSION 3.24)
project(Proyecto1_A_D2)

set(CMAKE_CXX_STANDARD 14)


add_executable(Proyecto1_A_D2
        main.cpp Game.h Game.cpp libserial/SerialStreamBuf.h libserial/SerialStream.h libserial/SerialPortConstants.h libserial/SerialStream.cpp libserial/SerialStreamBuf.cpp libserial/SerialPort.h libserial/SerialPort.cpp libserial/SerialPort.cpp enemigo.h enemigo.cpp arduinoHndlr.h arduinoHndlr.cpp Juego.cpp)
target_link_libraries(Proyecto1_A_D2 SDL2main SDL2)

