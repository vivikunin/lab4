#ifndef CASA_H
#define CASA_H
#include "Inmueble.h"
#include "TipoTecho.h"
#include "DTCasa.h"

class Casa : public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        Casa(bool esPH, TipoTecho techo);
        Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo);
        ~Casa();

        DTInmueble getDTInmueble();
};

#endif