#include "../include/ControladorInmobiliarias.h"
#include <set>

using namespace std;

ControladorInmobiliarias::ControladorInmobiliarias(){}

ControladorInmobiliarias::~ControladorInmobiliarias(){}

set <DTUsuario> ControladorInmobiliarias::listarInmobiliarias(){
    set <DTUsuario> res;
    for (set<Inmobiliaria*>::iterator it = coleccionInmobiliarias.begin(); it != coleccionInmobiliarias.end(); it++){
        Inmobiliaria *actual = (*it);
        nuevo = DTUsuario(actual.getNickname(), actual.getNombre());
        res.insert(nuevo);
    }
    return res;
}
        
bool ControladorInmobiliarias::altaPublicacion(string nickname, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio){

}
        
set <DTInmuebleAdministrado> ControladorInmobiliarias::listarInmueblesAdministrados (string nicknameInmobiliaria){

}
