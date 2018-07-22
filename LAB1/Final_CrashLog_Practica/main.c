#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    ArrayList* logEntry=al_newArrayList();
    ArrayList* service=al_newArrayList();

    int opcion, salir=0;

    do
    {
        vista_menuPrincipal();
        opcion=entero_get("opcion");
        switch(opcion)
        {
        case 1:
            leerLog(logEntry,service);
            break;
        case 2:
            procesarInformacion(logEntry,service);
            break;
        case 3:
            estadisticas(logEntry,service);
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
    return 0;
}
