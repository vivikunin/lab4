#ifndef DTINMUEBLEADMINISTRADO_H
#define DTINMUEBLEADMINISTRADO_H
#include "DTFecha.h"
#include <string>

class DTInmuebleAdministrado {
    private:
        int codigo;
        std::string direccion;
        DTFecha fechaComienzo;

    public:
        DTInmuebleAdministrado(int codigo, std::string direccion, const DTFecha& fechaComienzo);
        int getCodigo() const;
        std::string getDireccion() const;
        DTFecha getFechaComienzo() const;
        ~DTInmuebleAdministrado();
        friend bool operator<(const DTInmuebleAdministrado&, const DTInmuebleAdministrado&);
};

#endif