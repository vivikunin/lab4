#ifndef SUSCRIPTOR_H
#define SUSCRIPTOR_H
#include "Notificacion.h"
#include "Usuario.h"


#include <list>
#include <string>

class Suscriptor : public Usuario {
    protected:
        std::list <Notificacion*> misNotificaciones;
    
    public:
        Suscriptor(std::string nickname, std::string contrasena, std::string nombre, std::string email);   
        virtual ~Suscriptor()=0;

        virtual void notificar(Notificacion* n);
        const std::set<Notificacion*>& getNotificaciones() const;
};

#endif