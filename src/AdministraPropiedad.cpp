#include "../include/AdministraPropiedad.h"
#include "DTInmuebleAdministrado.h"
#include "ControladorFechaActual.h"

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha) {
    this->fecha = new DTFecha(fecha); 
    this->inmuebleAdministrado = nullptr;
    this->inmobiliariaAdministradora = nullptr;
}
AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;
    //vaciar y eliminar la coleccion de publicaciones
    for (std::map<int,Publicacion*>::iterator it = coleccionPublicaciones.begin(); it != coleccionPublicaciones.end(); ++it) {
        delete it->second;
    }
    coleccionPublicaciones.clear();
}

DTFecha*  AdministraPropiedad::getFecha(){
    return this->fecha;
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


DTPublicacion AdministraPropiedad::obtenerDatosPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo){

}

void AdministraPropiedad::eliminarInmueble(){

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
    Publicacion* pub = new Publicacion(Publicacion::ultimoCodigo+1, ControladorFechaActual::getInstance()->getFechaActual(), tipoPublicacion, texto, precio, true);
    this->coleccionPublicaciones.insert({pub->getCodigo(),pub});
}