#include "Suscriptor.h"
#include "DTNotificacion.h"

#include <list>
Suscriptor::Suscriptor(std::string nickname, std::string contrasena, std::string nombre, std::string email):
Usuario(nickname, contrasena, nombre, email){
}

    

Suscriptor::~Suscriptor(){
    for(std::list <Notificacion*>::iterator it = misNotificaciones.begin(); it!=misNotificaciones.end(); it++){
        delete *it;
    }
    misNotificaciones.clear();
}

std::list<DTNotificacion> Suscriptor::getNotificaciones(){
    std::list<DTNotificacion> resultado;
    for(std::list<Notificacion*>::iterator it = misNotificaciones.begin(); it!=misNotificaciones.end(); it++){
        resultado.push_back(DTNotificacion((*it)->getNicknameInmobiliaria(), (*it)->getCodigo(), (*it)->getTexto(), (*it)->getTipoPublicacion(), (*it)->getTipoInmueble()));
    }
    misNotificaciones.clear(); // Elimina las notificaciones ya consultadas
    return resultado;
}