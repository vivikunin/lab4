#ifndef SUSCRIPTOR_H
#define SUSCRIPTOR_H
#include "Notificacion.h"
#include "Usuario.h"


#include <set>
#include <string>

class Suscriptor : public Usuario {
    private:
        std::set <Notificacion*> misNotificaciones;
    
    public:
        Suscriptor(std::string nickname, std::string contrasena, std::string nombre, std::string email);   
        virtual ~Suscriptor()=0;

        void notificar(Notificacion* n);
        const std::set<Notificacion*>& getNotificaciones() const;
};

#endif