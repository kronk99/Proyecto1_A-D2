cmake_minimum_required(VERSION 3.24)
project(Proyecto1_A_D2)

set(CMAKE_CXX_STANDARD 14)


add_executable(Proyecto1_A_D2
        main.cpp Game.h Game.cpp libserial/SerialStreamBuf.h libserial/SerialStream.h libserial/SerialPortConstants.h libserial/SerialStream.cpp libserial/SerialStreamBuf.cpp libserial/SerialPort.h libserial/SerialPort.cpp libserial/SerialPort.cpp Enemigos/enemigo.h Enemigos/enemigo.cpp arduinoHndlr.h arduinoHndlr.cpp Juego.cpp textureLoader.cpp Player.cpp Lista.h Lista.cpp Bullet.cpp BList.h Bnode.h Bnode.cpp BList.cpp Bcollector.cpp Enemigos/enemyList.cpp Enemigos/enemyHndlr.h Enemigos/enemyHndlr.cpp)
target_link_libraries(Proyecto1_A_D2 SDL2main SDL2 SDL2_image)
#borre el SDL2 QUE IBA PEGADO A MAIN A VER QUE PASA

