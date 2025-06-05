#include "../include/Apartamento.h"

Apartamento:: Apartamento(int piso, bool tieneAscensor, float gastosComunes){
    this->piso=piso;
    this->tieneAscensor=tieneAscensor;
    this->gastosComunes=gastosComunes;
}

Apartamento::~Apartamento(){}

DTApartamento Apartamento::getDTApartamento() const{

}