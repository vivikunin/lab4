#ifndef CONTROLADORINMUEBLES_H
#define CONTROLADORINMUEBLES_H
#include "IInmuebles.h"
#include "DTPublicacion.h"
#include "TipoInmueble.h"
#include "TipoTecho.h"
#include "DTInmueble.h"

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
        
        Inmueble* getInmueble(int codigoInmueble);

        void eliminarInmueble(int codigoInmueble);
        std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
        std::set<DTInmuebleListado> listarInmuebles();

        void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,bool esPH, TipoTecho techo);
        void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);

        DTInmueble* detalleInmueble(int codigoInmueble);
        DTInmueble* detalleInmueblePublicacion(int codigoPublicacion);

};
#endif