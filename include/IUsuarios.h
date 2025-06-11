#ifndef IUSUARIOS_H
#define IUSUARIOS_H
#include <string>

using namespace std;

class IUsuarios{  
    public:
        virtual bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)=0;
        virtual bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)=0;
        virtual bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)=0;

        void eliminarUsuario(string nickname);
        
        virtual set<DTUsuario> listarPropietarios();
        void representarPropietario(std::string nicknamePropietario);

        std::set<DTNotificacion> consultarNotificaciones(std::string nickname);

        virtual Usuario* getUsuarioRecordado() const ;
        virtual void recordarUsuario(std::string nicknamePropietario);
        virtual void finalizarAltaUsuario();
        virtual void olvidarUsuarioRecordado();
        virtual void agregarSuscriptor(Usuario* u);
};
#endif