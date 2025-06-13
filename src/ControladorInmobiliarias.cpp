#include "../include/ControladorInmobiliarias.h"
#include "Inmobiliaria.h"
#include "AdministraPropiedad.h"
#include "Factory.h"

#include <set>
using namespace std;

ControladorInmobiliarias* ControladorInmobiliarias::instance = NULL;

ControladorInmobiliarias* ControladorInmobiliarias::getInstance() {
    if (instance == NULL) {
        instance = new ControladorInmobiliarias();
    }
    return instance;
}

ControladorInmobiliarias::ControladorInmobiliarias(){}

ControladorInmobiliarias::~ControladorInmobiliarias(){}

set <DTUsuario> ControladorInmobiliarias::listarInmobiliarias(){
    set <DTUsuario> dtu;
    for (map<string, Inmobiliaria*>::iterator it = coleccionInmobiliarias.begin(); it != coleccionInmobiliarias.end(); it++){
        DTUsuario d = DTUsuario(it->second->getNickname(), it->second->getNombre());
        dtu.insert(d); 
    }
    return dtu;
}
        
bool ControladorInmobiliarias::altaPublicacion(string nickname, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio){
    map<string,Inmobiliaria*>::iterator it=coleccionInmobiliarias.find(nickname);
    return it->second->altaPublicacion(codigoInmueble, tipoPublicacion, texto, precio);
}
        
set <DTInmuebleAdministrado> ControladorInmobiliarias::listarInmueblesAdministrados(string nicknameInmobiliaria){
    map<string,Inmobiliaria*>::iterator i = coleccionInmobiliarias.find(nicknameInmobiliaria);
    if (i != coleccionInmobiliarias.end()) {
        return i->second->datosInmueblesAdministrados();
    } else {
        return {};
    }
}

set<DTInmuebleListado> ControladorInmobiliarias::listarInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria){
    Inmobiliaria* ci = coleccionInmobiliarias.find(nicknameInmobiliaria)->second;
    set<DTInmuebleListado> listInmuebles = ci->getInmueblesNoAdminPropietario();
    return listInmuebles;
}

void ControladorInmobiliarias::altaAdministraPropiedad(){

}

std::set<string> ControladorInmobiliarias::mostrarInmobiliariasNoSuscrito(string nickname){
    std::set<string> res;
    for(std::map<string, Inmobiliaria*>::iterator it = coleccionInmobiliarias.begin(); it!=coleccionInmobiliarias.end(); it++){
        if(!it->second->tieneSuscriptor(nickname)){
            res.insert(it->second->getNickname());
        }
    }
    return res;
}

std::set<string> ControladorInmobiliarias::mostrarInmobiliariasSuscrito(string nickname){
    std::set<string> res;
    for(std::map<string, Inmobiliaria*>::iterator it = coleccionInmobiliarias.begin(); it!=coleccionInmobiliarias.end(); it++){
        if(it->second->tieneSuscriptor(nickname)){
            res.insert(it->second->getNickname());
        }
    }
    return res;
}

void ControladorInmobiliarias::suscribirseAInmobiliaria(std::string nombreInmobiliaria){
    std::map<std::string, Inmobiliaria*>::iterator it = coleccionInmobiliarias.find(nombreInmobiliaria);
    it->second->suscribir(dynamic_cast<Suscriptor*>(Factory::getInstance()->getControladorUsuario()->getUsuarioRecordado()));
}

void ControladorInmobiliarias::desSuscribirseAInmobiliaria(std::string nombreInmobiliaria){
    std::map<std::string, Inmobiliaria*>::iterator it = coleccionInmobiliarias.find(nombreInmobiliaria);
    it->second->anularSuscripcion(dynamic_cast<Suscriptor*>(Factory::getInstance()->getControladorUsuario()->getUsuarioRecordado()));
}



