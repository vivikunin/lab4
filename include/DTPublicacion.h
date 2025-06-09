#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include "DTFecha.h"
#include <string>

class DTPublicacion {
    private:
        int codigo;
        DTFecha* fecha;
        std::string texto;
        float precio;
        std::string inmobiliaria;

    public:
        DTPublicacion(int codigo, DTFecha* fecha, std::string texto, float precio, std::string inmobiliaria);
        int getCodigo() const;
        DTFecha* getFecha() const;
        std::string getTexto() const;
        float getPrecio() const;
        std::string getInmobiliaria() const;
        ~DTPublicacion();
};

#endif