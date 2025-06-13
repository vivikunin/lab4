#ifndef IUSUARIOS_H
#define IUSUARIOS_H
#include <string>
#include <list>
#include "Usuario.h"
#include "DTNotificacion.h"

using namespace std;

class IUsuarios{  
    public:
        virtual bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)=0;
        virtual bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)=0;
        virtual bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)=0;

        virtual void eliminarUsuario(string nickname)=0;
        
        virtual set<DTUsuario> listarPropietarios()=0;
        virtual void representarPropietario(std::string nicknamePropietario)=0;

        virtual std::list<DTNotificacion> consultarNotificaciones(std::string nickname)=0;

        virtual Usuario* getUsuarioRecordado() const =0;
        virtual void recordarUsuario(std::string nicknamePropietario)=0;
        virtual void finalizarAltaUsuario()=0;
        virtual void olvidarUsuarioRecordado()=0;
};
#endif