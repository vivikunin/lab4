#include "Propietario.h"
#include "Suscriptor.h"

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono):
Suscriptor(nickname, contrasena, nombre, email){
    this->cuentaBancaria=cuentaBancaria;
    this->telefono=telefono;
}

std::string Propietario::getCuentaBancaria(){
    return cuentaBancaria;
}

std::string Propietario::getTelefono(){
    return telefono;
}

void Propietario::notificar(Notificacion* n){
    this->misNotificaciones.push_back(n);
}