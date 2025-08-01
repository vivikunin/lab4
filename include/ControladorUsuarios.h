#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H
#include "IUsuarios.h"
#include "Inmobiliaria.h"
#include "Usuario.h"
#include <string>
#include <list>
#include <map>

class Usuario;

class ControladorUsuarios : public IUsuarios  {
    private:
        static ControladorUsuarios* instance;
        ControladorUsuarios();
        std::map <std::string, Usuario*> coleccionUsuarios;
        Usuario* usuarioRecordado;
        Inmobiliaria* inmobiliariaRecordada;

    
    public:
        static ControladorUsuarios* getInstance();
        virtual ~ControladorUsuarios();

        Usuario* getUsuarioRecordado() const;
        void finalizarAltaUsuario();
        void olvidarUsuarioRecordado();

        bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
        bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
        bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        void eliminarUsuario(string nickname);
        std::list<DTNotificacion> consultarNotificaciones(std::string nickname);

        void representarPropietario(std::string nicknamePropietario);
        void recordarUsuario(std::string nicknamePropietario);




        std::set<DTUsuario> listarPropietarios();

};

#endif