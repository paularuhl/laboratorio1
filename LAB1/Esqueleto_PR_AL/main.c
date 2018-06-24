#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
int main()
{
    char* fileName=(char*)malloc(sizeof(char)*50);
    ArrayList* listaUno=al_newArrayList();
    ArrayList* listaDos=al_newArrayList();
    ArrayList* listaTres=al_newArrayList();

    int opcion;
    char salir='n';

    do
    {
        opcion = generic_menu();
        switch(opcion)
        {
        case 1:
            generic_finFuncion();
            break;
        case 2:
            generic_finFuncion();
            break;
        case 3:
            generic_finFuncion();
            break;
        case 4:
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
