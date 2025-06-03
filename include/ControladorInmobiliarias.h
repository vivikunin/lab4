#ifndef CONTROLADORINMOBILIARIAS_H
#define CONTROLADORINMOBILIARIAS_H
#include "IInmobiliarias.h"
#include "TipoPublicacion.h"
#include "DTInmuebleAdministrado.h"
#include "DTUsuario.h"

#include <map>
#include <set>
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
        
        std::set <DTUsuario> listarInmobiliarias();
        bool altaPublicacion(string nickname, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio);
        std::set <DTInmuebleAdministrado> listarInmueblesAdministrados (string nicknameInmobiliaria);
};

#endif