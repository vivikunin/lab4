#include "../include/ControladorUsuarios.h"
#include "Cliente.h"
#include"Propietario.h"
#include "IInmobiliarias.h"

ControladorUsuarios::ControladorUsuarios(){}

ControladorUsuarios::~ControladorUsuarios(){}

ControladorUsuarios* ControladorUsuarios::instance = NULL;

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instance == NULL) {
        instance = new ControladorUsuarios();
    }
    return instance;
}

bool ControladorUsuarios::altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
        return false;
    } else {
        c = Cliente(nickname, contrasena, nombre, email, apellido, documento); //create
        coleccionUsuarios[nickname] = c; //add
    } 
}

bool ControladorUsuarios::altaPropiedad(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
            return false;
    } else {
        p = Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono); //create
        coleccionUsuarios[nickname] = p; //add
    } 
}

bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
            return false;
    } else {
        i = Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono); //create
        coleccionUsuarios[nickname] = i; //add
    } 
}