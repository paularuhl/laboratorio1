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
    ///los turnos a llamar no pueden ser sorted, porque se rompe todo. hay que, ent odo caso, clonar y ordenar.
    int turnoU=1;
    int turnoR=1;
    int opcion;
    char salir='n';

    do
    {
        opcion = generic_menuPrincipal();
        switch(opcion)
        {
        case 1:
            ///turno urgente
            turnoU=main_nuevoTramite(tramitesUrgentes,turnoU,HIGH);
            turnoU++;
            generic_finFuncion();
            break;
        case 2:
            ///turno regular
            turnoR=main_nuevoTramite(tramitesRegulares,turnoR,LOW);
            turnoR++;
            generic_finFuncion();
            break;
        case 3:
            ///proximo turno
            main_proximoCliente(tramitesUrgentes, tramitesRegulares, atendidosUrg, atendidosReg);
            generic_finFuncion();
            break;
        case 4:
            ///lista pendientes de atender
            main_listarPendientes(tramitesUrgentes,tramitesRegulares);
            generic_finFuncion();
            break;
        case 5:
            ///informar clientes ya atendidos en orden descendente
            main_informes(atendidosUrg,atendidosReg);
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
            generic_finFuncion();
            break;
        }
    }
    while(salir=='n');
    return 0;
}
