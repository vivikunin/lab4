#include "../include/AdministraPropiedad.h"
#include "DTInmuebleAdministrado.h"
#include "ControladorFechaActual.h"
#include <set>

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha) {
    this->fecha = new DTFecha(fecha); 
    this->inmuebleAdministrado = nullptr;
    this->inmobiliariaAdministradora = nullptr;
}
AdministraPropiedad::~AdministraPropiedad(){
    delete fecha;
    //vaciar y eliminar la coleccion de publicaciones
    for (std::map<int,Publicacion*>::iterator it = coleccionPublicaciones.begin(); it != coleccionPublicaciones.end(); ++it){
        delete it->second;
    }
    coleccionPublicaciones.clear();

    //Eliminar referencia de l ainmobiliaria y el inmueble
    if (inmuebleAdministrado != nullptr) {
        inmuebleAdministrado->eliminarReferenciaAdministracion();
    }
    if (inmobiliariaAdministradora != nullptr) {
        inmobiliariaAdministradora->eliminarReferenciaAdministracion(this);
    }
}

DTFecha*  AdministraPropiedad::getFecha(){
    return this->fecha;
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
    return DTInmuebleAdministrado(c,d,this->fecha);
}


std::set<DTPublicacion> AdministraPropiedad::obtenerDatosPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
    std::set<DTPublicacion> res;
    for(std::map<int, Publicacion*>::iterator it=coleccionPublicaciones.begin(); it!=coleccionPublicaciones.end(); it++){
        if(it->second->cumpleCondiciones(tipoPublicacion, precioMinimo,precioMaximo,tipoInmueble)){
            DTPublicacion dtp = it->second->getDTPublicacion();
            res.insert(dtp);
        }
    }
}

void AdministraPropiedad::eliminarInmueble(){
    for (std::map<int,Publicacion*>::iterator it=coleccionPublicaciones.begin(); it!=coleccionPublicaciones.end(); it++){
        delete(it->second);
    }
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
    this->coleccionPublicaciones.insert({pub->getCodigo(),pub});

    //notis
    Notificacion n(inmobiliariaAdministradora->getNombre(), inmuebleAdministrado->getCodigo(), texto, tipoPublicacion, inmuebleAdministrado->getTipoInmueble());
    inmobiliariaAdministradora->notificar(n);
}