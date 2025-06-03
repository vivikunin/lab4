#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"
#include "DTApartamento.h"


class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        Apartamento(int piso, bool tieneAscensor, float gastosComunes);
        ~Apartamento();

        DTApartamento getDTApartamento() const;
};

#endif