//
// Created by huevitoentorta on 05/04/23.
//

#include "arduinoHndlr.h"
arduinoHndlr ::arduinoHndlr(){
}
void arduinoHndlr::startHandler() {
    constexpr const char* const SERIAL_PORT_1 = "/dev/ttyUSB0" ;
    try{
        // Open the Serial Port at the desired hardware port.
        serial_stream.Open(SERIAL_PORT_1) ;
    }
    catch (const OpenFailed&) {
        std::cerr << "The serial port did not open correctly." << std::endl;
        //return EXIT_FAILURE ;
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
    while(serial_stream.rdbuf()->in_avail() == 0){
        usleep(2000);
        cout<<"esperando conexion a arduino"<<endl;
    }
    while(serial_stream.IsDataAvailable()){
        char data_byte ;
        // Read a single byte of data from the serial port.
        serial_stream.get(data_byte) ;
        if(data_byte =='R') { //esto me esta jodiendo los numeros
            cout << "sistema listo" << endl;
        }
    }
    cout<<"conexion exitosa"<<endl;
}
void arduinoHndlr::sendtoArduino(string datos) {
    serial_stream<<datos<<std::endl;
    serial_stream.DrainWriteBuffer();
}
int arduinoHndlr::receivefromArduino() {
    if(serial_stream.rdbuf()->in_avail() != 0){
        usleep(1000) ;
        int multiplier = 10; //PREGUNTAR AL TUTOR SI HACERLA CONST
        int dato=0; //inicia en 0
        //POR QUE NO SE SI AL REINICIAR EL CICLO WHILE SE ELIMINA DEL HEAP.
        while(serial_stream.IsDataAvailable()) {
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
        return dato;
    }
    else{
        return -1;
    }
}
