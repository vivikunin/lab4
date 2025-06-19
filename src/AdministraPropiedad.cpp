#include "../include/AdministraPropiedad.h"
#include "DTInmuebleAdministrado.h"
#include "ControladorFechaActual.h"
#include "DTFecha.h"
#include <set>

AdministraPropiedad::AdministraPropiedad(DTFecha fecha): fecha(fecha) {
    this->inmuebleAdministrado = NULL;
    this->inmobiliariaAdministradora = NULL;
}

AdministraPropiedad::AdministraPropiedad(DTFecha fecha,Inmueble* inmuebleAdministrado ,Inmobiliaria* inmobiliariaAdministradora): fecha(fecha){
    this->inmuebleAdministrado = inmuebleAdministrado;
    this->inmobiliariaAdministradora = inmobiliariaAdministradora;
}

AdministraPropiedad::~AdministraPropiedad(){
    //Eliminar referencia de la inmobiliaria y el inmueble
    if (inmuebleAdministrado != NULL) {
        inmuebleAdministrado->eliminarReferenciaAdministracion();
    }
    if (inmobiliariaAdministradora != NULL) {
        inmobiliariaAdministradora->eliminarReferenciaAdministracion(this);
    }
}

DTFecha&  AdministraPropiedad::getFecha(){
    return fecha;
} 

Inmueble* AdministraPropiedad::getInmuebleAdministrado() const{
    return this->inmuebleAdministrado;
}

Inmobiliaria* AdministraPropiedad::getInmobiliariaAdministradora() const{
    return this->inmobiliariaAdministradora;
}

void AdministraPropiedad::setInmuebleAdministrado(Inmueble* inmueble){
    this->inmuebleAdministrado=inmueble;
}
void AdministraPropiedad::setInmobiliariaAdministrada(Inmobiliaria* inmobiliaria){
    this->inmobiliariaAdministradora=inmobiliaria;
}

DTInmuebleAdministrado AdministraPropiedad::obtenerDatosInmuebleAdministrado(){
    std::string d=inmuebleAdministrado->getDireccion();
    int c=inmuebleAdministrado->getCodigo();
    return DTInmuebleAdministrado(c,d,fecha);
}


std::set<DTPublicacion> AdministraPropiedad::obtenerDatosPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo){
    std::set<DTPublicacion> res;
    for(std::map<int, Publicacion*>::iterator it=coleccionPublicaciones.begin(); it!=coleccionPublicaciones.end(); it++){
        if(it->second->cumpleCondiciones(tipoPublicacion, precioMinimo,precioMaximo)){
            DTPublicacion dtp = it->second->getDTPublicacion();
            res.insert(dtp);
        }
    }
    return res;
}

void AdministraPropiedad::eliminarInmueble(){
    for (std::map<int,Publicacion*>::iterator it=coleccionPublicaciones.begin(); it!=coleccionPublicaciones.end(); it++){
        delete(it->second);
    }
    coleccionPublicaciones.clear();
}



AdministraPropiedad* AdministraPropiedad::administraPropiedadParaInmueble(int codigoInmueble){
    if (this->inmuebleAdministrado->getCodigo()==codigoInmueble){
        return this;
    } else {
        return NULL;
    }
}

bool AdministraPropiedad::puedoCrearPublicacion(TipoPublicacion tp){
    for(std::map<int,Publicacion*>::iterator it= coleccionPublicaciones.begin();it!=coleccionPublicaciones.end(); it++){
        if(tp==it->second->getTipoPublicacion() && it->second->getFecha()==ControladorFechaActual::getInstance()->getFechaActual()){
            return false;
        }
    }
    return true;
}

void AdministraPropiedad::desactivarPublicacionActiva(){
    bool desactivada = false; 
    std::map<int,Publicacion*>::iterator it = coleccionPublicaciones.begin(); 
    while (desactivada==false && it!=coleccionPublicaciones.end()){
        if (it->second->estaActiva()){
            desactivada=true;
            it->second->marcarComoInactiva();
        }
        it++;
    }
}

void AdministraPropiedad::crearPublicacion(TipoPublicacion tipoPublicacion, std::string texto, float precio){
    Publicacion::ultimoCodigo++; 
    Publicacion* pub = new Publicacion(Publicacion::ultimoCodigo, ControladorFechaActual::getInstance()->getFechaActual(), tipoPublicacion, texto, precio, true);
    this->coleccionPublicaciones.insert(std::make_pair(pub->getCodigo(), pub));

    pub->setAdministrador(this);
    //notis
    inmobiliariaAdministradora->notificar(inmobiliariaAdministradora->getNickname(), pub->getCodigo(), texto, tipoPublicacion, inmuebleAdministrado->tipoDelInmueble());
    
}

bool AdministraPropiedad::tienePublicacion(int codigoPublicacion){
    if(coleccionPublicaciones.find(codigoPublicacion)!=coleccionPublicaciones.end()){
        return true;
    } else {
        return false;
    }
}