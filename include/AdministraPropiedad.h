#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"

class AdministraPropiedad {
    private:
        DTFecha* fecha;

    public:
        AdministraPropiedad(DTFecha* fecha);
        ~AdministraPropiedad();
        DTInmuebleAdministrado obtenerDatosInmuebleAdministrado();
        AdministraPropiedad administraPropiedadPaaraInmueble(int codigoInmueble);
        bool puedoCrearPublicacion(TipoPublicacion p);
        
};

#endif