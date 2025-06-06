#include "../include/ControladorInmuebles.h"
#include "../include/Inmueble.h" 

ControladorInmuebles* ControladorInmuebles::instance = NULL;

ControladorInmuebles* ControladorInmuebles::getInstance(){
    if (instance==NULL) {
        instance = new ControladorInmuebles();
    }
    return instance;
}

std::set<DTPublicacion> ControladorInmuebles::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
    std::set<DTPublicacion> dtp;
    for(std::map<int,Inmueble*>::iterator it=coleccionInmuebles.begin(); it!=coleccionInmuebles.end(); it++){
        if (it->second->esDelTipoInmueble(tipoInmueble)){
            std::set<DTPublicacion*> publicacionesParaAgregar = it->second->obtenerDatosPublicaciones(tipoPublicacion,precioMinimo,precioMaximo);
            dtp.insert(publicacionesParaAgregar.begin(),publicacionesParaAgregar.end());
        }
    }
}
