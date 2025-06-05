#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "Suscriptor.h"

#include <string>

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::set<AdministraPropiedad*> propiedadesAdministradas;
        std::set<Suscriptor*> suscriptores;

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        ~Inmobiliaria();

        std::set<DTInmuebleAdministrado> datosInmueblesAdministrados();
        DTUsuario getDatos();
        bool altaPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);

        void suscribir(std::string nickname);
        void anularSuscripcion(std::string nickname);
        void notificar(std::string nickname, int c, std::string texto, TipoInmueble tipoInmueble );

};

#endif