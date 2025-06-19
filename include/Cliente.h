#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "TipoInmueble.h"
#include "Suscriptor.h"
#include "Notificacion.h"
#include <string>
#include <list>

class Cliente : public Suscriptor {
    private:
        std::string apellido;
        std::string documento;
    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
        ~Cliente();
        std::string getApellido();
        std::string getDocumento();
        void notificar(Notificacion* n);
};

#endif