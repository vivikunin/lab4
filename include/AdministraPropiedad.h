#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include <set>
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
        std::set<Publicacion*> coleccionPublicaciones;
        Inmueble* inmuebleAdministrado;
        Inmobiliaria* inmobiliariaAdministradora;
        std::set<Publicacion*> publicaciones;
    public:
        AdministraPropiedad(DTFecha* fecha,Inmueble* inmuebleAdministrado ,Inmobiliaria* inmobiliariaAdministradora);
        ~AdministraPropiedad();

        DTFecha* getFecha(); 
        Inmueble* getInmuebleAdministrado() const;
        Inmobiliaria* getInmobiliariaAdministradora() const;
 
       // void setInmuebleAdministrado(Inmueble* inmueble); 
       // void setInmobiliariaAdministrada(Inmobiliaria* inmobiliaria);  

        DTInmuebleAdministrado obtenerDatosInmuebleAdministrado();
        bool puedoCrearPublicacion(TipoPublicacion tipo);
        DTPublicacion obtenerDatos(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo);
        void eliminarInmueble();
};

#endif