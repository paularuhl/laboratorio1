#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define LOW 2
#define HIGH 3

int main()
{
    //eGen genStruct;
    //char* fileName=(char*)malloc(sizeof(char)*50);
    ArrayList* atendidosUrg=al_newArrayList();
    ArrayList* atendidosReg=al_newArrayList();
    ArrayList* tramitesRegulares=al_newArrayList();
    ArrayList* tramitesUrgentes=al_newArrayList();
    int turnoU=1;
    int turnoR=1;
    int opcion;
    char salir='n';

    do
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
            turnoU=nuevoTramite(tramitesUrgentes,turnoU,HIGH);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            turnoR=nuevoTramite(tramitesRegulares,turnoR,LOW);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            proximoCliente(tramitesUrgentes, tramitesRegulares, atendidosUrg, atendidosReg);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            listarPendientes(tramitesUrgentes,tramitesRegulares);
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
