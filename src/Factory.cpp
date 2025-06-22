#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorUsuarios.h"
#include "../include/ControladorInmobiliarias.h"
#include "../include/ControladorInmuebles.h"

#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory::~Factory(){
    delete ControladorUsuarios::getInstance();
    delete ControladorInmuebles::getInstance();
    delete ControladorInmobiliarias::getInstance();
    delete ControladorFechaActual::getInstance();
}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

void Factory::destroyInstance() {
    delete instance;
    instance = NULL;
}


IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IUsuarios* Factory::getControladorUsuario(){
    return ControladorUsuarios::getInstance();
}

IInmobiliarias* Factory::getControladorInmobiliarias(){
    return ControladorInmobiliarias::getInstance();
}

IInmuebles* Factory::getControladorInmuebles(){
    return ControladorInmuebles::getInstance();
}