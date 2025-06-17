#include "../include/Inmueble.h"
#include "../include/TipoInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/AdministraPropiedad.h"

#include <set>

int Inmueble::ultimoCodigoInmueble=0;

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion){
    this->codigo=codigo;
    this->direccion=direccion;
    this->numeroPuerta=numeroPuerta;
    this->superficie=superficie;
    this->anoConstruccion=anoConstruccion;
    this->administracion=NULL;
    this->duenio=NULL;
}

Inmueble:: ~Inmueble(){
    delete administracion;
}


bool Inmueble::esDelTipoInmueble(TipoInmueble tipo) {
    switch (tipo) {
        case Todos:
            return true;
        case TICasa:
            return dynamic_cast<Casa*>(this) != nullptr;
        case TIApartamento:
            return dynamic_cast<Apartamento*>(this) != nullptr;
    }
    return false;
}

std::set<DTPublicacion> Inmueble::obtenerDatosPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo,float precioMaximo){
    return this->administracion->obtenerDatosPublicaciones(tipoPublicacion, precioMinimo, precioMaximo);
}

void Inmueble::eliminarInmueble(){
    administracion->getInmobiliariaAdministradora()->eliminarReferenciaAdministracion(administracion);
    administracion->eliminarInmueble();
    delete administracion;
    administracion = NULL;
    duenio->eliminarPropiedad(codigo);
}

void Inmueble::setDuenio( Propietario* duenio){
    this->duenio=duenio;
}

int Inmueble::getCodigo() const{
    return codigo;
}

std::string Inmueble::getDireccion() const{
    return direccion;
}

int Inmueble::getNumeroPuerta() const{
    return numeroPuerta;
}

int Inmueble::getSuperficie() const{
    return superficie;
}

int Inmueble::getAnoConstruccion() const{
    return anoConstruccion;
}

Propietario* Inmueble::getDueño(){
    return duenio;
}

void Inmueble::setAdministracion(AdministraPropiedad* admin){
    administracion=admin;
}

AdministraPropiedad* Inmueble::getAdministracion() const{
    return administracion;
}

bool Inmueble::esAdminitrado(Inmobiliaria* i){
    if (administracion == nullptr) {
        return false;
    }
    return (administracion->getInmobiliariaAdministradora() == i);
}

void Inmueble::eliminarReferenciaAdministracion(){
    administracion=NULL;
}

TipoInmueble Inmueble:: tipoDelInmueble(){
    if(dynamic_cast<Casa*>(this) != nullptr){
        return TICasa;
    } else{
        return TIApartamento;
    }
}

bool Inmueble::tienePublicacion(int codigoPublicacion){
    return administracion->tienePublicacion(codigoPublicacion);
}

DTInmuebleListado Inmueble::getDTInmuebleListado(){
    return DTInmuebleListado(this->codigo, this->direccion, this->duenio->getNickname());
}

void Inmueble::asociarAdministracionPropiedad(AdministraPropiedad* ap){
    administracion=ap;
}