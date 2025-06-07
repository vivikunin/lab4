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

bool AdministraPropiedad::puedoCrearPublicacion(TipoPublicacion tipo){

}

DTPublicacion AdministraPropiedad::obtenerDatosPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo){

}

void AdministraPropiedad::eliminarInmueble(){
    for (std::map<int,Publicacion*>::iterator it=coleccionPublicaciones.begin(); it!=coleccionPublicaciones.end(); it++){
        delete(it->second);
    }
}


