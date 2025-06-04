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
        Suscriptor();   
        ~Suscriptor();

        void notificar(Notificacion* n);
        const std::set<Notificacion*>& getNotificaciones() const;
};

#endif