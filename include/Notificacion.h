#ifndef NOTIFICACION_H
#define NOTIFICACION_H
#include "TipoInmueble.h"
#include "TipoPublicacion.h"

#include <set>
#include <string>

class Notificacion {
    private:
        std::string nicknameInmobiliaria;
        int codigo;
        std::string texto;
        TipoPublicacion tPublicacion;
        TipoInmueble tInmueble;

    public:
        Notificacion(std::string nicknameInmobiliari, int codigo, std::string texto, TipoPublicacion tPublicacion, TipoInmueble tInmueble);   
        ~Notificacion();

        std::string getNicknameInmobiliaria() const;
        int getCodigo() const;
        std::string getTexto() const;
        TipoPublicacion getTipoPublicacion() const;
        TipoInmueble getTipoInmueble() const;
};

#endif