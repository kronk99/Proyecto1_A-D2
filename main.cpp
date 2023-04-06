//
// Created by huevitoentorta on 17/03/23.
// revisar si en el cmake serial.cc no me hace daño al programa,ver el cmake
//ARREGLAR E INCLUDE DE SERIAL
#include <iostream>
#include <csignal>
#include <unistd.h>
#include "libserial/SerialStream.h"
//#include <SDL2/SDL.h>
#include <thread>
#include "Juego.h"
#include "Game.h"
using namespace std;
int main(int argc , char *argv[]){
    Juego *juego = new Juego(); //debo hacer juego singleton para meterlo en
    //el thread.
    juego->setFlag();
    thread juegos(&Juego::receiveMsg , *juego);
    juegos.join();
    /*
    constexpr const char* const SERIAL_PORT_1 = "/dev/ttyUSB0" ;
    SerialStream serial_stream ;
    try
    {
        // Open the Serial Port at the desired hardware port.
        serial_stream.Open(SERIAL_PORT_1) ;
    }
    catch (const OpenFailed&)
    {
        std::cerr << "The serial port did not open correctly." << std::endl ;
        return EXIT_FAILURE ;
    }
    // Set the baud rate of the serial port.
    serial_stream.SetBaudRate(BaudRate::BAUD_9600) ;

    // Set the number of data bits.
    serial_stream.SetCharacterSize(CharacterSize::CHAR_SIZE_8) ;

    // Turn off hardware flow control.
    serial_stream.SetFlowControl(FlowControl::FLOW_CONTROL_NONE) ;

    // Disable parity.
    serial_stream.SetParity(Parity::PARITY_NONE) ;

    // Set the number of stop bits.

    serial_stream.SetStopBits(StopBits::STOP_BITS_1) ;
    //CODIGO FUNCIONAL, PRIMER ARDUINO ENVIA A C++ PARA HACER LA COENXION
    //LUEGO DE ESO C++ PUEDE ENVIAR LO QUE QUIERA.
    while(serial_stream.rdbuf()->in_avail() == 0){
        usleep(2000);
    }
    while(serial_stream.IsDataAvailable()){
        char data_byte ;
        // Read a single byte of data from the serial port.
        serial_stream.get(data_byte) ;
        if(data_byte =='R') { //esto me esta jodiendo los numeros
            cout << "sistema listo" << endl;
        }
    }
    //probar hacer un flush si no sirve
    string numero ="el 8 es";
    serial_stream<<numero<<std::endl;
    serial_stream.DrainWriteBuffer();
    /*
    static  int loops = 0;
    while(true){
        if(loops<65){
            string numero ="el 3 es";
            cout<<"el tamaño es:"<<numero.size()<<endl;
            serial_stream<<numero<<std::endl;
            serial_stream.FlushOutputBuffer();
            loops+=1;
        }
    }*/

    //EL BUFER DE ARDUINO TIENE 64 BITS DE ESPACIO PARA LEER, puede ser por eso los
    //64 loops
    //OTRA VARIABLE A TOMAR EN CUENTA ES QUE PUEDE QUE LA CONEXION SE CAIGA MAS
    //RAPIDO DE LO QUE ENVIA, POR ESO SE NECESITA EL CICLO WHILE.
    //TRATAR DE METERLO A UN CICLO WHILE CON BANDERA QUE DURE 3 ITERACIONES 1
    //INCLUSIVE, ESE VA TAMBIEN DENTRO UN CICLO WHILE INFINITO A VER SI ES ESO
    //DE LA CONEXION
/*CODIGO FUNCIONAL ACA ABAJO*******************************************
    int flag = 0;
    int cicles = 0;
    while(flag ==0){
        //cambiarlo a un if este ciclo while
        if(serial_stream.rdbuf()->in_avail() != 0){
            usleep(2000) ;
            int multiplier = 10; //PREGUNTAR AL TUTOR SI HACERLA CONST
            int dato=0; //inicia en 0
            //POR QUE NO SE SI AL REINICIAR EL CICLO WHILE SE ELIMINA DEL HEAP.
            while(serial_stream.IsDataAvailable()){ //imprime 4 nulls por algun
                //NOTA PARA MAÑANA, SI NO LEER EL CICLO Y CONCATENAR STRINGS.
                //NOTA 2 probar si o si concatenar o enviar data y leerla.
                //SI NO SIRVE ASI, SIMPLEMENTE ENVIAR INTS Y QUE LOS LEA.

                // Variable to store data coming from the serial port.
                char data_byte ;
                // Read a single byte of data from the serial port.
                serial_stream.get(data_byte) ;
                int variable = int(data_byte)-48;
                if(variable >=0){ //esto me esta jodiendo los numeros
                    //cout<<"el numero como char es:"<<data_byte<<endl;
                    //cout<<"el numero es:"<<variable<<endl;
                    dato=dato * multiplier+variable;

                }
                usleep(1000) ;
            }
            cout<<"el numero final es:"<<dato<<endl;
        }
    }**********FIN DEL CODIGO FUNCIONAL*********************************
    */
    // Successful program completion.

// Create and open the serial port for communication.
    /*SerialPort   my_serial_port( "/dev/ttyS0" );
    SerialStream my_serial_stream( "/dev/ttyUSB0" );
    //my_serial_port.SetBaudRate( BaudRate::BAUD_9600 );
    my_serial_stream.SetBaudRate( BaudRate::BAUD_9600  );
    //my_serial_port.SetCharacterSize( CharacterSize::CHAR_SIZE_8 );
    my_serial_stream.SetCharacterSize( CharacterSize::CHAR_SIZE_8 );
    // Set the desired flow control type using a SetFlowControl() method call.
// Available flow control types are defined in SerialStreamConstants.h.
    //my_serial_port.SetFlowControl( FlowControl::FLOW_CONTROL_HARDWARE );
    my_serial_stream.SetFlowControl( FlowControl::FLOW_CONTROL_HARDWARE );
    // Set the desired parity type using a SetParity() method call.
// Available parity types are defined in SerialStreamConstants.h.
    //my_serial_port.SetParity( Parity::PARITY_ODD);
    my_serial_stream.SetParity( Parity::PARITY_ODD);
    //my_serial_port.SetStopBits(StopBits::STOP_BITS_1);
    my_serial_stream.SetStopBits(StopBits::STOP_BITS_1);
    int timeout = 25;
    char nextchar;
    //my_serial_port.ReadByte(nextchar,25);
    my_serial_stream.get(nextchar);
    cout<<nextchar<<endl;*/
    /*
    Game *game = new Game();
    //hice el init como el verdadero constructor de la ventana de juegoxd.
    game->init("juego1" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ,600 ,600 ,false);
    while(game->running()){
        game->eventHandler(); //currently not working
        game->update();
        game->render();
    }
    game->clean();
*/




}
