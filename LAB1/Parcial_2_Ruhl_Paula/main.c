#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "parser.h"

int main()
{
    ArrayList* empleados=al_newArrayList();
    ArrayList* programadores=al_newArrayList();

    int opcion;
    char salir='n';
    int id = main_parseIn(empleados,"empleados.csv");
    do
    {
        opcion = generic_menu();
        switch(opcion)
        {
        case 1:
            id++;
            main_alta(empleados,&id);
            break;
        case 2:
            programadores = al_filter(empleados,funcionQueFiltra);
            main_mostrarLista(programadores);
            main_parseOut(programadores,"prog.csv");

            generic_finFuncion();
            break;
        case 3:
            //main_modificar(empleados);
            break;
        case 4:
            main_mostrarLista(empleados);
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
