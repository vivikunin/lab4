#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include "DTInmueble.h"
#include "Notificacion.h"
#include "TipoInmueble.h"
#include "TipoPublicacion.h"
#include <string>

class DTNotificacion {
    private:
        std::string nicknameInmobiliaria;
        int codigo;
        std::string texto;
        TipoPublicacion tPublicacion;
        TipoInmueble tInmueble;

    public:
        DTNotificacion(std::string nicknameInmobiliaria, int codigo, std::string texto, TipoPublicacion tPublicacion, TipoInmueble tInmueble);   
        ~DTNotificacion();

        std::string getNicknameInmobiliaria() const;
        int getCodigo() const;
        std::string getTexto() const;
        TipoPublicacion getTipoPublicacion() const;
        TipoInmueble getTipoInmueble() const;
};

#endif