#ifndef IINMOBILIARIAS_H
#define IINMOBILIARIAS_H
#include <string>
#include <set>
#include "DTUsuario.h"
#include "TipoPublicacion.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"


using namespace std;

class IInmobiliarias{
    public:
        virtual ~IInmobiliarias() {}

       virtual set <DTUsuario> listarInmobiliarias()=0;
       virtual bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio)=0;
       virtual set <DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria)=0;
       virtual set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria)=0;
       virtual  void altaAdministraPropiedad(std::string nickname, int codigoInmueble)=0;
       virtual  std::set<string> mostrarInmobiliariasNoSuscrito(string nickname)=0;
       virtual std::set<string> mostrarInmobiliariasSuscrito(string nickname)=0;
       virtual void suscribirseAInmobiliaria(std::string nombreInmobiliaria)=0;
       virtual void desSuscribirseAInmobiliaria(std::string nombreInmobiliaria)=0;
};
#endif