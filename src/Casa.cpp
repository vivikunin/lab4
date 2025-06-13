#include "Casa.h"
#include "Inmueble.h"

Casa::Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo):
Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion){
    this->esPH=esPH;
    this->techo=techo;
}

DTInmueble Casa::getDTInmueble(){
    return DTCasa(this->getCodigo(), this->getDireccion(), this->getNumeroPuerta(), this->getSuperficie(), this->getAnoConstruccion(), esPH, techo);
}