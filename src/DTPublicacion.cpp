#include "../include/DTPublicacion.h"

DTPublicacion::DTPublicacion(int codigo,  const DTFecha& fecha, std::string texto, float precio, std::string inmobiliaria) : codigo(codigo)
, fecha(fecha)            
, texto(texto)
, precio(precio)
, inmobiliaria(inmobiliaria) {
}

int DTPublicacion::getCodigo() const {
    return codigo;
}

DTFecha DTPublicacion::getFecha() const {
    return fecha;
}

std::string DTPublicacion::getTexto() const {
    return texto;
}

float DTPublicacion::getPrecio() const{
    return precio;
}

std::string DTPublicacion::getInmobiliaria() const{
    return inmobiliaria;
}

DTPublicacion::~DTPublicacion(){
}

bool operator<(const DTPublicacion& a, const DTPublicacion& b) {
    return a.getCodigo() < b.getCodigo(); 
}