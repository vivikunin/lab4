#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "TipoInmueble.h"
#include "DTInmuebleListado.h"
#include "Suscriptor.h"
#include "Inmueble.h"


#include <string>

class Propietario : public Suscriptor {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::map<int,Inmueble*> misPropiedades;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        
        void añadirPropiedad(Inmueble* i);
        void eliminarPropiedad(int codigo);

        //getters
        std::string getCuentaBancaria();
        std::string getTelefono();

        std::set<DTInmuebleListado> getInmueblesNoAdmin(Inmobiliaria* i);
        void removerInmueble();
        void notificar(Notificacion* n);
};

#endif