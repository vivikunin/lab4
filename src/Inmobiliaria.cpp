#include "../include/Inmobiliaria.h"
#include "AdministraPropiedad.h"
#include <set>

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

void Inmobiliaria::suscribir(Suscriptor* s){ //CON EL NICKNAME COMO CONSIGO UN PUNTERO A SUSCRIPTOR
    suscriptores.insert(s);
}

void Inmobiliaria::anularSuscripcion(std::string nickname){
    suscriptores.erase(s);
}

void Inmobiliaria::notificar(std::string nickname, int c, std::string texto, TipoPublicacion tipoPublicacion, TipoInmueble tipoInmueble ){
    Notificacion* n = new Notificacion(nickname, c, texto, tipoPublicacion, tipoInmueble);
    for (std::set<Suscriptor*>::iterator it=suscriptores.begin(); it!=suscriptores.end(); it++) {
            (*it)->notificar(n);
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