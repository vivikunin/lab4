#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "TipoInmueble.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "AdministraPropiedad.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        AdministraPropiedad* administracion;
    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        virtual ~Inmueble();

        bool esDelTipoInmueble(TipoInmueble tipoInmueble);
        DTPublicacion obtenerDatos(TipoPublicacion tipoPublicacion, float precioMinimo,float precioMaximo);
        void eliminarInmueble();

        int getCodigo() const;
        std::string getDireccion() const;
        int getNumeroPuerta() const;
        int getSuperficie() const;
        int getAnoConstruccion() const;
    
        void setAdministracion(AdministraPropiedad* admin);
        AdministraPropiedad* getAdministracion() const;
};

#endif