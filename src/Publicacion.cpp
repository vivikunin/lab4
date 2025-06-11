#include "../include/Publicacion.h"
#include "TipoPublicacion.h"
#include "AdministraPropiedad.h"
#include "DTPublicacion.h"

#include <string>

int Publicacion::ultimoCodigo = 0;

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


TipoPublicacion Publicacion::getTipoPublicacion(){
    return this->tipo;
}

DTFecha* Publicacion::getFecha(){
    return this->fecha;
}

int Publicacion::getCodigo(){
    return this->codigo;
}

bool Publicacion::estaActiva(){
    return this->activa;
}

void Publicacion:: marcarComoInactiva(){
    this->activa=false;
}

bool Publicacion:: cumpleCondiciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
    return (this->getTipoPublicacion() == tipoPublicacion && (this->getPrecio() >= precioMinimo && this->getPrecio() <= precioMaximo));
}

float Publicacion::getPrecio(){
    return this->precio;
}

