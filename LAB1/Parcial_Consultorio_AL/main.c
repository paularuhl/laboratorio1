#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
int main()
{
    //eGen genStruct;
    //char* fileName=(char*)malloc(sizeof(char)*50);
    ArrayList* turnosTotales=al_newArrayList();
    ArrayList* turnosAtendidos=al_newArrayList();
    ArrayList* turnosPendientes=al_newArrayList();
    int turno = 0;
    int* pTurno = &turno;


    int opcion;
    char salir='n';

    do
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
            tramiteUrgente(turnosTotales,pTurno);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 5:
            printf("\n");
            system("pause");
            system("cls");
            break;
        /*case 6:
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 7:
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 8:
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 9:
            printf("\n");
            system("pause");
            system("cls");
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
