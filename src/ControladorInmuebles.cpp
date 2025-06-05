#include "../include/ControladorInmuebles.h"

ControladorInmuebles* ControladorInmuebles::instance = NULL;

ControladorInmuebles* ControladorInmuebles::getInstance(){
    if (instance==NULL) {
        instance = new ControladorInmuebles();
    }
    return instance;
}
