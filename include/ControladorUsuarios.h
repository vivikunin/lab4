#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H
#include "IUsuarios.h"
#include "Inmobiliaria.h"
#include <string>
#include <map>

class Usuario;

class ControladorUsuarios : public IUsuarios  {
    private:
        static ControladorUsuarios* instance;
        ControladorUsuarios();
        std::map <string, Usuario*> coleccionUsuarios;
        Propietario* propietarioRecordado=NULL;
    
    public:
        static ControladorUsuarios* getInstance();
        ~ControladorUsuarios();

        Propietario* getPropietarioRecordado() const;
        void finalizarAltaUsuario();

        bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
        bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
        bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        void eliminarUsuario(string nickname);

        std::set<DTUsuario> listarPropietarios();

};

#endif