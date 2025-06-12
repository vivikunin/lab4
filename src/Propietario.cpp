#include "Propietario.h"
#include "Suscriptor.h"
#include "Inmueble.h"
#include "DTInmuebleListado.h"
#include <map>
#include <string>

class Inmobiliaria;

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono):
Suscriptor(nickname, contrasena, nombre, email){
    this->cuentaBancaria=cuentaBancaria;
    this->telefono=telefono;
}

void Propietario::añadirPropiedad(Inmueble* i){
    misPropiedades.insert({i->getCodigo(),i});
}        

void Propietario::eliminarPropiedad(int codigo){
    misPropiedades.erase(codigo);
}


std::string Propietario::getCuentaBancaria(){
    return cuentaBancaria;
}

std::string Propietario::getTelefono(){
    return telefono;
}

void Propietario::notificar(Notificacion* n){
    this->misNotificaciones.insert(n);
}

std::set<DTInmuebleListado> Propietario::getInmueblesNoAdmin(Inmobiliaria* i){
    std::set<DTInmuebleListado> res;
    for (std::map<int,Inmueble*>::iterator it = misPropiedades.begin(); it!=misPropiedades.end(); it++){
        bool administrado = it->second->esAdminitrado(i);
        if(!administrado){
            int codigo = it->second->getCodigo();
            std::string direccion = it->second->getDireccion();
            res.insert(DTInmuebleListado(codigo,direccion,this->getNickname()));
        }
    }
    return res;
}
