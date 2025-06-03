#ifndef IINMOBILIARIAS_H
#define IINMOBILIARIAS_H
#include <string>
#include <set>
#include "DTUsuario.h"
#include "TipoPublicacion.h"
#include "DTInmuebleAdministrado.h"

using namespace std;

class IInmobiliarias{
    public:
        virtual ~IInmobiliarias() {}

       virtual set <DTUsuario> listarInmobiliarias();
       virtual bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio);
       virtual set <DTInmuebleAdministrado> listarInmuebleAdministrado(string nicknameInmobiliaria);
};
#endif