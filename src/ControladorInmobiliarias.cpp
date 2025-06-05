#include "../include/ControladorInmobiliarias.h"

ControladorInmobiliarias* ControladorInmobiliarias::instance = NULL;


ControladorInmobiliarias* ControladorInmobiliarias::getInstance() {
    if (instance == NULL) {
        instance = new ControladorInmobiliarias();
    }
    return instance;
}