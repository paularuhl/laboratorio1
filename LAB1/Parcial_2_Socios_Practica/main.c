#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
int main()
{
    ArrayList* socios=al_newArrayList();

    int opcion;
    char salir='n';
    int id = main_cargarAnteriores(socios);
    do
    {
        opcion = generic_menu();
        switch(opcion)
        {
        case 1:
            id++;
            main_alta(socios,&id);
            break;
        case 2:
            main_baja(socios);
            generic_finFuncion();
            break;
        case 3:
            main_modificar(socios);
            break;
        case 4:
            main_mostrarLista(socios);
            generic_finFuncion();
            break;
        case 5:
            generic_finFuncion();
            break;
        /*case 6:
            generic_finFuncion();
            break;
        case 7:
            generic_finFuncion();
            break;
        case 8:
            generic_finFuncion();
            break;
        case 9:
            generic_finFuncion();
            break;
            */
        case 0:
            printf("Adios!\n");
            system("pause");
            salir = 's';
            break;
        default:
            printf("\nOpcion invalida. Intente otra vez.");
            system("pause");
            system("cls");
            break;
        }
    }
    while(salir=='n');
    return 0;
}
