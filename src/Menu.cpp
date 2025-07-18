#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/DTNotificacion.h"

#include <string>
#include <set>
#include <list>
#include <cstdlib>
#include <stdexcept>

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Eliminar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            liberarMemoria();
            exit(0);
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario(){

    Factory* factory = Factory::getInstance();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        //TODO: usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);//////////////////
        usuarioOk = factory->getControladorUsuario()->altaCliente(nickname, contrasena, nombre, email, apellido, documento);

    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        //TODO: usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);/////////////////////
        usuarioOk = factory->getControladorUsuario()->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, apellido, documento);

    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        //TODO: usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);///////////////////
        usuarioOk = factory->getControladorUsuario()->altaPropietario(nickname, contrasena, nombre, email, apellido, documento);
    }
    if (usuarioOk){
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0){
                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    //TODO: Coleccion de DTUsuario = controlador->listarPropietarios();////////////////
                    std::set<DTUsuario> coleccionDTUsuario = factory->getControladorUsuario()->listarPropietarios();
                    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
                    for(std::set<DTUsuario>::iterator it = coleccionDTUsuario.begin(); it!=coleccionDTUsuario.end(); it++){
                        std::cout << "- Nickname: " <<  it->getNickname()
                        << ", Nombre: "   << it->getNombre() << "\n";
                    }
                    std::cout << "Nickname propietario a representar: ";
                    std::string nicknamePropietario;
                    std::getline(std::cin, nicknamePropietario);
                    //TODO: controlador->representarPropietario(nicknamePropietario)/////////////////////
                    factory->getControladorUsuario()->representarPropietario(nicknamePropietario);

                }else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        //TODO: controlador->altaCasa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                        factory->getControladorInmuebles()->altaCasa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        //TODO: controlador->altaApartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes)
                        factory->getControladorInmuebles()->altaApartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
                    }
                }
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }
        }
        //TODO: controlador->finalizarAltaUsuario();////////////////////////////////////
        factory->getControladorUsuario()->finalizarAltaUsuario();
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
    }
}

void altaPublicacion(){

    Factory* factory = Factory::getInstance();

    std::cout << "Lista de Inmobiliarias:\n";
    //TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();///////////////////////////////
    std::set<DTUsuario> coleccionDTUsuario = factory->getControladorInmobiliarias()->listarInmobiliarias();
    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    for(std::set<DTUsuario>::iterator it = coleccionDTUsuario.begin(); it!=coleccionDTUsuario.end(); it++){
        std::cout << "- Nickname: " <<  it->getNickname()
        << ", Nombre: "   << it->getNombre() << "\n";
    }
    bool nicknameValido = false;
    while (!nicknameValido) {
        std::cout << "Nickname de la inmobiliaria: ";
        std::string nicknameInmobiliaria;
        std::getline(std::cin, nicknameInmobiliaria);
        //TODO: Coleccion de DTInmuebleAdministrado = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);///////////////////
        try {
            std::set<DTInmuebleAdministrado> inmueblesAdministrados = factory->getControladorInmobiliarias()->listarInmueblesAdministrados(nicknameInmobiliaria);
            nicknameValido = true;
            //Recorrer la coleccion Mostrar "- Codigo: xx, Direccion: yy, Fecha comienzo: zzz"
            for( std::set<DTInmuebleAdministrado>::iterator it = inmueblesAdministrados.begin(); it!= inmueblesAdministrados.end(); it++){
                std::cout << " Codigo: " << it->getCodigo();
                std::cout << " Direccion: " << it->getDireccion();
                std::cout << " Fecha comienzo: " << (*it).getFechaComienzo().toString()<< "\n";
            }
            int codigoInmueble;
            std::cout << "Inmueble: ";
            std::cin >> codigoInmueble;
            std::cin.ignore();
            int inTipoPublicacion;
            std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
            std::cin >> inTipoPublicacion;
            TipoPublicacion tipoPublicacion = Alquiler;
            if(inTipoPublicacion == 1){
                tipoPublicacion = Venta;
            }
            std::cin.ignore();
            std::cout << "Texto: ";
            std::string texto;
            std::getline(std::cin, texto);
            std::cout << "Precio: ";
            float precio;
            std::cin >> precio; 
            std::cin.ignore();
            //TODO:Controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio)////////////////////////////////
            factory->getControladorInmobiliarias()->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << "\nPor favor ingrese un nickname válido.\n";
        }   
    }
}

void consultaPublicaciones(){

    Factory* factory = Factory::getInstance();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();
    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();
    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    std::cin >> inTipoInmueble;
    std::cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if(tipoInmueble == 1){
        tipoInmueble = TICasa;
    }else if(inTipoPublicacion == 2){
        tipoInmueble = TIApartamento;
    }
    std::cout << "Publicaciones encontradas:\n";
    //TODO: Coleccion de DTPublicacion = Controlador->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble); ///////////////////////////
    std::set <DTPublicacion> coleccionDatosPublicaciones = factory->getControladorInmuebles()->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
    //Recorrer la coleccion Mostrar "- Codigo: xx, fecha: dd/mm/yyyy, texto: zzz, precio: aaa, inmobiliaria: bbb"; //////////////////////////////////////  
    for( std::set<DTPublicacion>::iterator it = coleccionDatosPublicaciones.begin(); it!= coleccionDatosPublicaciones.end(); it++){
        std::cout << " Codigo: " << it->getCodigo()<<"\n";
        std::cout << " fecha: " << it->getFecha().toString()<<"\n";
        std::cout << " texto: " << it->getTexto()<<"\n";
        std::cout << " precio: " << it->getPrecio()<<"\n";
        std::cout << " inmobiliaria: " << it->getInmobiliaria()<<"\n";
    }
    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    std::cin >> verDetalle;
    std::cin.ignore();
    if (verDetalle == 1){
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();
        std::cout << "Detalle del inmueble:\n";
        //TODO: DTInmueble = Controlador->detalleInmueblePublicacion(codigoPublicacion): DTInmueble /////////////////////////////
        DTInmueble* dti = factory->getControladorInmuebles()->detalleInmueblePublicacion(codigoPublicacion);
        //Mostrarlo:
        // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
        // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
        if (dti!=NULL) {
            dti->mostrarDatos();  
            delete dti;           
        }
    }
}

void eliminarInmueble(){

    Factory* factory = Factory::getInstance();
    std::cout << "Listado de inmuebles:\n";
    //TODO: Coleccion de DTInmuebleListado = Controlador->listarInmuebles(); //////////////////////////////////////
    std::set<DTInmuebleListado> dtil = factory->getControladorInmuebles()->listarInmuebles();
    //Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";  /////////////////////////////////
    for( std::set<DTInmuebleListado>::iterator it = dtil.begin(); it!= dtil.end(); it++){
        std::cout << "-Codigo: " << it->getCodigo();
        std::cout << " Direccion: " << it->getDireccion();
        std::cout << " Propietario: " << it->getPropietario()<<"\n";
    }
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    std::cout << "Detalle del inmueble:\n";
    //TODO: DTInmueble = Controlador->detalleInmueble(codigoInmueble) //////////////////////////////////////
    DTInmueble* dti = factory->getControladorInmuebles()->detalleInmueble(codigoInmueble);
    if (dti) {
        dti->mostrarDatos();  
        delete dti;           
    }
    //Mostrarlo:
    // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No)";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    if (deseaEliminar == 1){
        //TODO: Controlador->eliminarInmueble(codigoInmueble) //////////////////////////////////////
            factory->getControladorInmuebles()->eliminarInmueble(codigoInmueble);
    }

}

void suscribirseNotificaciones(){
    Factory* factory = Factory::getInstance();
    std::string nickname, nombreInmobiliaria;
    bool nicknameValido = false;
    while (!nicknameValido) {
        std::cout << "Ingrese su nickname: ";
        std::cin >> nickname;
        try {
            factory->getControladorUsuario()->recordarUsuario(nickname);
            nicknameValido = true; 
            //mostrar inmobiliarias que no esta suscrito
            std::set<string> inmobilairias = factory->getControladorInmobiliarias()->mostrarInmobiliariasNoSuscrito(nickname);
            std::cout << "Inmobiliarias a las que no está suscrito:\n";
            for(std::set<string>::iterator it = inmobilairias.begin(); it!=inmobilairias.end(); it++){
                std::cout <<  *it <<"\n";
            }
            int salir = 1;
            while (salir != 0){
                std::cout << "Ingrese nombre de la inmobiliaria a la que desea suscribirse: "; 
                std::cin >> nombreInmobiliaria;
                //agregar a la lista de suscriptores
                factory->getControladorInmobiliarias()->suscribirseAInmobiliaria(nombreInmobiliaria);
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }
            factory->getControladorUsuario()->olvidarUsuarioRecordado();
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << "\nPor favor, intente nuevamente.\n";
        }
    }
}

void consultaNotificaciones(){
    Factory* factory = Factory::getInstance();
    std::string nickname;
    std::cout << "Ingrese su nickname: ";
    std::cin >> nickname;
    //listar notificaciones
    std::list<DTNotificacion> listaNotificaciones = factory->getControladorUsuario()->consultarNotificaciones(nickname);
    //mostrar las notificaciones
    for(std::list<DTNotificacion>::iterator it =listaNotificaciones.begin(); it!=listaNotificaciones.end(); it++){
        std::cout << "Inmobiliaria: " << (*it).getNicknameInmobiliaria() << "\n";
        std::cout << "Código: " << (*it).getCodigo() << "\n";
        std::cout << "Texto: " << (*it).getTexto() << "\n";
        std::cout << "Tipo Publicación: " << ((*it).getTipoPublicacion() == Alquiler ? "Alquiler" : "Venta") << "\n";
        std::cout << "Tipo Inmueble: " << ((*it).getTipoInmueble()== TICasa ? "Casa" : "Apartamento") << "\n";
    }
}

void eliminarSuscripciones(){
    Factory* factory = Factory::getInstance();
    std::string nickname, nombreInmobiliaria;
    std::cout << "Ingrese su nickname: ";
    std::cin >> nickname;
    factory->getControladorUsuario()->recordarUsuario(nickname);
    //listar inmobiliarias que esta suscrito
    std::cout << "Inmobiliarias a las que está suscrito: "<< "\n";
    std::set<string> inmobilairias = factory->getControladorInmobiliarias()->mostrarInmobiliariasSuscrito(nickname);
    for(std::set<string>::iterator it = inmobilairias.begin(); it!=inmobilairias.end(); it++){
        std::cout << (*it) << "\n";
    }
    int salir = 1;
    while (salir != 0){
        std::cout << "Ingrese nombre de la inmobiliaria a la que desea eliminar su suscripcion: ";
        std::cin >> nombreInmobiliaria;
        // eliminar suscripcion
        factory->getControladorInmobiliarias()->desSuscribirseAInmobiliaria(nombreInmobiliaria);
        std::cout << "¿Quiere seguir eliminando suscripciones? (1: Si, 0: No): ";
        std::cin >> salir;
        std::cin.ignore();
    }
}

void altaAdministracionPropiedad(){
    Factory* factory = Factory::getInstance();

    std::cout << "Lista de Inmobiliarias:\n";
    //TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias(); //////////////////////////////////////////
    std::set<DTUsuario> coleccionDTUsuario = factory->getControladorInmobiliarias()->listarInmobiliarias();
    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    for(std::set<DTUsuario>::iterator it = coleccionDTUsuario.begin(); it!=coleccionDTUsuario.end(); it++){
        std::cout << "- Nickname: " <<  it->getNickname()
        << ", Nombre: "   << it->getNombre() << "\n";
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    //TODO: Coleccion de DTInmuebleListado = Controlador->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    //Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
    try {
        std::set<DTInmuebleListado> dtil = factory->getControladorInmobiliarias()->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
        for( std::set<DTInmuebleListado>::iterator it = dtil.begin(); it!= dtil.end(); it++){
            std::cout << " Codigo: " << it->getCodigo();
            std::cout << " Direccion: " << it->getDireccion();
            std::cout << " Propietario: " << it->getPropietario()<<"\n";
        }
        std::cout << "Codigo del inmueble a administrar: ";
        int codigoInmueble;
        std::cin >> codigoInmueble;
        std::cin.ignore();
        //TODO: Controlador->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
        factory->getControladorInmobiliarias()->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void cargarDatos(){
    CargaDatos::getInstance();
}

 void verFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    DTFecha* fechaActual = cfecha->getFechaActual();
    std::cout << "fecha actual: " << fechaActual;
    delete fechaActual;
 }

 void asignarFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    std::cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
 }

 void liberarMemoria(){
    Factory::destroyInstance();
    CargaDatos::destroyInstance();
 }