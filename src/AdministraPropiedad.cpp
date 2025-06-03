#include "../include/AdministraPropiedad.h"

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha) {
    this->fecha = new DTFecha(fecha); 
    this->inmuebleAdministrado = nullptr;
    this->inmobiliariaAdministrada = nullptr;
}
AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;

    std::map<int, Publicacion*>::iterator it;
    for (it = coleccionPublicaciones.begin(); it != coleccionPublicaciones.end(); ++it) {
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
    this->inmobiliariaAdministrada=inmobiliaria;
}

DTInmuebleAdministrado AdministraPropiedad::obtenerDatosInmuebleAdministrado(){

}

bool AdministraPropiedad::puedoCrearPublicacion(TipoPublicacion tipo){

}

DTPublicacion AdministraPropiedad::obtenerDatos(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo){

}

void AdministraPropiedad::eliminarInmueble(){

}
