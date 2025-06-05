#ifndef IUSUARIOS_H
#define IUSUARIOS_H
#include <string>

using namespace std;

class IUsuarios{  
    public:
        virtual bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)=0;
        virtual bool altaPropiedad(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)=0;
        virtual bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)=0;
};
#endif