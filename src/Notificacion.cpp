#include "../include/Notificacion.h"
#include "TipoPublicacion.h"
#include <string>

Notificacion::Notificacion(std::string nicknameInmobiliaria, int codigo, std::string texto, TipoPublicacion tPublicacion, TipoInmueble tInmueble){
    this->nicknameInmobiliaria=nicknameInmobiliaria;
    this->codigo=codigo;
    this->texto=texto;
    this->tPublicacion= tPublicacion;
    this->tInmueble=tInmueble;
}

std::string Notificacion:: getNicknameInmobiliaria() const{
    return this->nicknameInmobiliaria;
}

int Notificacion::getCodigo() const{
    return this->codigo;
}
std::string Notificacion::getTexto() const{
    return this->texto;
}

TipoPublicacion Notificacion::getTipoPublicacion() const{
    return this->tPublicacion;
}

TipoInmueble Notificacion:: getTipoInmueble() const{
    return this->tInmueble;
}

Notificacion::~Notificacion() {}
