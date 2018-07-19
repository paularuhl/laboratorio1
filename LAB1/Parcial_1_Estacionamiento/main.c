#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include "propietario.h"
#include "autos.h"

#define QTY_EG 100
#define qty_PROP 20
#define qty_AUTOS 20
#define VACIO -1
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4
int main()
{
    EPropietario prop[qty_PROP];
    initPropietarios(prop,qty_PROP,VACIO);
    propietariosHC(prop);

    EAuto autos[qty_AUTOS];
    initAutos(autos,qty_AUTOS,VACIO);
    autosHC(autos);

    egresosEst autosOut[QTY_EG];
    initEgresos(autosOut,QTY_EG,VACIO);
    egresosHC(autosOut);

    char seguir=1;
    int opcion=0;


    do
    {
        menuPrincipal();

        opcion = ingresoStringNumerico("opcion");

        while(isNull(opcion))
        {
            printf("**Error: no se detecto ningun dato. Intente nuevamente\n");
            opcion = ingresoStringNumerico("opcion");
        }


        switch(opcion)
        {
        case 1: ///Registrar Propietario
            altaProp(prop,qty_PROP);
            printf("\n");
            system("pause");
            break;
        case 2: ///Modificar tarjeta de propietario
            modificarProp(prop,qty_PROP);
            printf("\n");
            system("pause");
            break;
        case 3: ///Baja de propietario y sus autos
            bajaProp(prop,qty_PROP,autos,qty_AUTOS,autosOut,QTY_EG);
            break;
        case 4: ///Ingreso de autos
            ingresoAuto(autos,qty_AUTOS,prop,qty_PROP);
            printf("\n");
            system("pause");
            break;
        case 5: ///Egreso de autos
            egresoAuto(autos,qty_AUTOS,prop,qty_PROP,autosOut,QTY_EG);
            break;
        case 6: ///Mostrar recaudacion total del estacionamiento
            recaudacionTotal(autosOut,QTY_EG);
            system("pause");
            break;
        case 7: ///Mostrar recaudacion total por marca
            recaudacionPorMarca(autosOut,QTY_EG);
            break;
        case 8: ///Mostrar propietario y sus autos
            //mostrarPropietarioConAutos(prop,qty_PROP,autos,qty_AUTOS);
            mostrarTodoProp(prop,qty_PROP);
            printf("\n");
            system("pause");
            break;
        case 9: ///Mostrar propietarios de Audi
            mostrarPropAudi(prop,qty_PROP,autos,qty_AUTOS);
            printf("\n");
            system("pause");
            break;
        case 10: ///Ordenar por patente y mostrar
            mostrarPorPatente(prop,autos,qty_AUTOS,qty_PROP);
            printf("\n");
            system("pause");
            break;
        case 11: ///Ordenar por nombre ascendente o descendente y mostrar
            ordenarPropietarios(prop,qty_PROP);
            break;
        case 12: ///Edad y listado
            mostrarSuperanEdad(prop,qty_PROP);
            printf("\n");
            system("pause");
            break;
        case 0: /// salir
            seguir = 0;
            break;
        default:
            printf("Opcion invalida, intente de nuevo.\n");
            break;
        }
        printf("\n");
        system("cls");
    }
    while(seguir!=0);
    return 0;
}


