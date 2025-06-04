#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"
#include "DTApartamento.h"
#include <string>

class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        Apartamento(int piso, bool tieneAscensor, float gastosComunes);
        Apartamento(int codigo, std::string direccion, std::string numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);
        ~Apartamento();

        DTApartamento getDTApartamento() const;
};

#endif