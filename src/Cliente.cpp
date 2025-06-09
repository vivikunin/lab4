#include "Cliente.h"
#include "Suscriptor.h"

Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento):
Suscriptor(nickname, contrasena, nombre, email){
    this->apellido=apellido;
    this->documento=documento;
}
        
Cliente::~Cliente(){}
        
std::string Cliente::getApellido(){
    return this->apellido;
}
        
std::string Cliente:: getDocumento(){
    return this->documento;
}
        
void Cliente::notificar(std::string nickname, int c, std::string texto, TipoInmueble tipoInmueble ){

}