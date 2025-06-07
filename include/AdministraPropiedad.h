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
        std::map<int,Publicacion*> coleccionPublicaciones;
        Inmueble* inmuebleAdministrado;
        Inmobiliaria* inmobiliariaAdministradora;
    public:
        AdministraPropiedad(DTFecha* fecha);
        AdministraPropiedad(DTFecha* fecha,Inmueble* inmuebleAdministrado ,Inmobiliaria* inmobiliariaAdministradora);
        ~AdministraPropiedad();

        DTFecha* getFecha(); 
        Inmueble* getInmuebleAdministrado() const;
        Inmobiliaria* getInmobiliariaAdministradora() const;
 
       void setInmuebleAdministrado(Inmueble* inmueble); 
       void setInmobiliariaAdministrada(Inmobiliaria* inmobiliaria);  

        DTInmuebleAdministrado obtenerDatosInmuebleAdministrado();
        bool puedoCrearPublicacion(TipoPublicacion tipo);
        DTPublicacion obtenerDatosPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo); //modifique nombre para que no se confundan
        void eliminarInmueble();
};
#endif