#include "../include/DTInmuebleAdministrado.h"

DTInmuebleAdministrado::DTInmuebleAdministrado(int codigo,std::string direccion,const DTFecha& fechaComienzo)
: codigo(codigo), direccion(std::move(direccion)), fechaComienzo(fechaComienzo)
{}

int DTInmuebleAdministrado::getCodigo() const{
    return codigo;
}

std::string DTInmuebleAdministrado::getDireccion() const{
    return direccion;
}

DTFecha DTInmuebleAdministrado::getFechaComienzo() const{
    return fechaComienzo;
}

DTInmuebleAdministrado::~DTInmuebleAdministrado(){}

bool operator<(const DTInmuebleAdministrado& a, const DTInmuebleAdministrado& b) {
    return a.getCodigo() < b.getCodigo(); 
}