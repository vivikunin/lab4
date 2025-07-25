#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <set>
#include"DTUsuario.h"

class Usuario {
    private:
        std::string nickname;
        std::string contrasena;
        std::string nombre;
        std::string email;

    public:
        Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
        virtual ~Usuario();
        std::string getNickname()const;
        std::string getContrasena()const;
        std::string getNombre()const;
        std::string getEmail()const;
        DTUsuario getDTUsuario();
        
};

#endif