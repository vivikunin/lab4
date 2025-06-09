#include "../include/ControladorUsuarios.h"
#include "Cliente.h"
#include"Propietario.h"
#include "IInmobiliarias.h"

ControladorUsuarios::ControladorUsuarios(){}

ControladorUsuarios::~ControladorUsuarios(){
    for (std::map<std::string, Usuario*>::iterator it = coleccionUsuarios.begin(); it != coleccionUsuarios.end(); ++it) {
        delete it->second;
    }
    coleccionUsuarios.clear();
}

ControladorUsuarios* ControladorUsuarios::instance = NULL;

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instance == NULL) {
        instance = new ControladorUsuarios();
    }
    return instance;
}

Propietario* ControladorUsuarios::getPropietarioRecordado() const { 
    return propietarioRecordado; 
}

void ControladorUsuarios::finalizarAltaUsuario() { 
    propietarioRecordado = nullptr; 
    inmobiliariaRecordada = nullptr;
}

bool ControladorUsuarios::altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
        return false;
    } else {
        Cliente* c = new Cliente(nickname, contrasena, nombre, email, apellido, documento); //create
        coleccionUsuarios[nickname] = c; //add
        
    } 
}

bool ControladorUsuarios::altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
            return false;
    } else {
        Propietario* p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono); //create
        coleccionUsuarios[nickname] = p; //add
        propietarioRecordado = p;
    } 
}

bool ControladorUsuarios::altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono){
    if (coleccionUsuarios.find(nickname) != coleccionUsuarios.end()){ //entonces existe
            return false;
    } else {
        Inmobiliaria* i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono); //create
        coleccionUsuarios[nickname] = i; //add
        inmobiliariaRecordada = i;
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
        res.insert(it->second->getDTUsuario());
    }
}

void ControladorUsuarios::agregarSuscriptor(std::string nickname, Suscriptor* s) {
        suscriptores[nickname] = s;
}

void ControladorUsuarios::consultarNotificaciones(std::string nickname){
    std::map<std::string, Suscriptor*>::iterator it = suscriptores.find(nickname);
    Suscriptor* s = it->second;
    std::set<Notificacion> notis = s->getNotificaciones();

    for(std::set<Notificacion>::iterator it =notis.begin(); it!=notis.end(); it++){
        std::cout << "Inmobiliaria: " << n.nicknameInmobiliaria << "\n";
        std::cout << "Código: " << n.codigo << "\n";
        std::cout << "Texto: " << n.texto << "\n";
        std::cout << "Tipo Publicación: " << (n.tPublicacion == TipoPublicacion::ALQUILER ? "Alquiler" : "Venta") << "\n";
        std::cout << "Tipo Inmueble: " << (n.tInmueble == TipoInmueble::CASA ? "Casa" : "Apartamento") << "\n\n";
    }
}

void ControladorUsuarios::representarPropietario(std::string nicknamePropietario){
    Propietario* prop = coleccionUsuarios.find(nicknamePropietario);
    inmobiliariaRecordada.linkPropietario(prop);
}