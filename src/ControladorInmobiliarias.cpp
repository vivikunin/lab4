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

}
        
set <DTInmuebleAdministrado> ControladorInmobiliarias::listarInmueblesAdministrados(string nicknameInmobiliaria){
    Inmobiliaria i = coleccionInmobiliarias.find(nicknameInmobiliaria);
    set<DTInmuebleAdministrado> datos;
    for (set<AdministraPropiedad*>::iterator it = propiedadesAdministradas.begin(); it != propiedadesAdministradas.end(); it++){
        AdministraPropiedad *ap = (*it);
        DTInmuebleAdministrado datosActual = ap.obtenerDatosInmuebleAdministrado(); //IMplementar esa
        datos.insert(datosActual); //A CHEQUEAR JAJAJJAJA
    }
;
}