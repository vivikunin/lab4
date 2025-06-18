#include "../include/ControladorUsuarios.h"
#include "Cliente.h"
#include"Propietario.h"
#include "IInmobiliarias.h"
#include "Suscriptor.h"
#include "Factory.h"
#include <iostream>
#include <map>

ControladorUsuarios::ControladorUsuarios(){}

ControladorUsuarios::~ControladorUsuarios(){
    for (std::map<std::string, Usuario*>::iterator it = coleccionUsuarios.begin(); it != coleccionUsuarios.end(); ++it) {
        delete it->second;
    }
    coleccionUsuarios.clear();
    delete instance;
    instance = NULL;
}

ControladorUsuarios* ControladorUsuarios::instance = NULL;

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instance == NULL) {
        instance = new ControladorUsuarios();
    }
    return instance;
}

Usuario* ControladorUsuarios::getUsuarioRecordado() const { 
    return usuarioRecordado; 
}

void ControladorUsuarios::finalizarAltaUsuario() { 
    usuarioRecordado = nullptr; 
    inmobiliariaRecordada = nullptr;
}

bool ControladorUsuarios::altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
        return false;
    } else {
        Cliente* c = new Cliente(nickname, contrasena, nombre, email, apellido, documento); //create
        coleccionUsuarios[nickname] = c; //add
        return true;
    } 
}

bool ControladorUsuarios::altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
            return false;
    } else {
        Propietario* p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono); //create
        coleccionUsuarios.insert(std::make_pair(dynamic_cast<Usuario*>(p)->getNickname(),dynamic_cast<Usuario*>(p))); 
        usuarioRecordado = dynamic_cast<Usuario*>(p);
        return true;
    } 
}

bool ControladorUsuarios::altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
            return false;
    } else {
        Inmobiliaria* i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono); //create
        coleccionUsuarios[nickname] = i; //add
        inmobiliariaRecordada = i;
        Factory::getInstance()->getControladorInmobiliarias()->agregarInmobiliariaColeccion(i);
        return true;
    } 
}

void ControladorUsuarios::eliminarUsuario(string nickname){
    Usuario* aRemover=coleccionUsuarios.find(nickname)->second;
    coleccionUsuarios.erase(nickname);
    delete aRemover;
} 

std::set<DTUsuario> ControladorUsuarios::listarPropietarios(){
    std::set<DTUsuario> res;
    for(std::map<std::string, Usuario*>::iterator it =coleccionUsuarios.begin(); it!=coleccionUsuarios.end(); it++){
        if(dynamic_cast<Propietario*>((it->second))!=NULL){
            res.insert(it->second->getDTUsuario());
        }
    }
    return res;
}

std::list<DTNotificacion> ControladorUsuarios::consultarNotificaciones(std::string nickname){
    std::map<std::string, Usuario*>::iterator it = coleccionUsuarios.find(nickname);
    return dynamic_cast<Suscriptor*>(it->second)->getNotificaciones();
}

void ControladorUsuarios::representarPropietario(std::string nicknamePropietario){
    Propietario* prop = dynamic_cast<Propietario*>((coleccionUsuarios.find(nicknamePropietario))->second);
    inmobiliariaRecordada->linkPropietario(prop);
}

void ControladorUsuarios::recordarUsuario(std::string nicknamePropietario){
    std::map <std::string, Usuario*>::iterator it =  coleccionUsuarios.find(nicknamePropietario);
    usuarioRecordado= it->second;
}

void ControladorUsuarios::olvidarUsuarioRecordado(){
    usuarioRecordado=NULL;
}