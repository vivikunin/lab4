#ifndef DTINMUEBLELISTADO_H
#define DTINMUEBLELISTADO_H
#include <string>

class DTInmuebleListado {
    private:
        int codigo;
        std::string direccion;
        std::string propietario;

    public:
        DTInmuebleListado(int codigo, std::string direccion, std::string propietario);
        int getCodigo()const;
        std::string getDireccion()const;
        std::string getPropietario()const;
        bool operator<(DTInmuebleListado& other);   
};

#endif