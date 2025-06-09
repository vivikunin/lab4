#ifndef CONTROLADORINMUEBLES_H
#define CONTROLADORINMUEBLES_H
#include "IInmuebles.h"
#include "DTPublicacion.h"
#include "TipoInmueble.h"
#include <set>
#include <map>
#include <string>

class Inmueble;

class ControladorInmuebles : public IInmuebles {
    private:
        static ControladorInmuebles* instance;
        ControladorInmuebles();
        std::map <int,Inmueble*> coleccionInmuebles;
    
    public:
        static ControladorInmuebles* getInstance();
        ~ControladorInmuebles();

        void eliminarInmueble(int codigoInmueble);
        std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);


};
#endif