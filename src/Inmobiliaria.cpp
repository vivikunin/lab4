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

void Inmobiliaria::eliminarReferenciaAdministracion(AdministraPropiedad* ap) {
    propiedadesAdministradas.erase(ap);
}