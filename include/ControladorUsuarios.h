#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H
#include "IUsuarios.h"
#include <string>
#include <set>

class Usuario;

class ControladorUsuarios : public IUsuarios  {
    private:
        static ControladorUsuarios* instance;
        ControladorUsuarios();
        std::set <Usuario*> coleccionUsuarios;
    
    public:
        static ControladorUsuarios* getInstance();
        ~ControladorUsuarios();

        bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
        bool altaPropiedad(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
        bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
};

#endif