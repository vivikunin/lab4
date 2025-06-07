#include "Inmueble.h"

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion){
    this->codigo=codigo;
    this->direccion=direccion;
    this->numeroPuerta=numeroPuerta;
    this->superficie=superficie;
    this->anoConstruccion=anoConstruccion;
}

Inmueble::~Inmueble() {
    if (administracion != nullptr) {
        Inmobiliaria* i = administracion->getInmobiliariaAdministradora();
        if (i != nullptr) {
            i->eliminarReferenciaAdministracion(administracion);
        }
        delete administracion;
        administracion = nullptr;
    }
}

void Inmueble::eliminarInmueble(){
    duenio->removerInmueble();
    administracion->eliminarInmueble();
}