#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "TipoInmueble.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "AdministraPropiedad.h"
#include "Propietario.h"
#include "DTInmueble.h"

class AdministraPropiedad;

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        AdministraPropiedad* administracion;
        Propietario* duenio;
    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        virtual ~Inmueble();

        bool esDelTipoInmueble(TipoInmueble tipoInmueble);
        std::set<DTPublicacion*> obtenerDatosPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo,float precioMaximo);
        void eliminarInmueble();

        void setDuenio( Propietario* duenio);

        int getCodigo() const;
        std::string getDireccion() const;
        int getNumeroPuerta() const;
        int getSuperficie() const;
        int getAnoConstruccion() const;
        DTInmueble getDTInmueble();
        Propietario* getDueño();
    
        void setAdministracion(AdministraPropiedad* admin);
        AdministraPropiedad* getAdministracion() const;
};

#endif