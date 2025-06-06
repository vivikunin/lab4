#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"

#include <set>

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion){
    this->codigo=codigo;
    this->direccion=direccion;
    this->numeroPuerta=numeroPuerta;
    this->superficie=superficie;
    this->anoConstruccion=anoConstruccion;
    this->administracion=NULL;
    this->duenio=NULL;
}

Inmueble:: ~Inmueble(){
    if (administracion != nullptr) {
        Inmobiliaria* i = administracion->getInmobiliariaAdministradora();
        if (i != nullptr){
            i->eliminarReferenciaAdministracion(administracion); 
        }  
        delete administracion;
    }
}


bool Inmueble::esDelTipoInmueble(TipoInmueble tipoInmueble){

}

std::set<DTPublicacion> Inmueble::obtenerDatosPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo,float precioMaximo, TipoInmueble tipoInmueble){
    return this->administracion->obtenerDatosPublicaciones(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
}
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