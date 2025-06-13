#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "AdministraPropiedad.h"

#include <string>

class AdministraPropiedad;

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
    static int ultimoCodigo;
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    ~Publicacion();

    TipoPublicacion getTipoPublicacion();
    DTFecha* getFecha();
    bool estaActiva();
    int getCodigo();
    float getPrecio();

    void setAdministrador(AdministraPropiedad* admin);
    DTPublicacion getDTPublicacion();

    void marcarComoInactiva();
    bool cumpleCondiciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo);
};

#endif