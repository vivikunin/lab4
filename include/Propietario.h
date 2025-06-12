#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "TipoInmueble.h"
#include "DTInmuebleListado.h"
#include "Suscriptor.h"


#include <string>

class Propietario : public Suscriptor {
    private:
        std::string cuentaBancaria;
        std::string telefono;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);

        //getters
        std::string getCuentaBancaria();
        std::string getTelefono();

        DTInmuebleListado getInmueblesNoAdmin(Inmobiliaria* i);
        void removerInmueble();
        void notificar(Notificacion* n);
};

#endif