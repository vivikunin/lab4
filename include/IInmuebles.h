#ifndef IINMUEBLES_H
#define IINMUEBLES_H
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "DTInmuebleListado.h"
#include "TipoTecho.h"

#include <set>

class IInmuebles{
    public:
        virtual ~IInmuebles() {}

       virtual void eliminarInmueble(int codigoInmueble)=0;
       virtual std::set <DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)=0;
       virtual void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,bool esPH, TipoTecho techo)=0;
       virtual void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);
       virtual DTInmueble detalleInmueble(int codigoInmueble);
       virtual DTInmueble detalleInmueblePublicacion(int codigoPublicacion);
       virtual std::set<DTInmuebleListado>listarInmuebles();

};
#endif