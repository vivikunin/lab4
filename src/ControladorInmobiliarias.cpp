#include "../include/ControladorInmobiliarias.h"
#include "Inmobiliaria.h"
#include "AdministraPropiedad.h"
#include "Factory.h"

#include <set>
#include <stdexcept>

using namespace std;

ControladorInmobiliarias* ControladorInmobiliarias::instance = NULL;

ControladorInmobiliarias* ControladorInmobiliarias::getInstance() {
    if (instance == NULL) {
        instance = new ControladorInmobiliarias();
    }
    return instance;
}

ControladorInmobiliarias::ControladorInmobiliarias(){}

ControladorInmobiliarias::~ControladorInmobiliarias(){
    coleccionInmobiliarias.clear();
}

void  ControladorInmobiliarias::agregarInmobiliariaColeccion(Inmobiliaria* i){
    coleccionInmobiliarias.insert(std::make_pair(i->getNickname(), i));
}

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
    if (i==coleccionInmobiliarias.end()) {
        throw std::invalid_argument("La inmobiliaria no existe.");
    }
    if (i != coleccionInmobiliarias.end()) {
        return i->second->datosInmueblesAdministrados();
    } else {
        return set<DTInmuebleAdministrado>();
    }
}

set<DTInmuebleListado> ControladorInmobiliarias::listarInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria){
    std::map <string, Inmobiliaria*>::iterator it = coleccionInmobiliarias.find(nicknameInmobiliaria);
    if (it == coleccionInmobiliarias.end()) {
        // Si no existe, lanzamos una excepción
        throw std::invalid_argument("El nickname ingresado no corresponde a ninguna inmobiliaria registrada.");
    }

    set<DTInmuebleListado> listInmuebles = it->second->getInmueblesNoAdminPropietario();
    return listInmuebles;
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

void ControladorInmobiliarias::altaAdministraPropiedad(std::string nickname, int codigoInmueble ){
    std::map<std::string, Inmobiliaria*>::iterator inmobiliaria = coleccionInmobiliarias.find(nickname);
    IInmuebles* controladorInmuebles = Factory::getInstance()->getControladorInmuebles();
    DTFecha* f = Factory::getInstance()->getControladorFechaActual()->getFechaActual();
    Inmueble* cin = controladorInmuebles->getInmueble(codigoInmueble);
    inmobiliaria->second->altaAdministracionPropiedad(cin, f);
    delete f;
}


