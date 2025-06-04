#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include <string>

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* administrador;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    ~Publicacion();

    void setAdministrador(AdministraPropiedad* admin);
    DTPublicacion getDTPublicacion();

    void marcarComoInactiva();
    bool cumpleCondiciones(TipoPublicacion tipoPublicacion, float precioMinimo, float prcioMaximo, TipoInmueble tipoInmueble);
};

#endif