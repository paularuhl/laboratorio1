#include <stdio.h>
#include <stdlib.h>
#include "control.h"
#include "lib.h"

///private functions

void control_init()
{
    ArrayList* numeros=al_newArrayList();
    int opcion, salir=0;
    do
    {
        vista_menuPrincipal();
        switch(opcion=entero_get("opcion"))
        {
        case 1:
            number_parseIn(numeros,"datos.csv");
            break;
        case 2:
            numeros_evaluate(numeros);
            number_parseOut(numeros,"resultados.csv");
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

///private functions
