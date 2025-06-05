#include "../include/Publicacion.h"
#include "TipoPublicacion.h"
#include "AdministraPropiedad.h"
#include "DTPublicacion.h"

#include <string>

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa){
    this->codigo=codigo;
    this->fecha=fecha;
    this->tipo=tipo;
    this->texto=texto;
    this->precio=precio;
    this->activa=activa;
}

Publicacion::~Publicacion() {
    delete fecha;
}

void Publicacion::setAdministrador(AdministraPropiedad* admin){
    this->administrador=admin;
}

DTPublicacion Publicacion::getDTPublicacion() {
    return DTPublicacion(
        this->codigo,
        this->fecha, 
        this->texto,
        this->precio, 
        this->administrador->getInmobiliariaAdministradora()->getNombre()
    );
    
}

void Publicacion:: marcarComoInactiva(){

}

bool Publicacion:: cumpleCondiciones(TipoPublicacion tipoPublicacion, float precioMinimo, float prcioMaximo, TipoInmueble tipoInmueble){

}
