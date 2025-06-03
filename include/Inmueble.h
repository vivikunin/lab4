#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "TipoInmueble.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "AdministraPropiedad.h"
#include "Propietario.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        AdministraPropiedad* administracion;
        Propietario* dueño;
    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, Propietario* dueño);
        virtual ~Inmueble();

        bool esDelTipoInmueble(TipoInmueble tipoInmueble);
        DTPublicacion obtenerDatos(TipoPublicacion tipoPublicacion, float precioMinimo,float precioMaximo);
        void eliminarInmueble();

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