#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IUsuarios.h"
#include "IInmuebles.h"
#include "IInmobiliarias.h"

class Factory {
    private:
        static Factory* instance;
        IUsuarios* controladorUsuario;
        IInmuebles* controladorInmuebles;
        IInmobiliarias* controladorInmobiliarias;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        //TODO: Get interfaces de controladores
        IUsuarios* getControladorUsuario();
        IInmuebles* getControladorInmuebles();
        IInmobiliarias* getControladorInmobiliarias();
        ~Factory();
};

#endif