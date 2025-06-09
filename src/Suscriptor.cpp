#include "Suscriptor.h"
#include <set>
Suscriptor::Suscriptor(std::string nickname, std::string contrasena, std::string nombre, std::string email):
Usuario(nickname, contrasena, nombre, email){
}

    

Suscriptor::~Suscriptor(){
    for(std::list <Notificacion*>::iterator it = misNotificaciones.begin(); it!=misNotificaciones.end(); it++){
        delete *it;
    }
    misNotificaciones.clear();
}

std::list<Notificacion*> Suscriptor::getNotificaciones(){
    std::list<Notificacion*> resultado = misNotificaciones;
        misNotificaciones.clear(); // Elimina las notificaciones ya consultadas
        return resultado;
}
