#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "parser.h"
#include "ArrayList.h"

int main()
{
    ArrayList* database=al_newArrayList();
    ArrayList* filtroSinAE=al_newArrayList();

    int opcion, salir=0;
    int id=0;

    do
    {
        opcion = vista_menu();
        switch(opcion)
        {
        case 1:
            main_parseIn(&id,database);
            break;
        case 2:
            filtroSinAE = al_filter(database,funcionQueFiltra);
            parseOut(filtroSinAE,"filtrado.csv");
            generic_finFuncion();
            break;
        case 3:
            main_mostrarLista(filtroSinAE);

//            main_depurar(destinatarios,listaNegra,depurados);
            break;
        case 4:
//            dest_mostrarLista(depurados);
            break;
        /*  case 5:
                generic_finFuncion();
                break;
            case 6:
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
            salir = 1;
            break;
        default:
            printf("\nOpcion invalida. Intente otra vez.");
            system("pause");
            system("cls");
            break;
        }
    }
    while(salir==0);
    return 0;
}
