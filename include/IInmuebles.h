#ifndef IINMUEBLES_H
#define IINMUEBLES_H
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include <set>

class IInmuebles{
    public:
        virtual ~IInmuebles() {}

       virtual void eliminarInmueble(int codigoInmueble)=0;
       virtual std::set <DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)=0;
};
#endif