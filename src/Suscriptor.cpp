#include "Suscriptor.h"
#include "DTNotificacion.h"

#include <set>
Suscriptor::Suscriptor(std::string nickname, std::string contrasena, std::string nombre, std::string email):
Usuario(nickname, contrasena, nombre, email){
}

    

Suscriptor::~Suscriptor(){
    for(std::set <Notificacion*>::iterator it = misNotificaciones.begin(); it!=misNotificaciones.end(); it++){
        delete *it;
    }
    misNotificaciones.clear();
}

std::set<DTNotificacion> Suscriptor::getNotificaciones(){
    std::set<DTNotificacion> resultado;
    for(std::set<Notificacion*>::iterator it = misNotificaciones.begin(); it!=misNotificaciones.end(); it++){
        resultado.insert(DTNotificacion((*it)->getNicknameInmobiliaria(), (*it)->getCodigo(), (*it)->getTexto(), (*it)->getTipoPublicacion(), (*it)->getTipoInmueble()));
    }
    misNotificaciones.clear(); // Elimina las notificaciones ya consultadas
    return resultado;
}