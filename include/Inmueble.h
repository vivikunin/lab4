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
class Propietario;

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
        static int ultimoCodigoInmueble;
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        virtual ~Inmueble();

        void setDuenio(Propietario* duenio);
        void setAdministracion(AdministraPropiedad* admin);

        int getCodigo() const;
        std::string getDireccion() const;
        int getNumeroPuerta() const;
        int getSuperficie() const;
        int getAnoConstruccion() const;
        virtual DTInmueble getDTInmueble()=0;
        DTInmuebleListado getDTInmuebleListado();
        Propietario* getDueño();
        AdministraPropiedad* getAdministracion() const;

        bool esAdminitrado(Inmobiliaria* i);

        bool esDelTipoInmueble(TipoInmueble tipoInmueble);
        TipoInmueble tipoDelInmueble();
        std::set<DTPublicacion> obtenerDatosPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo,float precioMaximo);
        void eliminarInmueble();
        void eliminarReferenciaAdministracion();   
        bool tienePublicacion(int codigoPublicacion);
    
};

#endif