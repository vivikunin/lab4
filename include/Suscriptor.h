#ifndef SUSCRIPTOR_H
#define SUSCRIPTOR_H

#include "Notificacion.h"
#include "Usuario.h"
#include "DTNotificacion.h"


#include <list>
#include <string>

class Suscriptor : public Usuario {
    protected:
        std::list <Notificacion*> misNotificaciones;
    
    public:
        Suscriptor(std::string nickname, std::string contrasena, std::string nombre, std::string email);   
        virtual ~Suscriptor();

        virtual void notificar(Notificacion* n)=0;
        std::list<DTNotificacion> getNotificaciones();
};

#endif