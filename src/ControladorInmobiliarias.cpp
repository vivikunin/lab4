#include "../include/ControladorInmobiliarias.h"
#include "Inmobiliaria.h"
#include "AdministraPropiedad.h"

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