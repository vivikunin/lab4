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

       virtual set <DTUsuario> listarInmobiliarias()=0;
       virtual bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio)=0;
       virtual set <DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria)=0;
       virtual set <DTUsuario> listarInmobiliarias();
       virtual set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria);
       virtual  void altaAdministraPropiedad();
       virtual  std::set<string> mostrarInmobiliariasNoSuscrito(string nickname);

};
#endif