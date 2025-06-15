#include "../include/DTCasa.h"
#include <iostream>

DTCasa::DTCasa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->esPH = esPH;
    this->techo = techo;
}

bool DTCasa::getEsPH() {
    return esPH;
}

TipoTecho DTCasa::getTecho() {
    return techo;
}

void DTCasa::mostrarDatos(){
     // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
     std::cout << "Codigo: " << getCodigo() 
                << ", direccion: " << getDireccion() 
                << ", puerta: " << getNumeroPuerta() 
                << ", superficie: " << getSuperficie() 
                << "m2, construccion: " << getAnioConstruccion();
                
    if (getEsPH()){
        std::cout <<", PH: Si";
    } else {
        std::cout <<", PH: No";
    }
    if (getTecho()==Liviano){
        std::cout <<", Tipo de techo: Liviano"<< "\n";
    } else if (getTecho()== A_dos_aguas){
        std::cout <<", Tipo de techo: A dos aguas"<< "\n";
    } else {
        std::cout <<", Tipo de techo: Plano"<< "\n";
    }
}

DTCasa::~DTCasa(){
    
}