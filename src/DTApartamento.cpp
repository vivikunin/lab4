#include "../include/DTApartamento.h"
#include <iostream>

DTApartamento::DTApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
}

int DTApartamento::getPiso() {
    return piso;
}

bool DTApartamento::getTieneAscensor() {
    return tieneAscensor;
}

float DTApartamento::getGastosComunes() {
    return gastosComunes;
}

void DTApartamento::mostrarDatos(){
    // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    std::cout << "Codigo: " << getCodigo() 
               << ", direccion: " << getDireccion() 
               << ", puerta: " << getNumeroPuerta() 
               << ", superficie: " << getSuperficie() 
               << "m2, construccion: " << getAnioConstruccion()
               << ", piso: " << getPiso();
               
   if (getTieneAscensor()){
       std::cout <<", ascensor: Si";
   } else {
       std::cout <<", ascensor: No";
   }
   std::cout << ", gastos comunes: " << getGastosComunes();
}

DTApartamento::~DTApartamento(){

}