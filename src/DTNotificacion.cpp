#include "Notificacion.h"
#include"DTNotificacion.h"
#include <string>

DTNotificacion::DTNotificacion(std::string nicknameInmobiliaria, int codigo, std::string texto, TipoPublicacion tPublicacion, TipoInmueble tInmueble){
    this->nicknameInmobiliaria=nicknameInmobiliaria;
    this->codigo=codigo;
    this->texto=texto;
    this->tPublicacion= tPublicacion;
    this->tInmueble=tInmueble;
}

std::string DTNotificacion:: getNicknameInmobiliaria() const{
    return this->nicknameInmobiliaria;
}

int DTNotificacion::getCodigo() const{
    return this->codigo;
}
std::string DTNotificacion::getTexto() const{
    return this->texto;
}

TipoPublicacion DTNotificacion::getTipoPublicacion() const{
    return this->tPublicacion;
}

TipoInmueble DTNotificacion:: getTipoInmueble() const{
    return this->tInmueble;
}

