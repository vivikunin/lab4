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
        std::map <std::string, Usuario*> coleccionUsuarios;
        Usuario* usuarioRecordado=NULL;
        Inmobiliaria* inmobiliariaRecordada=NULL;

    
    public:
        static ControladorUsuarios* getInstance();
        ~ControladorUsuarios();

        Usuario* getUsuarioRecordado() const;
        void finalizarAltaUsuario();
        void olvidarUsuarioRecordado();

        bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
        bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
        bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        void eliminarUsuario(string nickname);
        //con lo de notis
        void agregarSuscriptor(std::string nickname, Suscriptor* s);
        std::set<DTNotificacion> consultarNotificaciones(std::string nickname);

        void representarPropietario(std::string nicknamePropietario);
        void recordarUsuario(std::string nicknamePropietario);




        std::set<DTUsuario> listarPropietarios();

};

#endif