#include "../include/Inmobiliaria.h"
#include "AdministraPropiedad.h"
#include <set>
#include <string>

Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono):Usuario::Usuario(nickname, contrasena, nombre, email){
    this->direccion=direccion;
    this->url=url;
    this->telefono=telefono;
}

Inmobiliaria::~Inmobiliaria(){
    for(std::set<AdministraPropiedad*>::iterator it =propiedadesAdministradas.begin(); it!=propiedadesAdministradas.end();it++){
        delete *it;
    }
    propiedadesAdministradas.clear();
}

DTUsuario getDatos();
bool altaPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);

void Inmobiliaria::eliminarReferenciaAdministracion(AdministraPropiedad* ap){
    propiedadesAdministradas.erase(ap);
}

void Inmobiliaria::suscribir(Suscriptor* s){ 
    suscriptores.insert({s->getNickname(),s});
}

void Inmobiliaria::anularSuscripcion(Suscriptor* s){
    suscriptores.erase(s->getNickname());
}

void Inmobiliaria::notificar(std::string nickname, int c, std::string texto, TipoPublicacion tipoPublicacion, TipoInmueble tipoInmueble ){
    Notificacion* n = new Notificacion(nickname, c, texto, tipoPublicacion, tipoInmueble);
    for (std::map<std::string, Suscriptor*>::iterator it=suscriptores.begin(); it!=suscriptores.end(); it++) {
            it->second->notificar(n);
    }
}

std::set<DTInmuebleAdministrado> Inmobiliaria:: datosInmueblesAdministrados(){
    std::set<DTInmuebleAdministrado> datos;
    for(std::set<AdministraPropiedad*>::iterator it=propiedadesAdministradas.begin(); it!=propiedadesAdministradas.end(); it++ ){
        DTInmuebleAdministrado dtia = (*it)->obtenerDatosInmuebleAdministrado();
        datos.insert(dtia);
    }
    return datos;
}

std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario(){
   std::set<DTInmuebleListado> res;
   for (std::map<std::string, Propietario*>::iterator it = propietariosRepresentados.begin(); it!=propietariosRepresentados.end(); it++){
        res.insert(it->second->getInmueblesNoAdmin(this));
   }
   return res;
}

void Inmobiliaria::linkPropietario(Propietario* prop) {
    this->propietariosRepresentados.insert({prop->getNickname(), prop});
}

bool Inmobiliaria::altaPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){
    AdministraPropiedad* ap;
    for(std::set<AdministraPropiedad*>::iterator it=propiedadesAdministradas.begin(); it!=propiedadesAdministradas.end(); it++ ){
        ap = (*it)->administraPropiedadParaInmueble(codigoInmueble);
        if ((*it) != NULL) break;
    }
    bool puede = ap->puedoCrearPublicacion(tipoPublicacion);
    if (puede){
        ap->desactivarPublicacionActiva();
        ap->crearPublicacion(tipoPublicacion, texto, precio);
    }
}

bool Inmobiliaria::tieneSuscriptor(std::string nickname){
    if(suscriptores.find(nickname)!=suscriptores.end()){
        return true;
    } else {
        return false;
    }
}