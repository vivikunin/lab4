#include "../include/ControladorInmuebles.h"
#include "Inmueble.h"

ControladorInmuebles* ControladorInmuebles::instance = NULL;

ControladorInmuebles* ControladorInmuebles::getInstance(){
    if (instance==NULL) {
        instance = new ControladorInmuebles();
    }
    return instance;
}

void ControladorInmuebles::eliminarInmueble(int codigoInmueble){
    Inmueble* in = coleccionInmuebles.find(codigoInmueble)->second;
    in->eliminarInmueble();
}
