#include "ControladorInmuebles.h"
#include "Inmueble.h" 
#include "Casa.h"        
#include "Apartamento.h"  
#include "Factory.h"  

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
            std::set<DTPublicacion> publicacionesParaAgregar = it->second->obtenerDatosPublicaciones(tipoPublicacion,precioMinimo,precioMaximo, tipoInmueble);
            dtp.insert(publicacionesParaAgregar.begin(),publicacionesParaAgregar.end());
        }
    }
}

void ControladorInmuebles::eliminarInmueble(int codigoInmueble){
    Inmueble* in = coleccionInmuebles.find(codigoInmueble)->second;
    in->eliminarInmueble();
}

void ControladorInmuebles::altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,bool esPH, TipoTecho techo){
    Inmueble::ultimoCodigoInmueble++;
    Casa* c = new  Casa(Inmueble::ultimoCodigoInmueble, direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    this->coleccionInmuebles.insert({Inmueble::ultimoCodigoInmueble, c});
    Propietario* p = Factory::getInstance()->getControladorUsuario()->getPropietarioRecordado();///////////PROBLEMAAAAAAAAAA////////////
    c->setDuenio(p);
}

void ControladorInmuebles:: altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes){
    Inmueble::ultimoCodigoInmueble++;
    class Apartamento* a = new  class Apartamento(Inmueble::ultimoCodigoInmueble, direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    this->coleccionInmuebles.insert({Inmueble::ultimoCodigoInmueble, a});
    Propietario* p = Factory::getInstance()->getControladorUsuario()->getPropietarioRecordado();//////ANALOGO A ARRIBA////////////
    a->setDuenio(p);
}

DTInmueble ControladorInmuebles:: detalleInmueble(int codigoInmueble){
    return coleccionInmuebles.find(codigoInmueble)->second->getDTInmueble();
}

DTInmueble ControladorInmuebles::detalleInmueblePublicacion(int codigoPublicacion){
    bool ok=false;
    std::map<int, Inmueble*>::iterator it = coleccionInmuebles.begin();
    while(ok==false && it!=coleccionInmuebles.end()){
        ok=it->second->tienePublicacion(codigoPublicacion);
        it++;
    }
    return it->second->getDTInmueble();
}

std::set<DTInmuebleListado> ControladorInmuebles::listarInmuebles(){
    set<DTInmuebleListado> res;
    for(std::map<int, Inmueble*>::iterator it = coleccionInmuebles.begin(); it!=coleccionInmuebles.end(); it++){
        res.insert(it->second->getDTInmuebleListado());
    }
}


