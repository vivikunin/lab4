#ifndef CONTROLADORINMOBILIARIAS_H
#define CONTROLADORINMOBILIARIAS_H
#include "IInmobiliarias.h"
#include "TipoPublicacion.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"
#include "DTUsuario.h"

#include <map>
#include <string>

class Inmobiliaria;

class ControladorInmobiliarias : public IInmobiliarias {
    private:
        static ControladorInmobiliarias* instance;
        ControladorInmobiliarias();
        std::map <string, Inmobiliaria*> coleccionInmobiliarias;
    public:
        static ControladorInmobiliarias* getInstance();
        ~ControladorInmobiliarias();
        
        bool altaInmobiliaria(string nickname,string contrasena,string nombre,string email,string direccion,string url,string telefono);
        std::set <DTUsuario> listarInmobiliarias();
        bool altaPublicacion(string nickname, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio);
        std::set <DTInmuebleAdministrado> listarInmueblesAdministrados (string nicknameInmobiliaria);
        std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria);
        std::set<string> mostrarInmobiliariasNoSuscrito(string nickname);
        std::set<string> mostrarInmobiliariasSuscrito(string nickname);
        void altaAdministraPropiedad(std::string nickname, int codigoInmueble );

        void suscribirseAInmobiliaria(std::string nombreInmobiliaria);
        void desSuscribirseAInmobiliaria(std::string nombreInmobiliaria);
};

#endif