#include "../include/ControladorUsuarios.h"

ControladorUsuarios::ControladorUsuarios(){}


bool ControladorUsuarios::altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento){
        if (coleccionUsuarios.find(claveBuscada) != coleccionUsuarios.end()){ //entonces existe
            return false;
        } else {
            c = Cliente(nickname, contrasena, nombre, email, apellido, documento); //create
            coleccionUsuarios[nickname] = c; //add
        } 
}