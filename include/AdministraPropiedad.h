#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include <map>
#include "DTFecha.h"
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "Publicacion.h"
#include "Inmueble.h"
#include "Inmobiliaria.h"


class AdministraPropiedad {
    private:
        DTFecha* fecha;
        std::map<int, Publicacion*> coleccionPublicaciones;
        Inmueble* inmuebleAdministrado;
        Inmobiliaria* inmobiliariaAdministrada;
    public:
        AdministraPropiedad(DTFecha* fecha);
        ~AdministraPropiedad();

        DTFecha* getFecha();  
        void setInmuebleAdministrado(Inmueble* inmueble); 
        void setInmobiliariaAdministrada(Inmobiliaria* inmobiliaria);  

        DTInmuebleAdministrado obtenerDatosInmuebleAdministrado();
        bool puedoCrearPublicacion(TipoPublicacion tipo);
        DTPublicacion obtenerDatos(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo);
        void eliminarInmueble();
};

#endif