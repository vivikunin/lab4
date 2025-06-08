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

void suscribir(std::string nickname);
void anularSuscripcion(std::string nickname);
void notificar(std::string nickname, int c, std::string texto, TipoInmueble tipoInmueble );

std::set<DTInmuebleAdministrado> Inmobiliaria:: datosInmueblesAdministrados(){
    std::set<DTInmuebleAdministrado> datos;
    for(std::set<AdministraPropiedad*>::iterator it=propiedadesAdministradas.begin(); it!=propiedadesAdministradas.end(); it++ ){
        DTInmuebleAdministrado dtia = (*it)->obtenerDatosInmuebleAdministrado();
        datos.insert(dtia);
    }
    return datos;
}