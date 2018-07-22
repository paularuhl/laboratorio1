#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "control.h"
#include "clientes.h"
#include "alquileres.h"
#include "ArrayList.h"
#include "vista.h"
#include "lib.h"
#include "dataManager.h"

void control_init()
{
    ArrayList* clientes=al_newArrayList();
    ArrayList* alquileres=al_newArrayList();

    int opcion, salir=0;
    int idCte=ctes_parseIn(clientes,"clientes.csv");
    int idAlq=alq_parseIn(alquileres,"alq.csv");

    do
    {
        vista_menuPrincipal();
        opcion=entero_get("opcion");

        switch(opcion)
        {
        case 1:
            clientes_alta(clientes,&idCte);
            parseOut(clientes,alquileres);
            break;
        case 2:
            clientes_modificar(clientes);
            parseOut(clientes,alquileres);
            break;
        case 3:
            clientes_baja(clientes,alquileres);
            break;
        case 4:
            alq_alta(alquileres,clientes,&idAlq);
            break;
        case 5:
            alq_baja(alquileres,clientes);
            break;
        case 6:
            informes(clientes,alquileres);
            break;
        case 0:
            printf("Adios!\n");
            system("pause");
            salir = 1;
            break;
        default:
            vista_opcionInvalida();
            break;
        }
    }
    while(salir==0);
}
