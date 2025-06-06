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
    std::set<AdministraPropiedad*>::iterator it= propiedadesAdministradas.begin();
    while ( ap==NULL && it!=propiedadesAdministradas.end()){
        ap=(*it)->administraPropiedadParaInmueble(codigoInmueble);
        it++;
    }
    bool puede = ap->puedoCrearPublicacion(tipoPublicacion);
    if (puede){
        ap->desactivarPublicacionActiva();
        ap->crearPublicacion(tipoPublicacion, texto, precio);
    }
    return puede;
}

void Inmobiliaria::eliminarReferenciaAdministracion(AdministraPropiedad* a) {
    propiedadesAdministradas.erase(a);
}