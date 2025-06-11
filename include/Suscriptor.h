#ifndef SUSCRIPTOR_H
#define SUSCRIPTOR_H

#include "Notificacion.h"
#include "Usuario.h"
#include "DTNotificacion.h"


#include <set>
#include <string>

class Suscriptor : public Usuario {
    protected:
        std::set <Notificacion*> misNotificaciones;
    
    public:
        Suscriptor(std::string nickname, std::string contrasena, std::string nombre, std::string email);   
        virtual ~Suscriptor()=0;

        virtual void notificar(Notificacion* n);
        std::set<DTNotificacion> getNotificaciones();
};

#endif