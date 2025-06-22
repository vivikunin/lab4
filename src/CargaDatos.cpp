#include "../include/CargaDatos.h"
#include <cstddef>
#include <iostream> 
#include "Factory.h"

CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    //TODO: Cargar los datos de prueba
    Factory* factory = Factory::getInstance();
    IUsuarios* cu = factory->getControladorUsuario();
    IInmobiliarias* ci = factory->getControladorInmobiliarias();
    IInmuebles* cm = factory->getControladorInmuebles();
    IControladorFechaActual* cf = factory->getControladorFechaActual();

    // 1) Crear clientes 
    cu->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Pérez", "46859342");
    cu->finalizarAltaUsuario();

    cu->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");
    cu->finalizarAltaUsuario();

    // 2) Crear Propietarios con sus inmuebles
        // Propietario: marcelom
        cu->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "N/A", "123456789012");
        cm->altaCasa("Av. Rivera", 1011, 120, 1995, true, Plano);
        cm->altaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);
        cu->finalizarAltaUsuario();
    
        // Propietario: robertarce
        cu->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "N/A", "987654321001");
        cm->altaCasa("Camino Maldonado", 1540, 95, 1988, false, Plano);
        cu->finalizarAltaUsuario();
    
        // Propietario: soledadf
        cu->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "N/A", "654321987654");
        cm->altaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);
        cu->finalizarAltaUsuario();
    
        // Propietario: martagal
        cu->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "N/A", "321098765432");
        cm->altaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);
        cu->finalizarAltaUsuario();
    
        // Propietario: jorge88
        cu->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "N/A", "890123456789");
        cm->altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
        cm->altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
        cm->altaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);
        cu->finalizarAltaUsuario();
   
    // 3) Crear inmobiliarias y asociarlas a propietarios
        // Casasur 
        cu->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
        cu->representarPropietario("marcelom");
        cu->representarPropietario("jorge88");
        cu->finalizarAltaUsuario();

        // Idealhome 
        cu->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy", "Av. Italia 4567", "https://idealhome.uy", "99123456");
        cu->representarPropietario("marcelom");
        cu->representarPropietario("martagal");
        cu->representarPropietario("jorge88");
        cu->finalizarAltaUsuario();

        // VivaUrbana
        cu->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
        cu->representarPropietario("soledadf");
        cu->representarPropietario("robertarce");
        cu->representarPropietario("jorge88");
        cu->finalizarAltaUsuario();

    // 4) Dar de alta administración de propiedad
        cf->setNewFechaActual(12, 12, 2015);
        ci->altaAdministraPropiedad("casasur123", 2);

        cf->setNewFechaActual(25, 9, 2023);
        ci->altaAdministraPropiedad("idealhome", 1);

        cf->setNewFechaActual(20, 7, 2022);
        ci->altaAdministraPropiedad("vivaurbana", 3);

        cf->setNewFechaActual(1, 1, 2022);
        ci->altaAdministraPropiedad("vivaurbana", 4);

        cf->setNewFechaActual(3, 7, 2010);
        ci->altaAdministraPropiedad("idealhome", 5);

        cf->setNewFechaActual(4, 11, 2019);
        ci->altaAdministraPropiedad("casasur123", 6);

        cf->setNewFechaActual(19, 5, 2020);
        ci->altaAdministraPropiedad("vivaurbana", 6);

        cf->setNewFechaActual(19, 7, 2024);
        ci->altaAdministraPropiedad("idealhome", 6);

        cf->setNewFechaActual(18, 9, 2023);
        ci->altaAdministraPropiedad("idealhome", 7);

        cf->setNewFechaActual(19, 5, 2022);
        ci->altaAdministraPropiedad("vivaurbana", 8);
 
    // 5) Generar publicaciones
        //esta falla
        cf->setNewFechaActual(9, 10, 2011);
        ci->altaPublicacion("idealhome", 5, Venta, "Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000);

        cf->setNewFechaActual(15, 1, 2016);
        ci->altaPublicacion("casasur123", 2, Alquiler, "Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000);

        cf->setNewFechaActual(5, 3, 2019);
        ci->altaPublicacion("casasur123", 2, Alquiler, "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500);
        
        cf->setNewFechaActual(3, 4, 2019);
        ci->altaPublicacion("idealhome", 5, Alquiler, "Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500);

        cf->setNewFechaActual(12, 12, 2019);
        ci->altaPublicacion("casasur123", 6, Venta, "Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 375000);

        cf->setNewFechaActual(12, 6, 2020);
        ci->altaPublicacion("casasur123", 2, Venta, "Excelente apartamento en Av. Brasil 75 m ideal para reforma.", 390000);
  
        cf->setNewFechaActual(20, 7, 2020);
        ci->altaPublicacion("vivaurbana", 6, Alquiler, "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000);

        cf->setNewFechaActual(4, 3, 2022);
        ci->altaPublicacion("vivaurbana", 4, Alquiler, "Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.", 26000);

        cf->setNewFechaActual(12, 9, 2022);
        ci->altaPublicacion("vivaurbana", 3, Venta, "Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000);
        
        cf->setNewFechaActual(1, 10, 2023);
        ci->altaPublicacion("idealhome", 1, Venta, "Casa en Av. Rivera de 120 m con techo ideal para familia.", 520000);
    
        cf->setNewFechaActual(18, 10, 2023);
        ci->altaPublicacion("idealhome", 7, Alquiler, "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000);

        cf->setNewFechaActual(19, 10, 2023);
        ci->altaPublicacion("idealhome", 7, Venta, "Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000);
               
        cf->setNewFechaActual(20, 11, 2023);
        ci->altaPublicacion("idealhome", 7, Alquiler, "Apartamento con gran vista a la rambla", 31000);
               
        cf->setNewFechaActual(20, 11, 2023);
        ci->altaPublicacion("idealhome", 7, Venta, "Apartamento en excelentes condiciones de 80 m", 450000);      

        cf->setNewFechaActual(8, 3, 2024);
        ci->altaPublicacion("vivaurbana", 3, Venta, "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000);
 
        cf->setNewFechaActual(5, 5, 2024);
        ci->altaPublicacion("idealhome", 7, Alquiler, "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000);
  
        cf->setNewFechaActual(1, 8, 2024);
        ci->altaPublicacion("idealhome", 6, Venta, "A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000);
    
    // 6) Suscripciones de clientes a inmobiliarias
        // luisito23
        cu->recordarUsuario("luisito23");
        ci->suscribirseAInmobiliaria("casasur123");
        ci->suscribirseAInmobiliaria("idealhome");
        cu->olvidarUsuarioRecordado();

        // anarojo88
        cu->recordarUsuario("anarojo88");
        ci->suscribirseAInmobiliaria("casasur123");
        ci->suscribirseAInmobiliaria("idealhome");
        ci->suscribirseAInmobiliaria("vivaurbana");
        cu->olvidarUsuarioRecordado();

        // marcelom 
        cu->recordarUsuario("marcelom");
        ci->suscribirseAInmobiliaria("idealhome");
        cu->olvidarUsuarioRecordado();

        // robertarce 
        cu->recordarUsuario("robertarce");
        ci->suscribirseAInmobiliaria("idealhome");
        cu->olvidarUsuarioRecordado();

        // soledadf
        cu->recordarUsuario("soledadf");
        ci->suscribirseAInmobiliaria("vivaurbana");
        cu->olvidarUsuarioRecordado();

        // martagal 
        cu->recordarUsuario("martagal");
        ci->suscribirseAInmobiliaria("vivaurbana");
        cu->olvidarUsuarioRecordado();

        // jorge88 
        cu->recordarUsuario("jorge88");
        ci->suscribirseAInmobiliaria("casasur123");
        ci->suscribirseAInmobiliaria("idealhome");
        ci->suscribirseAInmobiliaria("vivaurbana");
        cu->olvidarUsuarioRecordado();

        //Avanzar a fecha actual
        cf->setNewFechaActual(16, 6, 2023);
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}

CargaDatos::~CargaDatos() {}

void CargaDatos::destroyInstance() {
    delete instance;
    instance = NULL;
}
