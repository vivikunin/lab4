#include "Usuario.h"
#include "DTUsuario.h"
Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

Usuario::~Usuario(){}

std::string Usuario::getNickname()const{
    return nickname;
}

std::string Usuario::getContrasena()const{
    return contrasena;
}

std::string Usuario::getNombre()const{
    return nombre;
}

std::string Usuario::getEmail() const{
    return email;
}

DTUsuario Usuario::getDTUsuario(){
    return DTUsuario(nickname, nombre);
}