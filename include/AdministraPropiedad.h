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

class Publicacion;
class Inmobiliaria;
class Inmueble;

class AdministraPropiedad{
    private:
        DTFecha fecha;
        std::map<int,Publicacion*> coleccionPublicaciones;
        Inmueble* inmuebleAdministrado;
        Inmobiliaria* inmobiliariaAdministradora;
    public:
        //constructor y destructor
        AdministraPropiedad(DTFecha fecha);
        AdministraPropiedad(DTFecha fecha,Inmueble* inmuebleAdministrado ,Inmobiliaria* inmobiliariaAdministradora);
        ~AdministraPropiedad();

        //getters
        DTFecha& getFecha();
        Inmueble* getInmuebleAdministrado() const;
        Inmobiliaria* getInmobiliariaAdministradora() const;
 
        //setters
        void setInmuebleAdministrado(Inmueble* inmueble); 
        void setInmobiliariaAdministrada(Inmobiliaria* inmobiliaria);  

        DTInmuebleAdministrado obtenerDatosInmuebleAdministrado();
        bool puedoCrearPublicacion(TipoPublicacion tipo);
        std::set<DTPublicacion> obtenerDatosPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo);
        void eliminarInmueble();
        AdministraPropiedad* administraPropiedadParaInmueble(int codigoInmueble);
        void desactivarPublicacionActiva();
        void crearPublicacion(TipoPublicacion tipoPublicacion, std::string texto, float precio);
        bool tienePublicacion(int codigoPublicacion);
};
#endif