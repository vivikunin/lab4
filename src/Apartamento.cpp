#include "../include/Apartamento.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"

Apartamento::Apartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes):
Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion){
    this->piso=piso;
    this->tieneAscensor=tieneAscensor;
    this->gastosComunes=gastosComunes;
}

Apartamento::~Apartamento(){}

DTInmueble Apartamento::getDTInmueble(){
    return DTApartamento(this->getCodigo(), this->getDireccion(), this->getNumeroPuerta(), this->getSuperficie(), this->getAnoConstruccion(), piso, tieneAscensor, gastosComunes);
}
