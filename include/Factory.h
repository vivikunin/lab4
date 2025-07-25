#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IUsuarios.h"
#include "IInmuebles.h"
#include "IInmobiliarias.h"

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        static void destroyInstance();
        IControladorFechaActual* getControladorFechaActual();
        //TODO: Get interfaces de controladores
        IUsuarios* getControladorUsuario();
        IInmuebles* getControladorInmuebles();
        IInmobiliarias* getControladorInmobiliarias();
        ~Factory();
};

#endif