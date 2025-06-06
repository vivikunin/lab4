#include "../include/Inmobiliaria.h"
#include "AdministraPropiedad.h"
#include <set>

std::set<DTInmuebleAdministrado> Inmobiliaria:: datosInmueblesAdministrados(){
    std::set<DTInmuebleAdministrado> datos;
    for(std::set<AdministraPropiedad*>::iterator it=propiedadesAdministradas.begin(); it!=propiedadesAdministradas.end(); it++ ){
        DTInmuebleAdministrado dtia = (*it)->obtenerDatosInmuebleAdministrado();
        datos.insert(dtia);
    }
    return datos;
}

bool Inmobiliaria::altaPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){
    AdministraPropiedad *ap =NULL;
    for(std::set<AdministraPropiedad*>::iterator it= propiedadesAdministradas.begin(); it!=propiedadesAdministradas.end(); it++){
        ap=(*it)->administraPropiedadParaInmueble(codigoInmueble);
    }
    bool puede = ap->puedoCrearPublicacion(tipoPublicacion);
    if (puede){
        ap->desactivarPublicacionActiva();
        ap->crearPublicacion();
    }
    return puede;
}