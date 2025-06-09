#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"
#include "Suscriptor.h"
#include "AdministraPropiedad.h"
#include <string>
#include <set>
#include <map>

class AdministraPropiedad;

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::map<std::string, Propietario*> propietariosRepresentados;
        std::set<AdministraPropiedad*> propiedadesAdministradas;
        std::set<Suscriptor*> suscriptores;

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        ~Inmobiliaria();

        std::set<DTInmuebleAdministrado> datosInmueblesAdministrados();
        DTUsuario getDatos();
        bool altaPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
        void eliminarReferenciaAdministracion(AdministraPropiedad* ap);
        void linkPropietario(Propietario* prop);

        void suscribir(Suscriptor* s);
        void anularSuscripcion(Suscriptor* s);
        void notificar(std::string nickname, int c, std::string texto, TipoPublicacion tipoPublicacion, TipoInmueble tipoInmueble );

        std::set<DTInmuebleListado> getInmueblesNoAdminPropietario();
};

#endif