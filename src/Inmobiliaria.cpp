#include "../include/Inmobiliaria.h"
#include "AdministraPropiedad.h"
#include <set>
#include <vector>
#include <string>

Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono):Usuario::Usuario(nickname, contrasena, nombre, email){
    this->direccion=direccion;
    this->url=url;
    this->telefono=telefono;
}

Inmobiliaria::~Inmobiliaria() {
    std::vector<AdministraPropiedad*> aBorrar(propiedadesAdministradas.begin(), propiedadesAdministradas.end());

    for (std::vector<AdministraPropiedad*>::iterator it = aBorrar.begin(); it != aBorrar.end(); ++it) {
        delete *it;
    }

    propiedadesAdministradas.clear();
    suscriptores.clear();
    propietariosRepresentados.clear();
}

DTUsuario getDatos();
bool altaPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);

void Inmobiliaria::eliminarReferenciaAdministracion(AdministraPropiedad* ap){
    propiedadesAdministradas.erase(ap);
}

void Inmobiliaria::suscribir(Suscriptor* s){ 
    suscriptores.insert(std::make_pair(s->getNickname(),s));
}

void Inmobiliaria::anularSuscripcion(Suscriptor* s){
    suscriptores.erase(s->getNickname());
}

void Inmobiliaria::notificar(std::string nickname, int c, std::string texto, TipoPublicacion tipoPublicacion, TipoInmueble tipoInmueble ){
    for (std::map<std::string, Suscriptor*>::iterator it=suscriptores.begin(); it!=suscriptores.end(); it++) {
        Notificacion* n = new Notificacion(nickname, c, texto, tipoPublicacion, tipoInmueble);
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
        std::set<DTInmuebleListado> inmueblesAgregar = it->second->getInmueblesNoAdmin(this);
        res.insert(inmueblesAgregar.begin(), inmueblesAgregar.end());   }
   return res;
}

void Inmobiliaria::linkPropietario(Propietario* prop) {
    this->propietariosRepresentados.insert(std::make_pair(prop->getNickname(), prop));
}

bool Inmobiliaria::altaPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){
    AdministraPropiedad* ap = NULL;
    for(std::set<AdministraPropiedad*>::iterator it=propiedadesAdministradas.begin(); it!=propiedadesAdministradas.end(); it++ ){
        ap = (*it)->administraPropiedadParaInmueble(codigoInmueble);
        if (ap != NULL) break;
    }
    bool puede = ap->puedoCrearPublicacion(tipoPublicacion);
    if (puede){
        ap->desactivarPublicacionActiva();
        ap->crearPublicacion(tipoPublicacion, texto, precio);
        return true;
    } else{
        return false;
    }
}

bool Inmobiliaria::tieneSuscriptor(std::string nickname){
    if(suscriptores.find(nickname)!=suscriptores.end()){
        return true;
    } else {
        return false;
    }
}

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* i, DTFecha f){
   AdministraPropiedad* ap = new AdministraPropiedad(f,i,this);
   propiedadesAdministradas.insert(ap);
   i->asociarAdministracionPropiedad(ap);
}